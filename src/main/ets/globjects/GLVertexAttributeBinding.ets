import { glVertexAttribBinding, IndicesType, glVertexAttribFormat, glBindVertexBuffer } from 'libgles.so';
import { Buffer } from './GLBuffer';
import { VertexArray } from './GLVertexArray';

"use shared"

@Sendable
export class VertexAttributeBinding {
  readonly bindingIndex: number
  private _attributeIndex: number;
  readonly vao: VertexArray;

  constructor(vao: VertexArray, index: number) {
    this.bindingIndex = index;
    this.vao = vao;
    this._attributeIndex = 0;
  }

  get attributeIndex(): number {
    return this._attributeIndex;
  }

  setAttribute(attributeIndex: number) {
    this._attributeIndex = attributeIndex;
    this.vao.bind();
    glVertexAttribBinding(this._attributeIndex, this.bindingIndex);
  }

  setFormat(size: number, format: IndicesType | number, normalize: boolean, offset: number) {
    glVertexAttribFormat(this.bindingIndex, size, format, normalize ? 1 : 0, offset);
  }

  setBuffer(buffer: Buffer, offset: number, stride: number) {
    glBindVertexBuffer(this.bindingIndex, buffer.handle, offset, stride);
  }
}