import {
  glAttachShader,
  glCreateProgram,
  glDeleteProgram,
  glDetachShader,
  glGetError,
  glGetProgramInfoLog,
  glGetProgramiv,
  glGetUniformLocation,
  glLinkProgram,
  glUniform1f,
  glUniform1i,
  glUseProgram
} from 'libgles.so';
import { GL_TRUE, ProgramParamName } from '../constant/Index';
import { Shader, Shader2 } from './Shader';
import { collections, HashMap } from '@kit.ArkTS';
import { ivec, ivec2, ivec3, ivec4, vec, vec2, vec3, vec4 } from '../glm/vec';

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
    for (let i = 0; i < args.length; i++) {
      let shader = args[i];
      if (!shader.isCompiled) {
        if (!shader.compile()) {
          return false;
        }
      }
    }
    glAttachShader(this._programId, ...args.map(it => it.id));
    glLinkProgram(this._programId);
    let status = glGetProgramiv(this._programId, ProgramParamName.GL_LINK_STATUS);
    this._infoLog = glGetProgramInfoLog(this._programId);
    return status == GL_TRUE;
  }

  detach(...args: Shader[]) {

    for (let i = 0; i < args.length; i++) {
      let err = glGetError();
      glDetachShader(this._programId, args[i].id);
      err = glGetError();
      args[i].delete();
      err = glGetError();
      console.log('1')
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

      value.setUniformf(location);
    }
  }

  setUniformi<T extends ivec>(name: string, ivec: T): void

  setUniformi(name: string, v0: number): void

  setUniformi(name: string, v0: number, v1: number): void

  setUniformi(name: string, v0: number, v1: number, v2: number): void

  setUniformi(name: string, v0: number, v1: number, v2: number, v3: number): void

  setUniformi<T extends ivec>(name: string, value: T | number, v1?: number, v2?: number, v3?: number): void {
    let location = this.getUniformLocation(name);
    if (typeof value == 'number') {
      switch (arguments.length) {
        case 2:
          this.bind();

          glUniform1i(location, value);
          break;
        case 3:
          this.setUniformi(name, new ivec2(value, v1!));
          break;
        case 4:
          this.setUniformi(name, new ivec3(value, v1!, v2!));
          break;
        case 5:
          this.setUniformi(name, new ivec4(value, v1!, v2!, v3!));
          break;
        default:
          throw Error('argument out of range');
      }
    } else {
      this.bind();

      value.setUniformi(location);
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

"use shared"

@Sendable
export class Program2 {
  private _programId: number;
  private _infoLog: string = '';
  private _uniformCache: collections.Map<string, number>;

  constructor() {
    this._uniformCache = new collections.Map();
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

  attach(...args: Shader2[]): boolean {
    for (let i = 0; i < args.length; i++) {
      let shader = args[i];
      if (!shader.isCompiled) {
        if (!shader.compile()) {
          return false;
        }
      }
    }
    glAttachShader(this._programId, ...args.map(it => it.id));
    glLinkProgram(this._programId);
    let status = glGetProgramiv(this._programId, ProgramParamName.GL_LINK_STATUS);
    this._infoLog = glGetProgramInfoLog(this._programId);
    return status == GL_TRUE;
  }

  detach(...args: Shader[]) {

    for (let i = 0; i < args.length; i++) {
      let err = glGetError();
      glDetachShader(this._programId, args[i].id);
      err = glGetError();
      args[i].delete();
      err = glGetError();
      console.log('1')
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

      value.setUniformf(location);
    }
  }

  setUniformi<T extends ivec>(name: string, ivec: T): void

  setUniformi(name: string, v0: number): void

  setUniformi(name: string, v0: number, v1: number): void

  setUniformi(name: string, v0: number, v1: number, v2: number): void

  setUniformi(name: string, v0: number, v1: number, v2: number, v3: number): void

  setUniformi<T extends ivec>(name: string, value: T | number, v1?: number, v2?: number, v3?: number): void {
    let location = this.getUniformLocation(name);
    if (typeof value == 'number') {
      switch (arguments.length) {
        case 2:
          this.bind();

          glUniform1i(location, value);
          break;
        case 3:
          this.setUniformi(name, new ivec2(value, v1!));
          break;
        case 4:
          this.setUniformi(name, new ivec3(value, v1!, v2!));
          break;
        case 5:
          this.setUniformi(name, new ivec4(value, v1!, v2!, v3!));
          break;
        default:
          throw Error('argument out of range');
      }
    } else {
      this.bind();

      value.setUniformi(location);
    }
  }

  getUniformLocation(name: string): number {
    if (this._uniformCache.has(name)) {
      return this._uniformCache.get(name)!;
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


