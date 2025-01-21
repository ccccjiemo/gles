import {
  glGenRenderbuffers,
  GL_RENDERBUFFER,
  glBindRenderbuffer,
  glDeleteRenderbuffers,
  InternalFormat,
  glRenderbufferStorage
} from 'libgles.so';
import { GLObject } from './GLObject';
"use shared"

@Sendable
export class RenderBuffer implements GLObject {
  readonly handle: number;
  readonly type: number;

  constructor(type?: number) {
    this.handle = glGenRenderbuffers(1)[0];
    this.type = type ?? GL_RENDERBUFFER
  }

  bind(): void {
    glBindRenderbuffer(this.type, this.handle);
  }

  unbind(): void {
    glBindRenderbuffer(this.type, 0);
  }

  delete(): void {
    glDeleteRenderbuffers(this.handle)
  }

  storage(format: InternalFormat | number, width: number, height: number) {
    this.bind();
    glRenderbufferStorage(this.type, format, width, height);
  }
}