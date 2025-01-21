import { GLObject } from './GLObject';
import { Buffer } from './GLBuffer'
import { collections } from '@kit.ArkTS';
import { VertexAttributeBinding } from './GLVertexAttributeBinding';
import gles from 'libgles.so';
"use shared"

@Sendable
export class VertexArray implements GLObject {
  handle: number;
  private _bindings: collections.Map<number, VertexAttributeBinding>

  constructor() {
    this.handle = gles.glGenVertexArrays(1)[0];
    this._bindings = new collections.Map();
  }

  bind(): void {
    gles.glBindVertexArray(this.handle);
  }

  unbind(): void {
    gles.glBindVertexArray(0);
  }

  delete(): void {
    gles.glDeleteVertexArrays(this.handle);
  }

  enable(attributeIndex: number) {
    gles.glEnableVertexAttribArray(attributeIndex);
  }

  disable(attributeIndex: number) {
    gles.glDisableVertexAttribArray(attributeIndex);
  }

  drawArrays(mode: gles.DrawMode | number, first: number, count: number) {
    this.bind();
    gles.glDrawArrays(mode, first, count);
  }

  /**
   *
   * @param mode { DrawMode }
   * @param count
   * @param format {IndicesType}
   * @param indices accept TypedArray
   */
  drawElements(mode: gles.DrawMode | number, count: number, format: gles.IndicesType | number,
    indices: ArrayLike<number>) {
    this.bind();
    gles.glDrawElements(mode, count, format, indices);
  }

  setBuffer(buffer: Buffer, index: number, size: number, type: gles.IndicesType | number, normalized: boolean,
    stride: number,
    pointer: number) {
    this.bind();
    buffer.bind();
    gles.glVertexAttribPointer(index, size, type, normalized ? 1 : 0, stride, pointer);
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
