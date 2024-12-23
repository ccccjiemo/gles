import { DrawMode, IndicesType } from "../constant/Index";
import { collections, HashMap } from "@kit.ArkTS";
import { VertexAttributeBinding } from "./VertexAttributeBinding";
import { Buffer, Buffer2 } from './Buffer'
import {
  glBindVertexArray,
  glDeleteVertexArrays,
  glDisableVertexAttribArray,
  glDrawArrays,
  glDrawElements,
  glEnableVertexAttribArray,
  glGenVertexArrays,
  glVertexAttribPointer
} from "libgles.so";


export class VertexArray {
  private _id: number;
  private _bindings: HashMap<number, VertexAttributeBinding>;

  constructor() {
    this._id = glGenVertexArrays(1)[0];
    this._bindings = new HashMap();
  }

  get id(): number {
    return this._id;
  }

  bind() {
    glBindVertexArray(this._id);
  }

  unbind() {
    glBindVertexArray(0);
  }

  enable(attributeIndex: number) {
    glEnableVertexAttribArray(attributeIndex);
  }

  disable(attributeIndex: number) {
    glDisableVertexAttribArray(attributeIndex);
  }

  drawArrays(mode: DrawMode, first: number, count: number) {
    this.bind();
    glDrawArrays(mode, first, count);
  }

  drawElements(mode: DrawMode, count: number, indices: Uint8Array | Uint16Array | Uint32Array) {
    this.bind();
    glDrawElements(mode, count, getIndicesType(indices), indices);
  }

  setBuffer(buffer: Buffer, index: number, size: number, type: IndicesType, normalized: boolean, stride: number,
    pointer: number) {
    this.bind();
    buffer.bind();
    glVertexAttribPointer(index, size, type, normalized ? 1 : 0, stride, pointer);
  }

  binding(vertexIndex: number) {
    if (this._bindings.hasKey(vertexIndex)) {
      return this._bindings.get(vertexIndex);
    }

    let binding = new VertexAttributeBinding(this, vertexIndex);
    this._bindings.set(vertexIndex, binding);
    return binding;
  }

  delete() {
    glDeleteVertexArrays(new Uint32Array([this._id]));
  }
}

function getIndicesType(buffer: ArrayLike<number>) {
  if (buffer instanceof ArrayBuffer || buffer instanceof Uint8Array) {
    return IndicesType.GL_UNSIGNED_BYTE;
  }

  if (buffer instanceof Uint16Array) {
    return IndicesType.GL_UNSIGNED_SHORT;
  }

  if (buffer instanceof Uint32Array) {
    return IndicesType.GL_UNSIGNED_INT;
  }

  if (buffer instanceof Int32Array) {
    return IndicesType.GL_INT;
  }

  if (buffer instanceof Float32Array) {
    return IndicesType.GL_FLOAT;
  }

  return IndicesType.GL_UNSIGNED_BYTE;
}

@Sendable
export class VertexArray2 {
  private _id: number;

  // private _bindings: collections.Map<number, VertexAttributeBinding>;

  constructor() {
    this._id = glGenVertexArrays(1)[0];
    // this._bindings = new HashMap();
  }

  get id(): number {
    return this._id;
  }

  bind() {
    glBindVertexArray(this._id);
  }

  unbind() {
    glBindVertexArray(0);
  }

  enable(attributeIndex: number) {
    glEnableVertexAttribArray(attributeIndex);
  }

  disable(attributeIndex: number) {
    glDisableVertexAttribArray(attributeIndex);
  }

  drawArrays(mode: DrawMode, first: number, count: number) {
    this.bind();
    glDrawArrays(mode, first, count);
  }

  drawElements(mode: DrawMode, count: number,
    indices: collections.Uint8Array | collections.Uint16Array | collections.Uint32Array) {
    this.bind();
    let type = 0;
    if (indices instanceof Uint8Array) {
      type = IndicesType.GL_UNSIGNED_BYTE;
    } else if (indices instanceof Uint16Array) {
      type = IndicesType.GL_UNSIGNED_SHORT;
    } else {
      type = IndicesType.GL_UNSIGNED_INT;
    }
    glDrawElements(mode, count, type, indices);
  }

  setBuffer(buffer: Buffer2, index: number, size: number, type: IndicesType, normalized: boolean, stride: number,
    pointer: number) {
    this.bind();
    buffer.bind();
    glVertexAttribPointer(index, size, type, normalized ? 1 : 0, stride, pointer);
  }

  // binding(vertexIndex: number) {
  //   if (this._bindings.hasKey(vertexIndex)) {
  //     return this._bindings.get(vertexIndex);
  //   }
  //
  //   let binding = new VertexAttributeBinding(this, vertexIndex);
  //   this._bindings.set(vertexIndex, binding);
  //   return binding;
  // }

  delete() {
    glDeleteVertexArrays(new Uint32Array([this._id]));
  }
}