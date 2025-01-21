import { GLObject } from './GLObject';
import gles from 'libgles.so';
import { glm } from '@jemoc/glm';

"use shared"

@Sendable
export class Buffer implements GLObject {
  readonly handle: number;
  readonly type: number;

  constructor(type?: gles.BufferType | number) {
    this.type = type ?? gles.BufferType.GL_ARRAY_BUFFER;
    this.handle = gles.glGenBuffers(1)[0];
  }

  bind(): void {
    gles.glBindBuffer(this.handle, this.type);
  }

  unbind(): void {
    gles.glBindBuffer(this.type, 0);
  }

  delete(): void {
    gles.glDeleteBuffers(this.handle);
  }

  setData(data: glm.valuetype, usage?: gles.BufferUsage) {
    this.bind();
    gles.glBufferData(this.type, data, usage ?? gles.BufferUsage.GL_STATIC_DRAW);
  }

  setSubData(data: glm.valuetype, offset: number = 0) {
    this.bind();
    gles.glBufferSubData(this.type, offset, data);
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
    return gles.glMapBufferRange(this.type, offset, length, access);
  }

  unMapBuffer(): boolean {
    this.bind();
    return gles.glUnmapBuffer(this.type);
  }
}



