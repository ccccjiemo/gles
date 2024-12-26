import {
  glBindBuffer,
  glBufferData,
  glBufferSubData,
  glDeleteBuffers,
  glGenBuffers,
  glGetBufferParameteri64v,
  glGetBufferParameteriv
} from 'libgles.so';
import { BufferType, BufferUsage, BufferParamName } from '../constant/Index'

export class Buffer {
  private _id: number;
  private _type: BufferType;

  constructor(target?: BufferType) {
    this._id = glGenBuffers(1)[0];
    this._type = target ?? BufferType.GL_ARRAY_BUFFER;
  }

  get id() {
    return this._id;
  }

  get bufferType() {
    return this._type;
  }

  bind() {
    glBindBuffer(this._type, this._id);
  }

  unbind() {
    glBindBuffer(this._type, 0);
  }

  // map(access?: BufferAccessMode) {
  // }

  setData(data: ArrayLike<number>, usage: BufferUsage) {
    this.bind();
    glBufferData(this._type, data, usage);
  }

  setSubData(data: ArrayLike<number>, offset: number) {
    this.bind();
    glBufferSubData(this._type, offset, data);
  }


  getParameter(pname: BufferParamName): number {
    this.bind();
    return glGetBufferParameteriv(this._type, pname);
  }

  getParameter64(pname: BufferParamName): number {
    this.bind();
    return glGetBufferParameteri64v(this._type, pname);
  }

  delete() {
    glDeleteBuffers(new Uint32Array([this._id]))
  }
}

"use shared"

@Sendable
export class Buffer2 {
  private _id: number;
  private _type: number;

  constructor(target?: BufferType) {
    this._id = glGenBuffers(1)[0];
    this._type = target ?? BufferType.GL_ARRAY_BUFFER;
  }

  get id() {
    return this._id;
  }

  get bufferType() {
    return this._type;
  }

  bind() {
    glBindBuffer(this._type, this._id);
  }

  unbind() {
    glBindBuffer(this._type, 0);
  }

  // map(access?: BufferAccessMode) {
  // }

  setData(data: ArrayLike<number>, usage: BufferUsage) {
    this.bind();
    glBufferData(this._type, data, usage);
  }

  setSubData(data: ArrayLike<number>, offset: number) {
    this.bind();
    glBufferSubData(this._type, offset, data);
  }


  getParameter(pname: BufferParamName): number {
    this.bind();
    return glGetBufferParameteriv(this._type, pname);
  }

  getParameter64(pname: BufferParamName): number {
    this.bind();
    return glGetBufferParameteri64v(this._type, pname);
  }

  delete() {
    glDeleteBuffers(new Uint32Array([this._id]))
  }
}