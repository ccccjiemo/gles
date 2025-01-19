import {
  glAttachShader,
  glCreateProgram,
  glDeleteProgram,
  glDetachShader,
  glGetProgramInfoLog,
  glGetProgramiv,
  glGetUniformLocation,
  glLinkProgram,
  glUniform1fv,
  glUniform1iv,
  glUniform2fv,
  glUniform2iv,
  glUniform3fv,
  glUniform3iv,
  glUniform4fv,
  glUniform4iv,
  glUseProgram
} from 'libgles.so';
import { GLObject } from './GLObject';
import { collections } from '@kit.ArkTS';
import { GLShader } from './GLShader';
import { ProgramParamName } from '../constant/ProgramParamName';
import { GL_TRUE } from '../constant/constants';
import { TupleUnionBySize } from '../glm/common';

@Sendable
class GLProgram implements GLObject {
  readonly handle: number;
  private _log: string;
  private _uniformCache: collections.Map<string, number>;

  constructor() {
    this.handle = glCreateProgram();
    this._uniformCache = new collections.Map();
    this._log = '';
  }

  attach(...args: GLShader[] | number[]): boolean {
    glAttachShader(this.handle, ...args.map((it: GLShader | number) => {
      if (typeof it === 'number') {
        return it;
      } else {
        return it.handle;
      }
    }));
    glLinkProgram(this.handle);
    if (GL_TRUE != glGetProgramiv(this.handle, ProgramParamName.GL_LINK_STATUS)) {
      this._log = glGetProgramInfoLog(this.handle);
      return false;
    }
    return true;
  }

  detach(...args: GLShader[] | number[]): void {
    for (let i = 0; i < args.length; i++) {
      let value = args[i];
      glDetachShader(this.handle, typeof value === 'number' ? value : value.handle);
    }
  }

  getUniformLocation(name: string): number {
    if (this._uniformCache.has(name)) {
      return this._uniformCache.get(name)!;
    }

    let uniform = glGetUniformLocation(this.handle, name);
    if (uniform < 0) {
      return uniform;
    }
    this._uniformCache.set(name, uniform);
    return uniform;
  }

  get attachedShader(): number {
    return glGetProgramiv(this.handle, ProgramParamName.GL_ATTACHED_SHADERS);
  }

  get activeAttributes(): number {
    return glGetProgramiv(this.handle, ProgramParamName.GL_ACTIVE_ATTRIBUTES);
  }

  get activeUniforms(): number {
    return glGetProgramiv(this.handle, ProgramParamName.GL_ACTIVE_UNIFORMS);
  }

  get activeAttributeMaxLength(): number {
    return glGetProgramiv(this.handle, ProgramParamName.GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
  }

  get activeUniformMaxLength(): number {
    return glGetProgramiv(this.handle, ProgramParamName.GL_ACTIVE_UNIFORM_MAX_LENGTH);
  }

  setUniformf(name: string, v: Float32Array): void
  setUniformf(name: string, ...args: TupleUnionBySize<4>): void
  setUniformf(name: string, ...args: number[] | Float32Array[]) {
    let location = this.getUniformLocation(name);
    let size = 0;
    let buffer: Float32Array;
    if (typeof args[0] === 'number') {
      size = Math.min(4, args.length);
      buffer = Float32Array.from(args as number[]);
    } else {
      size = Math.min(4, args[0].length);
      buffer = args[0];
    }

    switch (size) {
      case 1:
        glUniform1fv(location, buffer);
        break;
      case 2:
        glUniform2fv(location, buffer);
        break;
      case 3:
        glUniform3fv(location, buffer);
        break;
      case 4:
        glUniform4fv(location, buffer);
        break;
      default:
        throw Error('invalid argument');
    }

  }

  setUniformi(name: string, v: Uint32Array): void
  setUniformi(name: string, ...args: TupleUnionBySize<4>): void
  setUniformi(name: string, ...args: number[] | Uint32Array[]): void {
    let location = this.getUniformLocation(name);
    let size = 0;
    let buffer: Uint32Array;
    if (typeof args[0] === 'number') {
      size = Math.min(4, args.length);
      buffer = Uint32Array.from(args as number[]);
    } else {
      size = Math.min(4, args[0].length);
      buffer = args[0];
    }

    switch (size) {
      case 1:
        glUniform1iv(location, buffer);
        break;
      case 2:
        glUniform2iv(location, buffer);
        break;
      case 3:
        glUniform3iv(location, buffer);
        break;
      case 4:
        glUniform4iv(location, buffer);
        break;
      default:
        throw Error('invalid argument');
    }
  }

  bind(): void {
    glUseProgram(this.handle);
  }

  unbind(): void {
    glUseProgram(0);
  }

  delete(): void {
    glDeleteProgram(this.handle);
    this._uniformCache.clear();
  }
}

