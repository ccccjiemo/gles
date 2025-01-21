import { TypeConstructor, valuetype, VecSize, Rows, Cols, } from './common';
import { MatBase, mat as Mat } from './mat';
import { VecBase, vec as Vec, nvec } from './vec';

const d1 = Math.PI / 180;
const d2 = 180 / Math.PI;


// type Operand<T extends valuetype, S extends VecSize, R extends Rows, C extends Cols> = vec<T, S> | mat<T, R, C>;


function rotationMatrix<T extends valuetype>(m: Mat<T, 4, 4>, angle: number, axis: Vec<T, 3>): Mat<T, 4, 4> {
  const c = Math.cos(angle);
  const s = Math.sin(angle);

  const normalizedAxis = glm.normalize(axis);
  const temp = normalizedAxis.mul(1 - c);

  // Build rotation matrix according to GLM implementation
  const matrix = [
    c + temp.x * normalizedAxis.x, temp.x * normalizedAxis.y - s * normalizedAxis.z,
    temp.x * normalizedAxis.z + s * normalizedAxis.y, 0,
    temp.y * normalizedAxis.x + s * normalizedAxis.z, c + temp.y * normalizedAxis.y,
    temp.y * normalizedAxis.z - s * normalizedAxis.x, 0,
    temp.z * normalizedAxis.x - s * normalizedAxis.y, temp.z * normalizedAxis.y + s * normalizedAxis.x,
    c + temp.z * normalizedAxis.z, 0,
    0, 0, 0, 1
  ];

  return new MatBase(4, 4, m.elements.constructor as TypeConstructor<T>, matrix);
}

export namespace glm {

  export type valuetype = int | uint | float | double ;

  type ML = 2 | 3 | 4;

  export type Rows = ML;

  export type Cols = ML;

  export interface TypeConstructor<T extends valuetype> {
    readonly prototype: T;

    new(length: number): T;

    new(array: ArrayLike<number> | ArrayBufferLike): T;

    new(buffer: ArrayBufferLike, byteOffset?: number, length?: number): T;

    readonly BYTES_PER_ELEMENT: number;

    of(...items: number[]): T;

    from(arrayLike: ArrayLike<number>): T;

    from<T>(arrayLike: ArrayLike<T>, mapfn: (v: T, k: number) => number, thisArg?: any): T;
  }

  export type Tuple<T, N extends number, R extends T[] = []> = R['length'] extends N ? R : Tuple<T, N, [T, ...R]>;

  export type IsGreaterOrEqual<A extends number, B extends number> =
    A extends B ? true :
      B extends 1 ? true :
        B extends 2 ? A extends 3 | 4 ? true : false :
          B extends 3 ? A extends 4 ? true : false :
            false;

  export type GE<N1 extends number, N2 extends number> = IsGreaterOrEqual<N1, N2> extends true ? N1 : never;

  export type Subtract<A extends number, B
  extends number> = Tuple<any, A> extends [...(infer U), ...Tuple<any, B>] ? U['length'] : never;

  export type ConcatArrays<A extends any[], B extends any[]> = [...A, ...B];


  export type Multiply<A extends Rows, B extends Cols> =
    A extends 2 ? B extends 2 ? 4 : B extends 3 ? 6 : 8 :
      A extends 3 ? B extends 2 ? 6 : B extends 3 ? 9 : 12 :
        A extends 4 ? B extends 2 ? 8 : B extends 3 ? 12 : 16 : never;

  type Decrement<T extends number> =
    T extends 4 ? 3 :
      T extends 3 ? 2 :
        T extends 2 ? 1 :
          never;

  export type Range<T extends number, U extends number = 2> = T extends U ? T : T | Range<Decrement<T>, U>;

  export type TupleUnionBySize<TSize extends 1 | 2 | 3 | 4> =
    TSize extends 1 ? [number] :
      TSize extends 2 ? [number] | [number, number] :
        TSize extends 3 ? [number] | [number, number] | [number, number, number] :
        [number] | [number, number] | [number, number, number] | [number, number, number, number];


  export type float = Float32Array;

  export type int = Int32Array;

  export type double = Float64Array;

  export type uint = Uint32Array;

  export type vec<T extends valuetype, TSize extends VecSize> = Vec<T, TSize>;

  export type mat<T extends valuetype, R extends Rows, C extends Cols> = Mat<T, R, C>;


  /**
   * 角度转弧度
   * @param degrees
   * @returns
   */
  export function radians(degrees: number): number

  export function radians<T extends valuetype, S extends VecSize>(vec: vec<T, S>): vec<T, S>

  export function radians(degrees: number | vec<any, any>): number | vec<any, any> {
    if (typeof degrees === 'number') {
      return degrees * d1;
    } else {
      let result = degrees.elements.map((value) => {
        return radians(value);
      });
      return VecBase.createNew(degrees, result);
    }
  }

  /**
   * 弧度转角度
   * @param radian
   * @returns
   */
  export function degrees(degrees: number): number

  export function degrees<T extends valuetype, S extends VecSize>(vec: vec<T, S>): vec<T, S>

  export function degrees(radians: number | vec<any, any>): number | vec<any, any> {
    if (typeof radians === 'number') {
      return radians * d2;
    } else {
      let result = radians.elements.map((value) => {
        return degrees(value);
      });
      return VecBase.createNew(radians, result);
    }
  }

  /**
   * 矩阵平移
   * @param m
   * @param v
   * @returns
   */
  export function translate<T extends valuetype>(m: mat<T, 4, 4>, v: vec<T, 3>): mat<T, 4, 4> {
    let result = m.clone();

    result.elements[12] = m.elements[0] * v.x + m.elements[4] * v.y + m.elements[8] * v.z + m.elements[12];
    result.elements[13] = m.elements[1] * v.x + m.elements[5] * v.y + m.elements[9] * v.z + m.elements[13];
    result.elements[14] = m.elements[2] * v.x + m.elements[6] * v.y + m.elements[10] * v.z + m.elements[14];
    result.elements[15] = m.elements[3] * v.x + m.elements[7] * v.y + m.elements[11] * v.z + m.elements[15];

    return result;
  }


  /**
   * 矩阵缩放
   * @param m
   * @param v
   * @returns
   */
  export function scale<T extends valuetype>(m: mat<T, 4, 4>, v: vec<T, 3>): mat<T, 4, 4> {
    let result = (m as MatBase<T, 4, 4>).clone();
    result.elements[0] *= v.x;
    result.elements[5] *= v.y;
    result.elements[10] *= v.z;
    return result;
  }

  /**
   * 归一化
   * @param v
   * @returns
   */
  export function normalize<T extends valuetype, S extends VecSize>(v: vec<T, S>): vec<T, S> {
    let result = v.clone();
    let length = v.length;
    if (length === 0) {
      result.elements.fill(0);
    } else {
      for (let i = 0; i < result.size; i++) {
        result.elements[i] /= length;
      }

    }
    return result;

  }

  /**
   * 逆矩阵
   * @param m
   * @returns
   */
  export function inverse<T extends valuetype, R extends Rows, C extends Cols>(m: mat<T, R, C>): mat<T, R, C> {
    return m.inverse;
  }

  /**
   * 旋转
   * @param m
   * @param angle
   * @param axis
   * @returns
   */
  export function rotate<T extends valuetype>(m: mat<T, 4, 4>, angle: number, axis: vec<T, 3>): mat<T, 4, 4> {
    if (axis.length <= 0) {
      return m.clone();
    }

    const rotMat = rotationMatrix(m, angle, axis);

    // Perform the multiplication as per GLM implementation
    const result = m.clone();
    result.elements[0] =
      m.elements[0] * rotMat.elements[0] + m.elements[4] * rotMat.elements[1] + m.elements[8] * rotMat.elements[2];
    result.elements[4] =
      m.elements[0] * rotMat.elements[4] + m.elements[4] * rotMat.elements[5] + m.elements[8] * rotMat.elements[6];
    result.elements[8] =
      m.elements[0] * rotMat.elements[8] + m.elements[4] * rotMat.elements[9] + m.elements[8] * rotMat.elements[10];

    result.elements[1] =
      m.elements[1] * rotMat.elements[0] + m.elements[5] * rotMat.elements[1] + m.elements[9] * rotMat.elements[2];
    result.elements[5] =
      m.elements[1] * rotMat.elements[4] + m.elements[5] * rotMat.elements[5] + m.elements[9] * rotMat.elements[6];
    result.elements[9] =
      m.elements[1] * rotMat.elements[8] + m.elements[5] * rotMat.elements[9] + m.elements[9] * rotMat.elements[10];

    result.elements[2] =
      m.elements[2] * rotMat.elements[0] + m.elements[6] * rotMat.elements[1] + m.elements[10] * rotMat.elements[2];
    result.elements[6] =
      m.elements[2] * rotMat.elements[4] + m.elements[6] * rotMat.elements[5] + m.elements[10] * rotMat.elements[6];
    result.elements[10] =
      m.elements[2] * rotMat.elements[8] + m.elements[6] * rotMat.elements[9] + m.elements[10] * rotMat.elements[10];

    // Keep the last column unchanged
    result.elements[3] = m.elements[3];
    result.elements[7] = m.elements[7];
    result.elements[11] = m.elements[11];
    result.elements[12] = m.elements[12];
    result.elements[13] = m.elements[13];
    result.elements[14] = m.elements[14];
    result.elements[15] = m.elements[15];

    return result;
  }


  /**
   * 正交投影
   * @param constructor
   * @param left
   * @param right
   * @param bottom
   * @param top
   * @param near
   * @param far
   * @returns
   */
  export function ortho<T extends valuetype>(constructor: TypeConstructor<T>, left: number, right: number,
    bottom: number, top: number, near: number, far: number): mat<T, 4, 4> {
    let result = new MatBase(4, 4, constructor);
    result.elements[0] = 2 / (right - left);
    result.elements[5] = 2 / (top - bottom);
    result.elements[10] = -2 / (far - near);
    result.elements[12] = -(right + left) / (right - left);
    result.elements[13] = -(top + bottom) / (top - bottom);
    result.elements[14] = -(far + near) / (far - near);
    return result;

  }

  /**
   * 透视投影
   * @param constructor
   * @param fovy
   * @param aspect
   * @param near
   * @param far
   * @returns
   */
  export function perspective<T extends valuetype>(constructor: TypeConstructor<T>, fovy: number, aspect: number,
    near: number, far: number): mat<T, 4, 4> {
    let tanHalfFovy = Math.tan(fovy / 2.0);
    let result = new MatBase(4, 4, constructor);

    result.elements[0] = 1.0 / (aspect * tanHalfFovy);
    result.elements[5] = 1.0 / tanHalfFovy;
    result.elements[10] = -(far + near) / (far - near);
    result.elements[11] = -1.0;
    result.elements[14] = -(2.0 * far * near) / (far - near);
    return result;
  }

  /**
   * 点积
   * @param v0
   * @param v1
   * @returns
   */
  export function dot<T extends valuetype, TSize extends VecSize>(v0: vec<T, TSize>, v1: vec<T, TSize>): number {
    let result = 0;
    for (let i = 0; i < v0.size; i++) {
      result += v0.elements[i] * v1.elements[i];
    }
    return result;
  }

  /**
   * 叉积
   * @param v0
   * @param v1
   * @returns
   */
  export function cross<T extends valuetype>(v0: vec<T, 3>, v1: vec<T, 3>): vec<T, 3> {
    let result = v0.clone();
    result.x = v0.y * v1.z - v0.z * v1.y;
    result.y = v0.z * v1.x - v0.x * v1.z;
    result.z = v0.x * v1.y - v0.y * v1.x;
    return result;
  }

  /**
   * 向量长度
   * @param v
   * @returns
   */
  export function length(v: vec<valuetype, any>): number {
    return v.length;
  }

  /**
   * 字面意思
   * @param v
   * @returns
   */
  export function abs<T extends valuetype, S extends VecSize>(v: vec<T, S>): vec<T, S> {
    let result = v.clone();
    for (let i = 0; i < v.size; i++) {
      result.elements[i] = Math.abs(v.elements[i]);
    }
    return result;
  }

  /**
   * 矩阵转置
   * @param m
   * @returns
   */
  export function transpose<T extends valuetype, R extends Rows, C extends Cols>(m: mat<T, R, C>): mat<T, C, R> {
    return m.transpose;
  }


  /**
   * glm::vec2()
   */
  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize,
    constructor: TypeConstructor<TType>): vec<TType, TSize>

  /**
   * glm::vec2(1)
   */
  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize,
    constructor: TypeConstructor<TType>,
    scalar: number): vec<TType, TSize>

  /**
   * glm::vec1 vec1
   *
   * glm::vec2(vec1, 1)
   */
  export function Vec<TSize extends VecSize, TType extends valuetype, VS extends VecSize>(size: TSize,
    constructor: TypeConstructor<TType>, v0: vec<TType, IsGreaterOrEqual<TSize, VS> extends true ? VS : never>,
    ...args: Tuple<number, Subtract<TSize, VS>>): vec<TType, TSize>

  /**
   * glm::vec2([1,2])
   */
  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize,
    constructor: TypeConstructor<TType>,
    values: Tuple<number, TSize>): vec<TType, TSize>

  /**
   * glm::vec2(1,2)
   */
  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize,
    constructor: TypeConstructor<TType>,
    ...args: Tuple<number, TSize>): vec<TType, TSize>

  /**
   * @deprecated danger
   */
  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize,
    constructor: TypeConstructor<TType>,
    ...args: any): vec<TType, TSize>

  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize, constructor: TypeConstructor<TType>,
    ...args: any[]): vec<TType, TSize> {
    return new VecBase(size, constructor, ...args);
  }


  export function vec1(): vec<float, 1>

  export function vec1(scalar: number): vec<float, 1>

  export function vec1(...args: any[]): vec<float, 1> {
    return Vec(1, Float32Array, ...args);
  }

  export function vec2(): vec<float, 2>

  export function vec2(scalar: number): vec<float, 2>

  export function vec2(init: Tuple<number, 2>): vec<float, 2>

  export function vec2(...args: Tuple<number, 2>): vec<float, 2>

  export function vec2<TSize extends VecSize>(v0: vec<float, IsGreaterOrEqual<2, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<2, TSize>>): vec<float, 2>

  export function vec2(...args: any[]): vec<float, 2> {
    return Vec(2, Float32Array, ...args);
  }


  export function vec3(): vec<float, 3>

  export function vec3(scalar: number): vec<float, 3>

  export function vec3(init: Tuple<number, 3>): vec<float, 3>

  export function vec3<TSize extends VecSize>(v0: vec<float, IsGreaterOrEqual<3, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<3, TSize>>): vec<float, 3>

  export function vec3(...args: Tuple<number, 3>): vec<float, 3>

  export function vec3(...args: any[]): vec<float, 3> {
    return Vec(3, Float32Array, ...args);
  }


  export function vec4(): vec<float, 4>

  export function vec4(scalar: number): vec<float, 4>

  export function vec4(init: Tuple<number, 4>): vec<float, 4>

  export function vec4(...args: Tuple<number, 4>): vec<float, 4>

  export function vec4<TSize extends VecSize>(v0: vec<float, IsGreaterOrEqual<4, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<4, TSize>>): vec<float, 4>

  export function vec4(...args: any[]): vec<float, 4> {
    return Vec(4, Float32Array, ...args);
  }


  export function ivec1(): vec<int, 1>

  export function ivec1(scalar: number): vec<int, 1>

  export function ivec1(...args: any[]): vec<int, 1> {
    return Vec(1, Int32Array, ...args);
  }


  export function ivec2(): vec<int, 2>

  export function ivec2(scalar: number): vec<int, 2>

  export function ivec2(init: Tuple<number, 2>): vec<int, 2>

  export function ivec2<TSize extends VecSize>(v0: vec<int, IsGreaterOrEqual<2, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<2, TSize>>): vec<int, 2>

  export function ivec2(...args: Tuple<number, 2>): vec<int, 2>

  export function ivec2(...args: any[]): vec<int, 2> {
    return Vec(2, Int32Array, ...args);
  }


  export function ivec3(): vec<int, 3>

  export function ivec3(scalar: number): vec<int, 3>

  export function ivec3(init: Tuple<number, 3>): vec<int, 3>

  export function ivec3<TSize extends VecSize>(v0: vec<int, IsGreaterOrEqual<3, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<3, TSize>>): vec<int, 3>

  export function ivec3(...args: Tuple<number, 3>): vec<int, 3>

  export function ivec3(...args: any[]): vec<int, 3> {
    return Vec(3, Int32Array, ...args);

  }


  export function ivec4(): vec<int, 4>

  export function ivec4(scalar: number): vec<int, 4>

  export function ivec4(init: Tuple<number, 4>): vec<int, 4>

  export function ivec4<TSize extends VecSize>(v0: vec<int, IsGreaterOrEqual<4, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<4, TSize>>): vec<int, 4>

  export function ivec4(...args: Tuple<number, 4>): vec<int, 4>

  export function ivec4(...args: any[]): vec<int, 4> {
    return Vec(4, Int32Array, ...args);
  }


  export function uvec1(): vec<uint, 1>

  export function uvec1(scalar: number): vec<uint, 1>

  export function uvec1(init: Tuple<number, 1>): vec<uint, 1>

  export function uvec1(...args: Tuple<number, 1>): vec<uint, 1>

  export function uvec1(...args: any[]): vec<uint, 1> {
    return Vec(1, Uint32Array, ...args);
  }


  export function uvec2(): vec<uint, 2>

  export function uvec2(scalar: number): vec<uint, 2>

  export function uvec2(init: Tuple<number, 2>): vec<uint, 2>

  export function uvec2(v0: vec<uint, 1>, v1: number): vec<uint, 2>

  export function uvec2(...args: Tuple<number, 2>): vec<uint, 2>

  export function uvec2(...args: any[]): vec<uint, 2> {
    return Vec(2, Uint32Array, ...args);
  }


  export function uvec3(): vec<uint, 3>

  export function uvec3(scalar: number): vec<uint, 3>

  export function uvec3(init: Tuple<number, 3>): vec<uint, 3>

  export function uvec3<TSize extends VecSize>(v0: vec<uint, IsGreaterOrEqual<3, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<3, TSize>>): vec<uint, 3>

  export function uvec3(...args: Tuple<number, 3>): vec<uint, 3>

  export function uvec3(...args: any[]): vec<uint, 3> {
    return Vec(3, Uint32Array, ...args);
  }


  export function uvec4(): vec<uint, 4>

  export function uvec4(scalar: number): vec<uint, 4>

  export function uvec4(init: Tuple<number, 4>): vec<uint, 4>

  export function uvec4<TSize extends VecSize>(v0: vec<uint, IsGreaterOrEqual<4, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<4, TSize>>): vec<uint, 4>

  export function uvec4(...args: Tuple<number, 4>): vec<uint, 4>

  export function uvec4(...args: any[]): vec<uint, 4> {
    return Vec(4, Uint32Array, ...args);
  }

  export function dvec1(): vec<double, 1>

  export function dvec1(scalar: number): vec<double, 1>

  export function dvec1(...args: any[]): vec<double, 1> {
    return Vec(1, Float64Array, ...args);
  }


  export function dvec2(): vec<double, 2>

  export function dvec2(scalar: number): vec<double, 2>

  export function dvec2(init: Tuple<number, 2>): vec<double, 2>

  export function dvec2(v0: vec<double, 1>, v1: number): vec<double, 2>

  export function dvec2(...args: Tuple<number, 2>): vec<double, 2>

  export function dvec2(...args: any[]): vec<double, 2> {
    return Vec(2, Float64Array, ...args);
  }


  export function dvec3(): vec<double, 3>

  export function dvec3(scalar: number): vec<double, 3>

  export function dvec3(init: Tuple<number, 3>): vec<double, 3>

  export function dvec3<TSize extends VecSize>(v0: vec<double, IsGreaterOrEqual<3, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<3, TSize>>): vec<double, 3>

  export function dvec3(...args: Tuple<number, 3>): vec<double, 3>

  export function dvec3(...args: any[]): vec<double, 3> {
    return Vec(3, Float64Array, ...args);
  }


  export function dvec4(): vec<double, 4>

  export function dvec4(scalar: number): vec<double, 4>

  export function dvec4(init: Tuple<number, 4>): vec<double, 4>

  export function dvec4<TSize extends VecSize>(v0: vec<double, IsGreaterOrEqual<4, TSize> extends true ? TSize : never>,
    ...args: Tuple<number, Subtract<4, TSize>>): vec<double, 4>

  export function dvec4(...args: Tuple<number, 4>): vec<double, 4>

  export function dvec4(...args: any[]): vec<double, 4> {
    return Vec(4, Float64Array, ...args);
  }


  /**
   * Mat(3,3) //mat3x3()
   */
  export function Mat<R extends Rows, C extends Cols>(row: R, col: C): mat<float, R, C>

  /**
   * Mat(3,3, 1.0) //mat3x3(1.0f)
   */
  export function Mat<R extends Rows, C extends Cols>(row: R, col: C, scalar: number): mat<float, R, C>

  /**
   * Mat(2,2, 1,1,1,1) //mat2x2(1,1,1,1)
   */
  export function Mat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<number, Multiply<R, C>>): mat<float, R, C>

  /**
   * Mat(2,2, mat3x3) //mat2x2(mat3x3)
   */
  export function Mat<R extends Rows, C extends Cols>(row: R, col: C,
    v0: mat<float, Rows, Cols>): mat<float, R, C>

  /**
   * Mat(2,2, vec2, vec2) //mat2x2(vec2, vec2)
   */
  export function Mat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<vec<float, C>, R>): mat<float, R, C>

  /**
   * @deprecated danger
   * @param row
   * @param col
   * @param args
   * @returns
   */
  export function Mat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: any): mat<float, R, C>

  export function Mat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<float, TR, TC> {
    return new MatBase(row, col, Float32Array, ...args);
  }


  /**
   * Mat(3,3) //mat3x3()
   */
  export function dMat<R extends Rows, C extends Cols>(row: R, col: C): mat<double, R, C>

  /**
   * Mat(3,3, 1.0) //mat3x3(1.0f)
   */
  export function dMat<R extends Rows, C extends Cols>(row: R, col: C, scalar: number): mat<double, R, C>

  /**
   * Mat(2,2, 1,1,1,1) //mat2x2(1,1,1,1)
   */
  export function dMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<number, Multiply<R, C>>): mat<double, R, C>

  /**
   * Mat(2,2, mat3x3) //mat2x2(mat3x3)
   */
  export function dMat<R extends Rows, C extends Cols>(row: R, col: C,
    v0: mat<double, Rows, Cols>): mat<double, R, C>

  /**
   * Mat(2,2, vec2, vec2) //mat2x2(vec2, vec2)
   */
  export function dMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<vec<float, C>, R>): mat<double, R, C>

  export function dMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: any): mat<double, R, C>

  export function dMat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<double, TR, TC> {
    return new MatBase(row, col, Float64Array, ...args);
  }


  /**
   * Mat(3,3) //mat3x3()
   */
  export function iMat<R extends Rows, C extends Cols>(row: R, col: C): mat<int, R, C>

  /**
   * Mat(3,3, 1.0) //mat3x3(1.0f)
   */
  export function iMat<R extends Rows, C extends Cols>(row: R, col: C, scalar: number): mat<int, R, C>

  /**
   * Mat(2,2, 1,1,1,1) //mat2x2(1,1,1,1)
   */
  export function iMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<number, Multiply<R, C>>): mat<int, R, C>

  /**
   * Mat(2,2, mat3x3) //mat2x2(mat3x3)
   */
  export function iMat<R extends Rows, C extends Cols>(row: R, col: C,
    v0: mat<int, Rows, Cols>): mat<int, R, C>

  /**
   * Mat(2,2, vec2, vec2) //mat2x2(vec2, vec2)
   */
  export function iMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<vec<int, C>, R>): mat<int, R, C>

  export function iMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: any): mat<int, R, C>

  export function iMat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<int, TR, TC> {
    return new MatBase(row, col, Int32Array, ...args);
  }


  /**
   * Mat(3,3) //mat3x3()
   */
  export function uMat<R extends Rows, C extends Cols>(row: R, col: C): mat<uint, R, C>

  /**
   * Mat(3,3, 1.0) //mat3x3(1.0f)
   */
  export function uMat<R extends Rows, C extends Cols>(row: R, col: C, scalar: number): mat<uint, R, C>

  /**
   * Mat(2,2, 1,1,1,1) //mat2x2(1,1,1,1)
   */
  export function uMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<number, Multiply<R, C>>): mat<uint, R, C>

  /**
   * Mat(2,2, mat3x3) //mat2x2(mat3x3)
   */
  export function uMat<R extends Rows, C extends Cols>(row: R, col: C,
    v0: mat<uint, Rows, Cols>): mat<uint, R, C>

  /**
   * @deprecated danger
   */
  export function uMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: any[]): mat<uint, R, C>

  /**
   * Mat(2,2, vec2, vec2) //mat2x2(vec2, vec2)
   */
  export function uMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: Tuple<vec<uint, C>, R>): mat<uint, R, C>

  export function uMat<R extends Rows, C extends Cols>(row: R, col: C,
    ...args: any): mat<uint, R, C>

  export function uMat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<uint, TR, TC> {
    return new MatBase(row, col, Uint32Array, ...args);
  }


  /**
   * 2x2 matrix
   * @returns
   */
  export function mat2(): mat<float, 2, 2>

  export function mat2(scalar: number): mat<float, 2, 2>

  export function mat2(...args: Tuple<number, Multiply<2, 2>>): mat<float, 2, 2>

  export function mat2(v0: mat<float, Rows, Cols>): mat<float, 2, 2>

  export function mat2(...args: Tuple<vec<float, 2>, 2>): mat<float, 2, 2>

  export function mat2(...args: any[]): mat<float, 2, 2> {
    return Mat(2, 2, ...args);
  }


  export function mat2x2(): mat<float, 2, 2>

  export function mat2x2(scalar: number): mat<float, 2, 2>

  export function mat2x2(...args: Tuple<number, Multiply<2, 2>>): mat<float, 2, 2>

  export function mat2x2(v0: mat<float, Rows, Cols>): mat<float, 2, 2>

  export function mat2x2(...args: Tuple<vec<float, 2>, 2>): mat<float, 2, 2>

  export function mat2x2(...args: any[]): mat<float, 2, 2> {
    return Mat(2, 2, ...args);
  }

  export function mat2x3(): mat<float, 2, 3>

  export function mat2x3(scalar: number): mat<float, 2, 3>

  export function mat2x3(...args: Tuple<number, Multiply<2, 3>>): mat<float, 2, 3>

  export function mat2x3(v0: mat<float, Rows, Cols>): mat<float, 2, 3>

  export function mat2x3(...args: Tuple<vec<float, 3>, 2>): mat<float, 2, 3>

  export function mat2x3(...args: any[]): mat<float, 2, 3> {
    return Mat(2, 3, ...args);
  }

  export function mat2x4(): mat<float, 2, 4>

  export function mat2x4(scalar: number): mat<float, 2, 4>

  export function mat2x4(...args: Tuple<number, Multiply<2, 4>>): mat<float, 2, 4>

  export function mat2x4(v0: mat<float, Rows, Cols>): mat<float, 2, 4>

  export function mat2x4(...args: Tuple<vec<float, 3>, 2>): mat<float, 2, 4>

  export function mat2x4(...args: any[]): mat<float, 2, 4> {
    return Mat(2, 4, ...args);
  }

  export function mat3(): mat<float, 3, 3>

  export function mat3(scalar: number): mat<float, 3, 3>

  export function mat3(...args: Tuple<number, Multiply<3, 3>>): mat<float, 3, 3>

  export function mat3(v0: mat<float, Rows, Cols>): mat<float, 3, 3>

  export function mat3(...args: Tuple<vec<float, 3>, 3>): mat<float, 3, 3>

  export function mat3(...args: any[]): mat<float, 3, 3> {
    return Mat(3, 3, ...args);
  }

  export function mat3x3(): mat<float, 3, 3>

  export function mat3x3(scalar: number): mat<float, 3, 3>

  export function mat3x3(...args: Tuple<number, Multiply<3, 3>>): mat<float, 3, 3>

  export function mat3x3(v0: mat<float, Rows, Cols>): mat<float, 3, 3>

  export function mat3x3(...args: Tuple<vec<float, 3>, 3>): mat<float, 3, 3>

  export function mat3x3(...args: any[]): mat<float, 3, 3> {
    return Mat(3, 3, ...args);
  }

  export function mat3x2(): mat<float, 3, 2>

  export function mat3x2(scalar: number): mat<float, 3, 2>

  export function mat3x2(...args: Tuple<number, Multiply<3, 2>>): mat<float, 3, 2>

  export function mat3x2(v0: mat<float, Rows, Cols>): mat<float, 3, 2>

  export function mat3x2(...args: Tuple<vec<float, 2>, 3>): mat<float, 3, 2>

  export function mat3x2(...args: any[]): mat<float, 3, 2> {
    return Mat(3, 2, ...args);
  }

  export function mat3x4(): mat<float, 3, 4>

  export function mat3x4(scalar: number): mat<float, 3, 4>

  export function mat3x4(...args: Tuple<number, Multiply<3, 4>>): mat<float, 3, 4>

  export function mat3x4(v0: mat<float, Rows, Cols>): mat<float, 3, 4>

  export function mat3x4(...args: Tuple<vec<float, 4>, 3>): mat<float, 3, 4>

  export function mat3x4(...args: any[]): mat<float, 3, 4> {
    return Mat(3, 4, ...args);
  }

  export function mat4(): mat<float, 4, 4>

  export function mat4(scalar: number): mat<float, 4, 4>

  export function mat4(...args: Tuple<number, Multiply<4, 4>>): mat<float, 4, 4>

  export function mat4(v0: mat<float, Rows, Cols>): mat<float, 4, 4>

  export function mat4(...args: Tuple<vec<float, 4>, 4>): mat<float, 4, 4>

  export function mat4(...args: any[]): mat<float, 4, 4> {
    return Mat(4, 4, ...args);
  }

  export function mat4x4(): mat<float, 4, 4>

  export function mat4x4(scalar: number): mat<float, 4, 4>

  export function mat4x4(...args: Tuple<number, Multiply<4, 4>>): mat<float, 4, 4>

  export function mat4x4(v0: mat<float, Rows, Cols>): mat<float, 4, 4>

  export function mat4x4(...args: Tuple<vec<float, 4>, 4>): mat<float, 4, 4>

  export function mat4x4(...args: any[]): mat<float, 4, 4> {
    return Mat(4, 4, ...args);
  }

  export function mat4x3(): mat<float, 4, 3>

  export function mat4x3(scalar: number): mat<float, 4, 3>

  export function mat4x3(...args: Tuple<number, Multiply<4, 3>>): mat<float, 4, 3>

  export function mat4x3(v0: mat<float, Rows, Cols>): mat<float, 4, 3>

  export function mat4x3(...args: Tuple<vec<float, 3>, 4>): mat<float, 4, 3>

  export function mat4x3(...args: any[]): mat<float, 4, 3> {
    return Mat(4, 3, ...args);
  }

  export function mat4x2(): mat<float, 4, 2>

  export function mat4x2(scalar: number): mat<float, 4, 2>

  export function mat4x2(...args: Tuple<number, Multiply<4, 2>>): mat<float, 4, 2>

  export function mat4x2(v0: mat<float, Rows, Cols>): mat<float, 4, 2>

  export function mat4x2(...args: Tuple<vec<float, 2>, 4>): mat<float, 4, 2>

  export function mat4x2(...args: any[]): mat<float, 4, 2> {
    return Mat(4, 2, ...args);
  }

  export function imat2(): mat<int, 2, 2>

  export function imat2(scalar: number): mat<int, 2, 2>

  export function imat2(...args: Tuple<number, Multiply<2, 2>>): mat<int, 2, 2>

  export function imat2(v0: mat<int, Rows, Cols>): mat<int, 2, 2>

  export function imat2(...args: Tuple<vec<int, 2>, 2>): mat<int, 2, 2>

  export function imat2(...args: any[]): mat<int, 2, 2> {
    return iMat(2, 2, ...args);
  }

  export function imat2x2(): mat<int, 2, 2>

  export function imat2x2(scalar: number): mat<int, 2, 2>

  export function imat2x2(...args: Tuple<number, Multiply<2, 2>>): mat<int, 2, 2>

  export function imat2x2(v0: mat<int, Rows, Cols>): mat<int, 2, 2>

  export function imat2x2(...args: Tuple<vec<int, 2>, 2>): mat<int, 2, 2>

  export function imat2x2(...args: any[]): mat<int, 2, 2> {
    return iMat(2, 2, ...args);
  }

  export function imat2x3(): mat<int, 2, 3>

  export function imat2x3(scalar: number): mat<int, 2, 3>

  export function imat2x3(...args: Tuple<number, Multiply<2, 3>>): mat<int, 2, 3>

  export function imat2x3(v0: mat<int, Rows, Cols>): mat<int, 2, 3>

  export function imat2x3(...args: Tuple<vec<int, 3>, 2>): mat<int, 2, 3>

  export function imat2x3(...args: any[]): mat<int, 2, 3> {
    return iMat(2, 3, ...args);
  }

  export function imat2x4(): mat<int, 2, 4>

  export function imat2x4(scalar: number): mat<int, 2, 4>

  export function imat2x4(...args: Tuple<number, Multiply<2, 4>>): mat<int, 2, 4>

  export function imat2x4(v0: mat<int, Rows, Cols>): mat<int, 2, 4>

  export function imat2x4(...args: Tuple<vec<int, 3>, 2>): mat<int, 2, 4>

  export function imat2x4(...args: any[]): mat<int, 2, 4> {
    return iMat(2, 4, ...args);
  }

  export function imat3(): mat<int, 3, 3>

  export function imat3(scalar: number): mat<int, 3, 3>

  export function imat3(...args: Tuple<number, Multiply<3, 3>>): mat<int, 3, 3>

  export function imat3(v0: mat<int, Rows, Cols>): mat<int, 3, 3>

  export function imat3(...args: Tuple<vec<int, 3>, 3>): mat<int, 3, 3>

  export function imat3(...args: any[]): mat<int, 3, 3> {
    return iMat(3, 3, ...args);
  }


  export function imat3x3(): mat<int, 3, 3>

  export function imat3x3(scalar: number): mat<int, 3, 3>

  export function imat3x3(...args: Tuple<number, Multiply<3, 3>>): mat<int, 3, 3>

  export function imat3x3(v0: mat<int, Rows, Cols>): mat<int, 3, 3>

  export function imat3x3(...args: Tuple<vec<int, 3>, 3>): mat<int, 3, 3>

  export function imat3x3(...args: any[]): mat<int, 3, 3> {
    return iMat(3, 3, ...args);
  }


  export function imat3x2(): mat<int, 3, 2>

  export function imat3x2(scalar: number): mat<int, 3, 2>

  export function imat3x2(...args: Tuple<number, Multiply<3, 2>>): mat<int, 3, 2>

  export function imat3x2(v0: mat<int, Rows, Cols>): mat<int, 3, 2>

  export function imat3x2(...args: Tuple<vec<int, 2>, 3>): mat<int, 3, 2>

  export function imat3x2(...args: any[]): mat<int, 3, 2> {
    return iMat(3, 2, ...args);
  }

  export function imat3x4(): mat<int, 3, 4>

  export function imat3x4(scalar: number): mat<int, 3, 4>

  export function imat3x4(...args: Tuple<number, Multiply<3, 4>>): mat<int, 3, 4>

  export function imat3x4(v0: mat<int, Rows, Cols>): mat<int, 3, 4>

  export function imat3x4(...args: Tuple<vec<int, 4>, 3>): mat<int, 3, 4>

  export function imat3x4(...args: any[]): mat<int, 3, 4> {
    return iMat(3, 4, ...args);
  }

  export function imat4(): mat<int, 4, 4>

  export function imat4(scalar: number): mat<int, 4, 4>

  export function imat4(...args: Tuple<number, Multiply<4, 4>>): mat<int, 4, 4>

  export function imat4(v0: mat<int, Rows, Cols>): mat<int, 4, 4>

  export function imat4(...args: Tuple<vec<int, 4>, 4>): mat<int, 4, 4>

  export function imat4(...args: any[]): mat<int, 4, 4> {
    return iMat(4, 4, ...args);
  }

  export function imat4x4(): mat<int, 4, 4>

  export function imat4x4(scalar: number): mat<int, 4, 4>

  export function imat4x4(...args: Tuple<number, Multiply<4, 4>>): mat<int, 4, 4>

  export function imat4x4(v0: mat<int, Rows, Cols>): mat<int, 4, 4>

  export function imat4x4(...args: Tuple<vec<int, 4>, 4>): mat<int, 4, 4>

  export function imat4x4(...args: any[]): mat<int, 4, 4> {
    return iMat(4, 4, ...args);
  }

  export function imat4x3(): mat<int, 4, 3>

  export function imat4x3(scalar: number): mat<int, 4, 3>

  export function imat4x3(...args: Tuple<number, Multiply<4, 3>>): mat<int, 4, 3>

  export function imat4x3(v0: mat<int, Rows, Cols>): mat<int, 4, 3>

  export function imat4x3(...args: Tuple<vec<int, 3>, 4>): mat<int, 4, 3>

  export function imat4x3(...args: any[]): mat<int, 4, 3> {
    return iMat(4, 3, ...args);
  }

  export function imat4x2(): mat<int, 4, 2>

  export function imat4x2(scalar: number): mat<int, 4, 2>

  export function imat4x2(...args: Tuple<number, Multiply<4, 2>>): mat<int, 4, 2>

  export function imat4x2(v0: mat<int, Rows, Cols>): mat<int, 4, 2>

  export function imat4x2(...args: Tuple<vec<int, 2>, 4>): mat<int, 4, 2>

  export function imat4x2(...args: any[]): mat<int, 4, 2> {
    return iMat(4, 2, ...args);
  }

  export function umat2(): mat<uint, 2, 2>

  export function umat2(scalar: number): mat<uint, 2, 2>

  export function umat2(...args: Tuple<number, Multiply<2, 2>>): mat<uint, 2, 2>

  export function umat2(v0: mat<uint, Rows, Cols>): mat<uint, 2, 2>

  export function umat2(...args: Tuple<vec<uint, 2>, 2>): mat<uint, 2, 2>

  export function umat2(...args: any[]): mat<uint, 2, 2> {
    return uMat(2, 2, ...args);
  }

  export function umat2x2(): mat<uint, 2, 2>

  export function umat2x2(scalar: number): mat<uint, 2, 2>

  export function umat2x2(...args: Tuple<number, Multiply<2, 2>>): mat<uint, 2, 2>

  export function umat2x2(v0: mat<uint, Rows, Cols>): mat<uint, 2, 2>

  export function umat2x2(...args: Tuple<vec<uint, 2>, 2>): mat<uint, 2, 2>

  export function umat2x2(...args: any[]): mat<uint, 2, 2> {
    return uMat(2, 2, ...args);
  }

  export function umat2x3(): mat<uint, 2, 3>

  export function umat2x3(scalar: number): mat<uint, 2, 3>

  export function umat2x3(...args: Tuple<number, Multiply<2, 3>>): mat<uint, 2, 3>

  export function umat2x3(v0: mat<uint, Rows, Cols>): mat<uint, 2, 3>

  export function umat2x3(...args: Tuple<vec<uint, 3>, 2>): mat<uint, 2, 3>

  export function umat2x3(...args: any[]): mat<uint, 2, 3> {
    return uMat(2, 3, ...args);
  }

  export function umat2x4(): mat<uint, 2, 4>

  export function umat2x4(scalar: number): mat<uint, 2, 4>

  export function umat2x4(...args: Tuple<number, Multiply<2, 4>>): mat<uint, 2, 4>

  export function umat2x4(v0: mat<uint, Rows, Cols>): mat<uint, 2, 4>

  export function umat2x4(...args: Tuple<vec<uint, 3>, 2>): mat<uint, 2, 4>

  export function umat2x4(...args: any[]): mat<uint, 2, 4> {
    return uMat(2, 4, ...args);
  }

  export function umat3(): mat<uint, 3, 3>

  export function umat3(scalar: number): mat<uint, 3, 3>

  export function umat3(...args: Tuple<number, Multiply<3, 3>>): mat<uint, 3, 3>

  export function umat3(v0: mat<uint, Rows, Cols>): mat<uint, 3, 3>

  export function umat3(...args: Tuple<vec<uint, 3>, 3>): mat<uint, 3, 3>

  export function umat3(...args: any[]): mat<uint, 3, 3> {
    return uMat(3, 3, ...args);
  }

  export function umat3x3(): mat<uint, 3, 3>

  export function umat3x3(scalar: number): mat<uint, 3, 3>

  export function umat3x3(...args: Tuple<number, Multiply<3, 3>>): mat<uint, 3, 3>

  export function umat3x3(v0: mat<uint, Rows, Cols>): mat<uint, 3, 3>

  export function umat3x3(...args: Tuple<vec<uint, 3>, 3>): mat<uint, 3, 3>

  export function umat3x3(...args: any[]): mat<uint, 3, 3> {
    return uMat(3, 3, ...args);
  }

  export function umat3x2(): mat<uint, 3, 2>

  export function umat3x2(scalar: number): mat<uint, 3, 2>

  export function umat3x2(...args: Tuple<number, Multiply<3, 2>>): mat<uint, 3, 2>

  export function umat3x2(v0: mat<uint, Rows, Cols>): mat<uint, 3, 2>

  export function umat3x2(...args: Tuple<vec<uint, 2>, 3>): mat<uint, 3, 2>

  export function umat3x2(...args: any[]): mat<uint, 3, 2> {
    return uMat(3, 2, ...args);
  }

  export function umat3x4(): mat<uint, 3, 4>

  export function umat3x4(scalar: number): mat<uint, 3, 4>

  export function umat3x4(...args: Tuple<number, Multiply<3, 4>>): mat<uint, 3, 4>

  export function umat3x4(v0: mat<uint, Rows, Cols>): mat<uint, 3, 4>

  export function umat3x4(...args: Tuple<vec<uint, 4>, 3>): mat<uint, 3, 4>

  export function umat3x4(...args: any[]): mat<uint, 3, 4> {
    return uMat(3, 4, ...args);
  }

  export function umat4(): mat<uint, 4, 4>

  export function umat4(scalar: number): mat<uint, 4, 4>

  export function umat4(...args: Tuple<number, Multiply<4, 4>>): mat<uint, 4, 4>

  export function umat4(v0: mat<uint, Rows, Cols>): mat<uint, 4, 4>

  export function umat4(...args: Tuple<vec<uint, 4>, 4>): mat<uint, 4, 4>

  export function umat4(...args: any[]): mat<uint, 4, 4> {
    return uMat(4, 4, ...args);
  }

  export function umat4x4(): mat<uint, 4, 4>

  export function umat4x4(scalar: number): mat<uint, 4, 4>

  export function umat4x4(...args: Tuple<number, Multiply<4, 4>>): mat<uint, 4, 4>

  export function umat4x4(v0: mat<uint, Rows, Cols>): mat<uint, 4, 4>

  export function umat4x4(...args: Tuple<vec<uint, 4>, 4>): mat<uint, 4, 4>

  export function umat4x4(...args: any[]): mat<uint, 4, 4> {
    return uMat(4, 4, ...args);
  }

  export function umat4x3(): mat<uint, 4, 3>

  export function umat4x3(scalar: number): mat<uint, 4, 3>

  export function umat4x3(...args: Tuple<number, Multiply<4, 3>>): mat<uint, 4, 3>

  export function umat4x3(v0: mat<uint, Rows, Cols>): mat<uint, 4, 3>

  export function umat4x3(...args: Tuple<vec<uint, 3>, 4>): mat<uint, 4, 3>

  export function umat4x3(...args: any[]): mat<uint, 4, 3> {
    return uMat(4, 3, ...args);
  }

  export function umat4x2(): mat<uint, 4, 2>

  export function umat4x2(scalar: number): mat<uint, 4, 2>

  export function umat4x2(...args: Tuple<number, Multiply<4, 2>>): mat<uint, 4, 2>

  export function umat4x2(v0: mat<uint, Rows, Cols>): mat<uint, 4, 2>

  export function umat4x2(...args: Tuple<vec<uint, 2>, 4>): mat<uint, 4, 2>

  export function umat4x2(...args: any[]): mat<uint, 4, 2> {
    return uMat(4, 2, ...args);
  }

  export function dmat2(): mat<double, 2, 2>

  export function dmat2(scalar: number): mat<double, 2, 2>

  export function dmat2(...args: Tuple<number, Multiply<2, 2>>): mat<double, 2, 2>

  export function dmat2(v0: mat<double, Rows, Cols>): mat<double, 2, 2>

  export function dmat2(...args: Tuple<vec<double, 2>, 2>): mat<double, 2, 2>

  export function dmat2(...args: any[]): mat<double, 2, 2> {
    return dMat(2, 2, ...args);
  }

  export function dmat2x2(): mat<double, 2, 2>

  export function dmat2x2(scalar: number): mat<double, 2, 2>

  export function dmat2x2(...args: Tuple<number, Multiply<2, 2>>): mat<double, 2, 2>

  export function dmat2x2(v0: mat<double, Rows, Cols>): mat<double, 2, 2>

  export function dmat2x2(...args: Tuple<vec<double, 2>, 2>): mat<double, 2, 2>

  export function dmat2x2(...args: any[]): mat<double, 2, 2> {
    return dMat(2, 2, ...args);
  }

  export function dmat2x3(): mat<double, 2, 3>

  export function dmat2x3(scalar: number): mat<double, 2, 3>

  export function dmat2x3(...args: Tuple<number, Multiply<2, 3>>): mat<double, 2, 3>

  export function dmat2x3(v0: mat<double, Rows, Cols>): mat<double, 2, 3>

  export function dmat2x3(...args: Tuple<vec<double, 3>, 2>): mat<double, 2, 3>

  export function dmat2x3(...args: any[]): mat<double, 2, 3> {
    return dMat(2, 3, ...args);
  }

  export function dmat2x4(): mat<double, 2, 4>

  export function dmat2x4(scalar: number): mat<double, 2, 4>

  export function dmat2x4(...args: Tuple<number, Multiply<2, 4>>): mat<double, 2, 4>

  export function dmat2x4(v0: mat<double, Rows, Cols>): mat<double, 2, 4>

  export function dmat2x4(...args: Tuple<vec<double, 3>, 2>): mat<double, 2, 4>

  export function dmat2x4(...args: any[]): mat<double, 2, 4> {
    return dMat(2, 4, ...args);
  }

  export function dmat3(): mat<double, 3, 3>

  export function dmat3(scalar: number): mat<double, 3, 3>

  export function dmat3(...args: Tuple<number, Multiply<3, 3>>): mat<double, 3, 3>

  export function dmat3(v0: mat<double, Rows, Cols>): mat<double, 3, 3>

  export function dmat3(...args: Tuple<vec<double, 3>, 3>): mat<double, 3, 3>

  export function dmat3(...args: any[]): mat<double, 3, 3> {
    return dMat(3, 3, ...args);
  }

  export function dmat3x3(): mat<double, 3, 3>

  export function dmat3x3(scalar: number): mat<double, 3, 3>

  export function dmat3x3(...args: Tuple<number, Multiply<3, 3>>): mat<double, 3, 3>

  export function dmat3x3(v0: mat<double, Rows, Cols>): mat<double, 3, 3>

  export function dmat3x3(...args: Tuple<vec<double, 3>, 3>): mat<double, 3, 3>

  export function dmat3x3(...args: any[]): mat<double, 3, 3> {
    return dMat(3, 3, ...args);
  }

  export function dmat3x2(): mat<double, 3, 2>

  export function dmat3x2(scalar: number): mat<double, 3, 2>

  export function dmat3x2(...args: Tuple<number, Multiply<3, 2>>): mat<double, 3, 2>

  export function dmat3x2(v0: mat<double, Rows, Cols>): mat<double, 3, 2>

  export function dmat3x2(...args: Tuple<vec<double, 2>, 3>): mat<double, 3, 2>

  export function dmat3x2(...args: any[]): mat<double, 3, 2> {
    return dMat(3, 2, ...args);
  }

  export function dmat3x4(): mat<double, 3, 4>

  export function dmat3x4(scalar: number): mat<double, 3, 4>

  export function dmat3x4(...args: Tuple<number, Multiply<3, 4>>): mat<double, 3, 4>

  export function dmat3x4(v0: mat<double, Rows, Cols>): mat<double, 3, 4>

  export function dmat3x4(...args: Tuple<vec<double, 4>, 3>): mat<double, 3, 4>

  export function dmat3x4(...args: any[]): mat<double, 3, 4> {
    return dMat(3, 4, ...args);
  }

  export function dmat4(): mat<double, 4, 4>

  export function dmat4(scalar: number): mat<double, 4, 4>

  export function dmat4(...args: Tuple<number, Multiply<4, 4>>): mat<double, 4, 4>

  export function dmat4(v0: mat<double, Rows, Cols>): mat<double, 4, 4>

  export function dmat4(...args: Tuple<vec<double, 4>, 4>): mat<double, 4, 4>

  export function dmat4(...args: any[]): mat<double, 4, 4> {
    return dMat(4, 4, ...args);
  }

  export function dmat4x4(): mat<double, 4, 4>

  export function dmat4x4(scalar: number): mat<double, 4, 4>

  export function dmat4x4(...args: Tuple<number, Multiply<4, 4>>): mat<double, 4, 4>

  export function dmat4x4(v0: mat<double, Rows, Cols>): mat<double, 4, 4>

  export function dmat4x4(...args: Tuple<vec<double, 4>, 4>): mat<double, 4, 4>

  export function dmat4x4(...args: any[]): mat<double, 4, 4> {
    return dMat(4, 4, ...args);
  }

  export function dmat4x3(): mat<double, 4, 3>

  export function dmat4x3(scalar: number): mat<double, 4, 3>

  export function dmat4x3(...args: Tuple<number, Multiply<4, 3>>): mat<double, 4, 3>

  export function dmat4x3(v0: mat<double, Rows, Cols>): mat<double, 4, 3>

  export function dmat4x3(...args: Tuple<vec<double, 3>, 4>): mat<double, 4, 3>

  export function dmat4x3(...args: any[]): mat<double, 4, 3> {
    return dMat(4, 3, ...args);
  }

  export function dmat4x2(): mat<double, 4, 2>

  export function dmat4x2(scalar: number): mat<double, 4, 2>

  export function dmat4x2(...args: Tuple<number, Multiply<4, 2>>): mat<double, 4, 2>

  export function dmat4x2(v0: mat<double, Rows, Cols>): mat<double, 4, 2>

  export function dmat4x2(...args: Tuple<vec<double, 2>, 4>): mat<double, 4, 2>

  export function dmat4x2(...args: any[]): mat<double, 4, 2> {
    return dMat(4, 2, ...args);
  }

}

// mul(glm.vec2(), glm.vec2())
// mul(glm.mat2(), glm.vec2())
// mul(glm.vec4(), glm.mat3())


// let vec1 = glm.vec1()
// let vec2 = glm.vec2([1, 2])
