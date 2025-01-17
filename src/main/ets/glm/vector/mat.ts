import { float, valuetype } from './nvec'


interface mat<T extends valuetype, R extends number, C extends number> {
  elements: T;
  rows: R;
  cols: C;
}

class BaseMat<T extends valuetype, R extends number, C extends number> implements mat<T, R, C> {
  elements: T;
  rows: R;
  cols: C;
  constructor(row: R, col: C, data: number[], type: { new(size: number | number[]): T }) {
    this.rows = row;
    this.cols = col;
    const size = row * col;
    this.elements = new type(data.length ? data : size);
  }

}

class matn<R extends number, C extends number> extends BaseMat<float, R, C> {
  constructor(row: R, col: C, ...args: number[]) {
    super(row, col, args, Float32Array);
  }
}

// namespace glm {
//   export function mat2(...args: number[]): mat<float, 2,2> {
//     return new matn(2, 2,...args);
//   }
// }