import { glVertexAttribBinding } from "libgles.so";
import { IndicesType } from "../constant/Index";
import { glBindVertexBuffer, GLboolean, glVertexAttribFormat } from "../GLES";
import { Buffer } from "./Buffer";
import { VertexArray } from "./VertexArray";

export class VertexAttributeBinding {
  private readonly _vao: VertexArray;
  private readonly _bindingindex: number;
  private _vbo?: Buffer;
  private _attribindex: number;

  constructor(vao: VertexArray, bindingindex: number) {
    this._vao = vao;
    this._bindingindex = bindingindex;
    this._attribindex = 0;
  }

  setBuffer(vbo: Buffer, baseOffset: number, stride: number) {
    this._vbo = vbo;
    this._vao.bind();
    glBindVertexBuffer(this._bindingindex, this._vbo.id, baseOffset, stride);
    // glVertexArrayVertexBuffer(vao(binding) - > id(), bindingIndex(binding), vbo ? vbo - > id() : 0, baseoffset, stride);

  }

  setFormat(size: number, type: IndicesType, normalized: boolean, relativeOffset: number) {
    this._vao.bind();
    glVertexAttribFormat(this._attribindex, size, type, normalized ? 1 : 0, relativeOffset);
    //glVertexArrayAttribFormat(vao(binding) - > id(), attributeIndex(binding), size, type, normalized, relativeoffset);

  }

  setAttribute(attribindex: number) {
    this._attribindex = attribindex;
    this._vao.bind();
    glVertexAttribBinding(this._attribindex, this._bindingindex);
  }
}