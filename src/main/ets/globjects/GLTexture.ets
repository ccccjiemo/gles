import {
  glActiveTexture,
  glBindTexture,
  glDeleteTextures,
  glGenerateMipmap,
  glGenTextures,
  glTexImage2D,
  glTexParameteri,
  glTexSubImage2D,
  GL_TEXTURE0,
  IndicesType,
  InternalFormat,
  TexParamName,
  TextureTarget } from "libgles.so";
import { GLObject } from "./GLObject";
"use shared"

interface Image2DOption {
  level?: number;
  internalFormat?: InternalFormat | number;
  width?: number;
  height?: number;
  border?: number;
  format?: InternalFormat | number;
  type?: IndicesType | number;
  data?: Uint8Array;
}

interface UpdateImage2DOption extends Image2DOption {
  xoffset?: number,
  yoffset?: number,
}

@Sendable
export class Texture implements GLObject {
  readonly handle: number;
  readonly type: number;

  constructor(type?: TextureTarget | number) {
    this.type = type ?? TextureTarget.GL_TEXTURE_2D;
    this.handle = glGenTextures(1)[0];
  }


  setParameter(name: TexParamName | number, value: number): Texture {
    this.bind();
    glTexParameteri(this.handle, name, value);
    return this;
  }

  image2D(option?: Image2DOption): void {
    this.bind();
    glTexImage2D(
      this.handle,
      option?.level ?? 0,
      option?.internalFormat ?? InternalFormat.GL_RGBA8,
      option?.width ?? 1024,
      option?.height ?? 1024,
      option?.border ?? 0,
      option?.format ?? InternalFormat.GL_RGBA,
      option?.type ?? IndicesType.GL_UNSIGNED_BYTE,
      option?.data
    )
  }

  updateImage2D(option: UpdateImage2DOption) {
    this.bind();
    glTexSubImage2D(
      this.handle,
      option.level ?? 0,
      option.xoffset ?? 0,
      option.yoffset ?? 0,
      option.width ?? 0,
      option.height ?? 0,
      option.format ?? InternalFormat.GL_RGBA,
      option.type ?? IndicesType.GL_UNSIGNED_BYTE,
      option.data
    )
  }

  bind() {
    glBindTexture(this.type, this.handle);
  }

  unbind() {
    glBindTexture(this.type, 0);
  }

  generateMipMap() {
    this.bind();
    glGenerateMipmap(this.type);
  }

  bindActive(target?: number) {
    glActiveTexture(GL_TEXTURE0 + (target ?? 0));
    glBindTexture(this.type, this.handle);
  }

  delete() {
    glDeleteTextures(this.handle);
  }
}