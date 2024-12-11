import { TextureTarget, TexParamName, InternalFormat, IndicesType, MipmapTarget, GL_TEXTURE0 } from "../constant/Index";
import {
  glGenTextures,
  glBindTexture,
  glTexParameteri,
  glTexImage2D,
  glGenerateMipmap,
  glActiveTexture,
  glDeleteTextures
} from "../GLES";

interface Image2DOption {
  level?: number;
  internalFormat?: InternalFormat;
  width?: number;
  height?: number;
  border?: number;
  format?: InternalFormat;
  type?: IndicesType;
  data?: ArrayBuffer;
}

export class Texture {
  private _id: number;
  private _type: TextureTarget;

  constructor(type: TextureTarget) {
    this._type = type;
    this._id = glGenTextures(1)[0];
    glBindTexture(type, this._id);
  }

  get id(): number {
    return this._id
  }

  get textureType(): TextureTarget {
    return this._type
  }

  setParameter(name: TexParamName, value: number): Texture {
    glTexParameteri(this._type, name, value);
    return this;
  }

  image2D(option?: Image2DOption): void {
    glTexImage2D(
      this._type,
      option?.level ?? 0,
      option?.internalFormat ?? InternalFormat.GL_RGBA8,
      option?.width ?? 1024,
      option?.height ?? 1024,
      option?.border ?? 0,
      option?.format ?? InternalFormat.GL_RGBA,
      option?.type ?? IndicesType.GL_UNSIGNED_BYTE,
      option?.data ?? undefined
    )
  }

  generateMipMap() {
    glGenerateMipmap(MipmapTarget.GL_TEXTURE_2D);
  }

  bindActive(target?: number) {
    glActiveTexture(GL_TEXTURE0 + (target ?? 0));
    glBindTexture(this._type, this._id);
  }

  delete() {
    glDeleteTextures(this._id)
  }
}