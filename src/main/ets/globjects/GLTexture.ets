import gles from "libgles.so";
import { GLObject } from "./GLObject";
"use shared"

interface Image2DOption {
  level?: number;
  internalFormat?: gles.InternalFormat | number;
  width?: number;
  height?: number;
  border?: number;
  format?: gles.InternalFormat | number;
  type?: gles.IndicesType | number;
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

  constructor(type?: gles.TextureTarget | number) {
    this.type = type ?? gles.TextureTarget.GL_TEXTURE_2D;
    this.handle = gles.glGenTextures(1)[0];
  }


  setParameter(name: gles.TexParamName | number, value: number): Texture {
    this.bind();
    gles.glTexParameteri(this.handle, name, value);
    return this;
  }

  image2D(option?: Image2DOption): void {
    this.bind();
    gles.glTexImage2D(
      this.handle,
      option?.level ?? 0,
      option?.internalFormat ?? gles.InternalFormat.GL_RGBA8,
      option?.width ?? 1024,
      option?.height ?? 1024,
      option?.border ?? 0,
      option?.format ?? gles.InternalFormat.GL_RGBA,
      option?.type ?? gles.IndicesType.GL_UNSIGNED_BYTE,
      option?.data
    )
  }

  updateImage2D(option: UpdateImage2DOption) {
    this.bind();
    gles.glTexSubImage2D(
      this.handle,
      option.level ?? 0,
      option.xoffset ?? 0,
      option.yoffset ?? 0,
      option.width ?? 0,
      option.height ?? 0,
      option.format ?? gles.InternalFormat.GL_RGBA,
      option.type ?? gles.IndicesType.GL_UNSIGNED_BYTE,
      option.data
    )
  }

  bind() {
    gles.glBindTexture(this.type, this.handle);
  }

  unbind() {
    gles.glBindTexture(this.type, 0);
  }

  generateMipMap() {
    this.bind();
    gles.glGenerateMipmap(this.type);
  }

  bindActive(target?: number) {
    gles.glActiveTexture(gles.GL_TEXTURE0 + (target ?? 0));
    gles.glBindTexture(this.type, this.handle);
  }

  delete() {
    gles.glDeleteTextures(this.handle);
  }
}