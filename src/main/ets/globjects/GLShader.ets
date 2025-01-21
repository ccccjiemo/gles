
import { fileIo as fs } from "@kit.CoreFileKit";
import { GLObject } from './GLObject';
import gles from "libgles.so";
"use shared"

@Sendable
export class Shader implements GLObject {
  readonly handle: number;
  readonly isCompiled: boolean;
  readonly log: string;
  readonly type: number;

  constructor(type: gles.ShaderType | number, shaderSource: string) {
    let result = gles.createShaderWithSource(type, shaderSource);
    this.handle = result.handle;
    this.isCompiled = result.status == gles.GL_TRUE;
    this.log = result.log;
    this.type = type;
  }

  static fromUri(type: gles.ShaderType | number, uri: string, encoding?: string): Shader {
    let source = fs.readTextSync(uri, { encoding });
    return new Shader(type, source);
  }

  bind(): void {
  }

  unbind(): void {
  }

  delete(): void {
    gles.glDeleteShader(this.handle);
  }
}