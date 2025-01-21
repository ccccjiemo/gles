import { GLObject } from './GLObject';
import { glm } from '../glm/index';
import {
  glBindBuffer,
  glDeleteBuffers,
  BufferUsage,
  glBufferData,
  glBufferSubData,
  glMapBufferRange,
  glUnmapBuffer,
  glGenBuffers,
  BufferType
} from 'libgles.so';

"use shared"

@Sendable
export class Buffer implements GLObject {
  readonly handle: number;
  readonly type: number;

  constructor(type?: BufferType | number) {
    this.type = type ?? BufferType.GL_ARRAY_BUFFER;
    this.handle = glGenBuffers(1)[0];
  }

  bind(): void {
    glBindBuffer(this.handle, this.type);
  }

  unbind(): void {
    glBindBuffer(this.type, 0);
  }

  delete(): void {
    glDeleteBuffers(this.handle);
  }

  setData(data: glm.valuetype, usage?: BufferUsage) {
    this.bind();
    glBufferData(this.type, data, usage ?? BufferUsage.GL_STATIC_DRAW);
  }

  setSubData(data: glm.valuetype, offset: number = 0) {
    this.bind();
    glBufferSubData(this.type, offset, data);
  }

  /**
   *
   * @param offset
   * @param length
   * @param access GL_MAP_READ_BIT / GL_MAP_WRITE_BIT
   * @returns
   */
  mapBufferRange(offset: number, length: number, access: number): ArrayBuffer {
    this.bind();
    return glMapBufferRange(this.type, offset, length, access);
  }

  unMapBuffer(): boolean {
    this.bind();
    return glUnmapBuffer(this.type);
  }
}



