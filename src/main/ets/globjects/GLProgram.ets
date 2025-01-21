import { GLObject } from "./GLObject";
import { collections } from "@kit.ArkTS";
import gles from "libgles.so";
import { Shader } from "./GLShader";
import { glm } from "@jemoc/glm";
"use shared"

@Sendable
export class Program implements GLObject {
  readonly handle: number;
  private _log: string;
  private _uniformCache: collections.Map<string, number>;

  constructor() {
    this.handle = gles.glCreateProgram();
    this._uniformCache = new collections.Map();
    this._log = '';
  }

  get log(): string {
    return this._log;
  }

  attach(...args: Shader[] | number[]): boolean {
    collections.Array
    gles.glAttachShader(this.handle, ...args.map((it: Shader | number) => {
      if (typeof it === 'number') {
        return it;
      } else {
        return it.handle;
      }
    }));
    gles.glLinkProgram(this.handle);
    if (gles.GL_TRUE != gles.glGetProgramiv(this.handle, gles.GL_LINK_STATUS)) {
      this._log = gles.glGetProgramInfoLog(this.handle);
      return false;
    }
    return true;
  }

  detach(...args: Shader[] | number[]): void {
    for (let i = 0; i < args.length; i++) {
      let value = args[i];
      gles.glDetachShader(this.handle, typeof value === 'number' ? value : value.handle);
    }
  }

  getUniformLocation(name: string): number {
    if (this._uniformCache.has(name)) {
      return this._uniformCache.get(name)!;
    }

    let uniform = gles.glGetUniformLocation(this.handle, name);
    if (uniform < 0) {
      return uniform;
    }
    this._uniformCache.set(name, uniform);
    return uniform;
  }

  get attachedShader(): number {
    return gles.glGetProgramiv(this.handle, gles.GL_ATTACHED_SHADERS);
  }

  get activeAttributes(): number {
    return gles.glGetProgramiv(this.handle, gles.GL_ACTIVE_ATTRIBUTES);
  }

  get activeUniforms(): number {
    return gles.glGetProgramiv(this.handle, gles.GL_ACTIVE_UNIFORMS);
  }

  get activeAttributeMaxLength(): number {
    return gles.glGetProgramiv(this.handle, gles.ProgramParamName.GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
  }

  get activeUniformMaxLength(): number {
    return gles.glGetProgramiv(this.handle, gles.ProgramParamName.GL_ACTIVE_UNIFORM_MAX_LENGTH);
  }

  setUniformf(name: string, v: glm.vec<glm.float, glm.Range<4, 1>>)

  setUniformf(name: string, v: Float32Array): void

  setUniformf(name: string, ...args: glm.TupleUnionBySize<4>): void

  setUniformf(name: string, ...args: number[] | Float32Array[] | glm.vec<glm.float, glm.Range<4, 1>>[]) {
    let location = this.getUniformLocation(name);
    let size = 0;
    let buffer: Float32Array;
    if (typeof args[0] === 'number') {
      size = Math.min(4, args.length);
      buffer = Float32Array.from(args as number[]);
    } else if (args[0] instanceof Float32Array) {
      size = Math.min(4, args[0].length);
      buffer = args[0];
    } else {
      size = args[0].size;
      buffer = args[0].elements;
    }

    switch (size) {
      case 1:
        gles.glUniform1fv(location, buffer);
        break;
      case 2:
        gles.glUniform2fv(location, buffer);
        break;
      case 3:
        gles.glUniform3fv(location, buffer);
        break;
      case 4:
        gles.glUniform4fv(location, buffer);
        break;
      default:
        throw Error('invalid argument');
    }

  }

  setUniformi(name: string, v: glm.vec<glm.int, glm.Range<4, 1>>)

  setUniformi(name: string, v: glm.int): void

  setUniformi(name: string, ...args: glm.TupleUnionBySize<4>): void

  setUniformi(name: string, ...args: number[] | glm.int[] | glm.vec<glm.int, glm.Range<4, 1>>[]): void {
    let location = this.getUniformLocation(name);
    let size = 0;
    let buffer: Int32Array;
    if (typeof args[0] === 'number') {
      size = Math.min(4, args.length);
      buffer = Int32Array.from(args as number[]);
    } else if (args[0] instanceof Int32Array) {
      size = Math.min(4, args[0].length);
      buffer = args[0];
    } else {
      size = args[0].size;
      buffer = args[0].elements;
    }

    switch (size) {
      case 1:
        gles.glUniform1iv(location, buffer);
        break;
      case 2:
        gles.glUniform2iv(location, buffer);
        break;
      case 3:
        gles.glUniform3iv(location, buffer);
        break;
      case 4:
        gles.glUniform4iv(location, buffer);
        break;
      default:
        throw Error('invalid argument');
    }
  }

  bind(): void {
    gles.glUseProgram(this.handle);
  }

  unbind(): void {
    gles.glUseProgram(0);
  }

  delete(): void {
    gles.glDeleteProgram(this.handle);
    this._uniformCache.clear();
  }
}


