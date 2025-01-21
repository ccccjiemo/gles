import gles from 'libgles.so';
import { Buffer } from './GLBuffer';
import { VertexArray } from './GLVertexArray';
"use shared"

@Sendable
export class VertexAttributeBinding {
  readonly bindingIndex: number
  private _attributeIndex: number = 0;
  readonly vao: VertexArray;

  constructor(vao: VertexArray, index: number) {
    this.bindingIndex = index;
    this.vao = vao;
  }

  get attributeIndex(): number {
    return this._attributeIndex;
  }

  setAttribute(attributeIndex: number) {
    this._attributeIndex = attributeIndex;
    this.vao.bind();
    gles.glVertexAttribBinding(this._attributeIndex, this.bindingIndex);
  }

  setFormat(size: number, format: gles.IndicesType | number, normalize: boolean, offset: number) {
    gles.glVertexAttribFormat(this.bindingIndex, size, format, normalize ? 1 : 0, offset);
  }

  setBuffer(buffer: Buffer, offset: number, stride: number) {
    gles.glBindVertexBuffer(this.bindingIndex, buffer.handle, offset, stride);
  }
}