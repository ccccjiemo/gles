import { createShaderWithSource, glDeleteShader } from 'libgles.so';
import { fileIo as fs } from "@kit.CoreFileKit";
import { ShaderType } from '../constant/ShaderType';
import { GL_TRUE } from '../constant/constants';
import { GLObject } from './GLObject';

@Sendable
export class GLShader implements GLObject {
  readonly handle: number;
  readonly isCompiled: boolean;
  readonly log: string;
  readonly type: number;

  constructor(type: ShaderType, shaderSource: string) {
    let result = createShaderWithSource(type, shaderSource);
    this.handle = result.handle;
    this.isCompiled = result.status == GL_TRUE;
    this.log = result.log;
    this.type = type;
  }

  static fromUri(type: ShaderType, uri: string, encoding?: string) {
    let source = fs.readTextSync(uri, { encoding });
    return new GLShader(type, source);
  }

  bind(): void {
  }

  unbind(): void {
  }

  delete(): void {
    glDeleteShader(this.handle);
  }
}