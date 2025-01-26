import { GLObject } from './GLObject';
import { Buffer } from './GLBuffer'
import { collections } from '@kit.ArkTS';
import { VertexAttributeBinding } from './GLVertexAttributeBinding';
import {
  glGenVertexArrays,
  glBindVertexArray,
  glDeleteVertexArrays,
  glEnableVertexAttribArray,
  glDisableVertexAttribArray,
  DrawMode,
  glDrawArrays,
  IndicesType,
  glDrawElements,
  glVertexAttribPointer
} from 'libgles.so';

"use shared"

@Sendable
export class VertexArray implements GLObject {
  readonly handle: number;
  private _bindings: collections.Map<number, VertexAttributeBinding>

  constructor() {
    this.handle = glGenVertexArrays(1)[0];
    this._bindings = new collections.Map();
    this.bind();
  }

  bind(): void {
    glBindVertexArray(this.handle);
  }

  unbind(): void {
    glBindVertexArray(0);
  }

  delete(): void {
    glDeleteVertexArrays(this.handle);
  }

  enable(attributeIndex: number) {
    glEnableVertexAttribArray(attributeIndex);
  }

  disable(attributeIndex: number) {
    glDisableVertexAttribArray(attributeIndex);
  }

  drawArrays(mode: DrawMode | number, first: number, count: number) {
    this.bind();
    glDrawArrays(mode, first, count);
  }

  /**
   *
   * @param mode { DrawMode }
   * @param count
   * @param format {IndicesType}
   * @param indices accept TypedArray
   */
  drawElements(mode: DrawMode | number, count: number, format: IndicesType | number,
    indices: ArrayLike<number>) {
    this.bind();
    glDrawElements(mode, count, format, indices);
  }

  setBuffer(buffer: Buffer, index: number, size: number, type: IndicesType | number, normalized: boolean,
    stride: number,
    pointer: number) {
    this.bind();
    buffer.bind();
    glVertexAttribPointer(index, size, type, normalized ? 1 : 0, stride, pointer);
  }

  binding(bindingIndex: number): VertexAttributeBinding {
    if (this._bindings.has(bindingIndex)) {
      return this._bindings.get(bindingIndex)!;
    }
    let binding = new VertexAttributeBinding(this, bindingIndex);
    this._bindings.set(bindingIndex, binding);
    return binding;
  }
}
