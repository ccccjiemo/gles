import { GLObject } from './GLObject';
import gles from 'libgles.so';
"use shared"

@Sendable
export class RenderBuffer implements GLObject {
  readonly handle: number;
  readonly type: number;

  constructor(type?: number) {
    this.handle = gles.glGenRenderbuffers(1)[0];
    this.type = type ?? gles.GL_RENDERBUFFER
  }

  bind(): void {
    gles.glBindRenderbuffer(this.type, this.handle);
  }

  unbind(): void {
    gles.glBindRenderbuffer(this.type, 0);
  }

  delete(): void {
    gles.glDeleteRenderbuffers(this.handle)
  }

  storage(format: gles.InternalFormat | number, width: number, height: number) {
    this.bind();
    gles.glRenderbufferStorage(this.type, format, width, height);
  }
}