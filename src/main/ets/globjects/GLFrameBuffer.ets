import {
  glGenFramebuffers,
  GL_FRAMEBUFFER,
  GL_FRAMEBUFFER_COMPLETE,
  glCheckFramebufferStatus,
  glBindFramebuffer,
  glDeleteFramebuffers,
  glFramebufferTexture2D,
  glFramebufferRenderbuffer
} from 'libgles.so';
import { GLObject } from './GLObject';
import { RenderBuffer } from './GLRenderBuffer';
import { Texture } from './GLTexture';
"use shared"

@Sendable
export class FrameBuffer implements GLObject {
  readonly handle: number;
  readonly type: number;

  /**
   * GL_FRAMEBUFFER/GL_READ_FRAMEBUFFER/GL_WRITE_FRAMEBUFFER
   * @param type
   */
  constructor(type?: number) {
    this.handle = glGenFramebuffers(1)[0];
    this.type = GL_FRAMEBUFFER
  }

  get isComplete(): boolean {
    this.bind();
    return GL_FRAMEBUFFER_COMPLETE == glCheckFramebufferStatus(this.type);
  }

  bind(): void {
    glBindFramebuffer(this.type, this.handle);
  }

  unbind(): void {
    glBindFramebuffer(this.type, 0);
  }

  delete(): void {
    glDeleteFramebuffers(this.handle)
  }

  attachTexture(attachment: number, texture: Texture) {
    this.bind();
    glFramebufferTexture2D(this.type, attachment, texture.type, texture.handle, 0);
  }

  attachRenderBuffer(attachment: number, renderbuffer: RenderBuffer) {
    this.bind();
    glFramebufferRenderbuffer(this.type, attachment, renderbuffer.type, renderbuffer.handle)
  }
}