import { glAttachShader, glGetProgramInfoLog } from 'libgles.so';
import { GL_INFO_LOG_LENGTH, GL_TRUE, ProgramParamName, ShaderType } from '../constant/Index';
import {
  glCreateProgram,
  glLinkProgram,
  glUseProgram,
  glGetProgramiv,
  glGetUniformLocation,
  glUniform1f,
  glDeleteProgram,
  glDetachShader
} from '../GLES'
import { Shader } from './Shader';
import { HashMap } from '@kit.ArkTS';
import { vec, vec2, vec3, vec4 } from '../glm/vec';

export class Program {
  private _programId: number;
  private _infoLog: string = '';
  private _uniformCache: HashMap<string, number>;

  constructor() {
    this._uniformCache = new HashMap();
    this._programId = glCreateProgram();
  }

  get id() {
    return this._programId;
  }

  get infoLog() {
    return this._infoLog;
  }

  get attachedShader(): number {
    return glGetProgramiv(this._programId, ProgramParamName.GL_ATTACHED_SHADERS);
  }

  get activeAttributes(): number {
    return glGetProgramiv(this._programId, ProgramParamName.GL_ACTIVE_ATTRIBUTES);
  }

  get activeUniforms(): number {
    return glGetProgramiv(this._programId, ProgramParamName.GL_ACTIVE_UNIFORMS);
  }

  get activeAttributeMaxLength(): number {
    return glGetProgramiv(this._programId, ProgramParamName.GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
  }

  get activeUniformMaxLength(): number {
    return glGetProgramiv(this._programId, ProgramParamName.GL_ACTIVE_UNIFORM_MAX_LENGTH);
  }

  bind() {
    glUseProgram(this._programId)
  }

  unbind() {
    glUseProgram(0);
  }

  attach(...args: Shader[]): boolean {
    this.bind();
    for (let i = 0; i < args.length; i++) {
      let shader = args[i];
      if (!shader.isCompiled) {
        if (!shader.compile()) {
          return false;
        }
      }
      glAttachShader(this._programId, shader.id);
    }
    glLinkProgram(this._programId);
    if (GL_TRUE == glGetProgramiv(this._programId, ProgramParamName.GL_LINK_STATUS)) {
      this._infoLog = '';
      return true;
    }


    this._infoLog = glGetProgramInfoLog(this._programId);
    return false;
  }

  detach(...args: Shader[]) {
    this.bind();

    for (let i = 0; i < args.length; i++) {
      glDetachShader(this._programId, args[i].id);
    }
  }


  setUniformf<T extends vec>(name: string, vec: T): void

  setUniformf(name: string, v0: number): void

  setUniformf(name: string, v0: number, v1: number): void

  setUniformf(name: string, v0: number, v1: number, v2: number): void

  setUniformf(name: string, v0: number, v1: number, v2: number, v3: number): void

  setUniformf<T extends vec>(name: string, value: T | number, v1?: number, v2?: number, v3?: number): void {
    let location = this.getUniformLocation(name);
    if (typeof value == 'number') {
      switch (arguments.length) {
        case 2:
          this.bind();

          glUniform1f(location, value);
          break;
        case 3:
          this.setUniformf(name, new vec2(value, v1!));
          break;
        case 4:
          this.setUniformf(name, new vec3(value, v1!, v2!));
          break;
        case 5:
          this.setUniformf(name, new vec4(value, v1!, v2!, v3!));
          break;
        default:
          throw Error('argument out of range');
      }
    } else {
      this.bind();

      value.setUniform(location);
    }


  }

  getUniformLocation(name: string): number {
    if (this._uniformCache.hasKey(name)) {
      return this._uniformCache.get(name);
    }
    this.bind();

    let uniform = glGetUniformLocation(this._programId, name);
    if (uniform == -1) {
      return -1;
    }
    this._uniformCache.set(name, uniform);
    return uniform;
  }

  delete(): boolean {
    glDeleteProgram(this._programId);
    return GL_TRUE == glGetProgramiv(this._programId, ProgramParamName.GL_DELETE_STATUS);
  }
}


// let program = new GLProgram();
// program.setUniformf("test", 1);
// program.setUniformf("test", 1, 2);
// program.setUniformf("test", 1, 2, 3);
// program.setUniformf("test", 1, 2, 4);
// program.setUniformf("test", new vec2(1));
// program.setUniformf("test", new vec3(1));
// program.setUniformf("test", new vec4(1));
// program.attach(GLShader.fromString(ShaderType.GL_VERTEX_SHADER, ""),
//   GLShader.fromString(ShaderType.GL_FRAGMENT_SHADER, ""))

