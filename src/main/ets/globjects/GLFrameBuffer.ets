import gles from 'libgles.so';
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
    this.handle = gles.glGenFramebuffers(1)[0];
    this.type = gles.GL_FRAMEBUFFER
  }

  get isComplete(): boolean {
    this.bind();
    return gles.GL_FRAMEBUFFER_COMPLETE == gles.glCheckFramebufferStatus(this.type);
  }

  bind(): void {
    gles.glBindFramebuffer(this.type, this.handle);
  }

  unbind(): void {
    gles.glBindFramebuffer(this.type, 0);
  }

  delete(): void {
    gles.glDeleteFramebuffers(this.handle)
  }

  attachTexture(attachment: number, texture: Texture) {
    this.bind();
    gles.glFramebufferTexture2D(this.type, attachment, texture.type, texture.handle, 0);
  }

  attachRenderBuffer(attachment: number, renderbuffer: RenderBuffer) {
    this.bind();
    gles.glFramebufferRenderbuffer(this.type, attachment, renderbuffer.type, renderbuffer.handle)
  }
}