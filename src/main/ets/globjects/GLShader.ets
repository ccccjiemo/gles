
import { fileIo as fs } from "@kit.CoreFileKit";
import { ShaderType, createShaderWithSource, GL_TRUE, glDeleteShader } from "libgles.so";
import { GLObject } from './GLObject';
"use shared"

@Sendable
export class Shader implements GLObject {
  readonly handle: number;
  readonly isCompiled: boolean;
  readonly log: string;
  readonly type: number;

  constructor(type: ShaderType | number, shaderSource: string) {
    let result = createShaderWithSource(type, shaderSource);
    this.handle = result.handle;
    this.isCompiled = result.status == GL_TRUE;
    this.log = result.log;
    this.type = type;
  }

  static fromUri(type: ShaderType | number, uri: string, encoding?: string): Shader {
    let source = fs.readTextSync(uri, { encoding });
    return new Shader(type, source);
  }

  bind(): void {
  }

  unbind(): void {
  }

  delete(): void {
    glDeleteShader(this.handle);
  }
}