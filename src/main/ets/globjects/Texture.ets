import {
  glActiveTexture,
  glBindTexture,
  glDeleteTextures,
  glGenerateMipmap,
  glGenTextures,
  glTexImage2D,
  glTexParameteri,
  glTexSubImage2D
} from "libgles.so";
import { TextureTarget, TexParamName, InternalFormat, IndicesType, MipmapTarget, GL_TEXTURE0 } from "../constant/Index";


interface Image2DOption {
  level?: number;
  internalFormat?: InternalFormat;
  width?: number;
  height?: number;
  border?: number;
  format?: InternalFormat;
  type?: IndicesType;
  data?: ArrayLike<number>;
}

interface UpdateImage2DOption extends Image2DOption {
  xoffset?: number,
  yoffset?: number,
}

export class Texture {
  private _id: number;
  private _type: TextureTarget;

  constructor(type?: TextureTarget) {
    this._type = type ?? TextureTarget.GL_TEXTURE_2D;
    this._id = glGenTextures(1)[0];
  }

  get id(): number {
    return this._id
  }

  get textureType(): TextureTarget {
    return this._type
  }

  setParameter(name: TexParamName, value: number): Texture {
    this.bind();
    glTexParameteri(this._type, name, value);
    return this;
  }

  image2D(option?: Image2DOption): void {
    this.bind();
    glTexImage2D(
      this._type,
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
      this._type,
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
    glBindTexture(this._type, this._id);
  }

  unbind() {
    glBindTexture(this._type, 0);
  }

  generateMipMap() {
    this.bind();
    glGenerateMipmap(MipmapTarget.GL_TEXTURE_2D);
  }

  bindActive(target?: number) {
    glActiveTexture(GL_TEXTURE0 + (target ?? 0));
    glBindTexture(this._type, this._id);
  }

  delete() {
    glDeleteTextures(new Uint32Array([this._id]));
  }
}

@Sendable
export class Texture2 {
  private _id: number;
  private _type: number;

  constructor(type?: TextureTarget) {
    this._type = type ?? TextureTarget.GL_TEXTURE_2D;
    this._id = glGenTextures(1)[0];
  }

  get id(): number {
    return this._id
  }

  get textureType(): TextureTarget {
    return this._type
  }

  setParameter(name: TexParamName, value: number): Texture2 {
    this.bind();
    glTexParameteri(this._type, name, value);
    return this;
  }

  image2D(option?: Image2DOption): void {
    this.bind();
    glTexImage2D(
      this._type,
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
      this._type,
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
    glBindTexture(this._type, this._id);
  }

  unbind() {
    glBindTexture(this._type, 0);
  }

  generateMipMap() {
    this.bind();
    glGenerateMipmap(MipmapTarget.GL_TEXTURE_2D);
  }

  bindActive(target?: number) {
    glActiveTexture(GL_TEXTURE0 + (target ?? 0));
    glBindTexture(this._type, this._id);
  }

  delete() {
    glDeleteTextures(new Uint32Array([this._id]));
  }
}