import { double, float, int, TypeConstructor, uint, valuetype, VecSize } from './common';
import { BaseMat,  Cols,  mat, Mat2, Mat3, Mat4, Rows } from './mat';
import { mul } from './operation';
import { vec, VecBase, } from './vec';

export namespace glm {
  export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize, constructor: TypeConstructor<TType>, ...args: object[]) {
    return new VecBase(size, constructor, args);
  }

  export function vec1(...args: object[]): vec<float, 1> {
    return Vec(1, Float32Array, args);
  }

  export function vec2(...args: object[]): vec<float, 2> {
    return new Vec2(Float32Array, args);
  }

  export function vec3(...args: object[]): vec<float, 3> {
    return new Vec3(Float32Array, args);
  }

  export function vec4(...args: object[]): vec<float, 4> {
    return new Vec4(Float32Array, args);
  }

  export function ivec1(...args: object[]): vec<int, 1> {
    return new Vec1(Int32Array, args);
  }

  export function ivec2(...args: object[]): vec<int, 2> {
    return new Vec2(Int32Array, args);
  }

  export function ivec3(...args: object[]): vec<int, 3> {
    return new Vec3(Int32Array, args);
  }

  export function ivec4(...args: object[]): vec<int, 4> {
    return new Vec4(Int32Array, args);
  }

  export function uvec1(...args: object[]): vec<uint, 1> {
    return new Vec1(Uint32Array, args)
  }

  export function uvec2(...args: object[]): vec<uint, 2> {
    return new Vec2(Uint32Array, args);
  }

  export function uvec3(...args: object[]): vec<uint, 3> {
    return new Vec3(Uint32Array, args);
  }

  export function uvec4(...args: object[]): vec<uint, 4> {
    return new Vec4(Uint32Array, args);
  }

  export function dvec1(...args: object[]): vec<double, 1> {
    return new Vec1(Float64Array, args)
  }

  export function dvec2(...args: object[]): vec<double, 2> {
    return new Vec2(Float64Array, args);
  }

  export function dvec3(...args: object[]): vec<double, 3> {
    return new Vec3(Float64Array, args);
  }

  export function dvec4(...args: object[]): vec<double, 4> {
    return new Vec4(Float64Array, args);
  }

  export function mat2(...args: object[]): mat<float, 2, 2> {
    return new Mat2(Float32Array, args);
  }

  export function mat3(...args: object[]): mat<float, 3, 3> {
    return new Mat3(Float32Array, args);
  }

  export function mat4(...args: object[]): mat<float, 4, 4> {
    return new Mat4(Float32Array, args);
  }

  export function dmat2(...args: object[]): mat<double, 2, 2> {
    return new Mat2(Float64Array, args);
  }

  export function dmat3(...args: object[]): mat<double, 3, 3> {
    return new Mat3(Float64Array, args);
  }

  export function dmat4(...args: object[]): mat<double, 4, 4> {
    return new Mat4(Float64Array, args);
  }

  export function Mat<TR extends Rows, TC extends Cols, TType extends valuetype>(row: TR, col: TC,
    constructor: TypeConstructor<TType>,
    ...args: number[]): mat<TType, TR, TC> {
    return new BaseMat(row, col, args, constructor);
  }
}

mul(glm.vec2(), glm.vec2())
mul(glm.mat2(), glm.vec2())
mul(glm.vec4(), glm.mat3())
