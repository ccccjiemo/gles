import {
    double,
    float,
    int,
    TypeConstructor,
    uint,
    valuetype,
    VecSize,
    Rows,
    Cols,
} from './common';
import { BaseMat, mat, } from './mat';
import { vec, VecBase, } from './vec';

const d1 = Math.PI / 180;
const d2 = 180 / Math.PI;


type Operand<T extends valuetype, S extends VecSize, R extends Rows, C extends Cols> = vec<T, S> | mat<T, R, C>;


function rotationMatrix<T extends valuetype>(m: mat<T, 4, 4>, angle: number, axis: vec<T, 3>): mat<T, 4, 4> {
    const c = Math.cos(angle);
    const s = Math.sin(angle);

    const normalizedAxis = glm.normalize(axis);
    const temp = normalizedAxis.mul(1 - c);

    // Build rotation matrix according to GLM implementation
    const matrix = [
        c + temp.x * normalizedAxis.x, temp.x * normalizedAxis.y - s * normalizedAxis.z, temp.x * normalizedAxis.z + s * normalizedAxis.y, 0,
        temp.y * normalizedAxis.x + s * normalizedAxis.z, c + temp.y * normalizedAxis.y, temp.y * normalizedAxis.z - s * normalizedAxis.x, 0,
        temp.z * normalizedAxis.x - s * normalizedAxis.y, temp.z * normalizedAxis.y + s * normalizedAxis.x, c + temp.z * normalizedAxis.z, 0,
        0, 0, 0, 1
    ];

    return new BaseMat(4, 4, m.elements.constructor as TypeConstructor<T>, matrix);
}

export namespace glm {
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

    export function translate<T extends valuetype>(m: mat<T, 4, 4>, v: vec<T, 3>): mat<T, 4, 4> {
        let result = m.clone();

        result.elements[12] = m.elements[0] * v.x + m.elements[4] * v.y + m.elements[8] * v.z + m.elements[12];
        result.elements[13] = m.elements[1] * v.x + m.elements[5] * v.y + m.elements[9] * v.z + m.elements[13];
        result.elements[14] = m.elements[2] * v.x + m.elements[6] * v.y + m.elements[10] * v.z + m.elements[14];
        result.elements[15] = m.elements[3] * v.x + m.elements[7] * v.y + m.elements[11] * v.z + m.elements[15];

        return result;
    }

    export function scale<T extends valuetype>(m: mat<T, 4, 4>, v: vec<T, 3>): mat<T, 4, 4> {
        let result = (m as BaseMat<T, 4, 4>).clone();
        result.elements[0] *= v.x;
        result.elements[5] *= v.y;
        result.elements[10] *= v.z;
        return result;
    }

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

    export function inverse<T extends valuetype, R extends Rows, C extends Cols>(m: mat<T, R, C>): mat<T, R, C> {
        return m.inverse;
    }

    export function rotate<T extends valuetype>(m: mat<T, 4, 4>, angle: number, axis: vec<T, 3>): mat<T, 4, 4> {
        if (axis.length <= 0) {
            return m.clone();
        }

        const rotMat = rotationMatrix(m, angle, axis);

        // Perform the multiplication as per GLM implementation
        const result = m.clone();
        result.elements[0] = m.elements[0] * rotMat.elements[0] + m.elements[4] * rotMat.elements[1] + m.elements[8] * rotMat.elements[2];
        result.elements[4] = m.elements[0] * rotMat.elements[4] + m.elements[4] * rotMat.elements[5] + m.elements[8] * rotMat.elements[6];
        result.elements[8] = m.elements[0] * rotMat.elements[8] + m.elements[4] * rotMat.elements[9] + m.elements[8] * rotMat.elements[10];

        result.elements[1] = m.elements[1] * rotMat.elements[0] + m.elements[5] * rotMat.elements[1] + m.elements[9] * rotMat.elements[2];
        result.elements[5] = m.elements[1] * rotMat.elements[4] + m.elements[5] * rotMat.elements[5] + m.elements[9] * rotMat.elements[6];
        result.elements[9] = m.elements[1] * rotMat.elements[8] + m.elements[5] * rotMat.elements[9] + m.elements[9] * rotMat.elements[10];

        result.elements[2] = m.elements[2] * rotMat.elements[0] + m.elements[6] * rotMat.elements[1] + m.elements[10] * rotMat.elements[2];
        result.elements[6] = m.elements[2] * rotMat.elements[4] + m.elements[6] * rotMat.elements[5] + m.elements[10] * rotMat.elements[6];
        result.elements[10] = m.elements[2] * rotMat.elements[8] + m.elements[6] * rotMat.elements[9] + m.elements[10] * rotMat.elements[10];

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

    export function ortho<T extends valuetype>(constructor: TypeConstructor<T>, left: number, right: number, bottom: number, top: number, near: number, far: number): mat<T, 4, 4> {
        let result = new BaseMat(4, 4, constructor);
        result.elements[0] = 2 / (right - left);
        result.elements[5] = 2 / (top - bottom);
        result.elements[10] = -2 / (far - near);
        result.elements[12] = -(right + left) / (right - left);
        result.elements[13] = -(top + bottom) / (top - bottom);
        result.elements[14] = -(far + near) / (far - near);
        return result;

    }

    export function perspective<T extends valuetype>(constructor: TypeConstructor<T>, fovy: number, aspect: number, near: number, far: number): mat<T, 4, 4> {
        let tanHalfFovy = Math.tan(fovy / 2.0);
        let result = new BaseMat(4, 4, constructor);

        result.elements[0] = 1.0 / (aspect * tanHalfFovy);
        result.elements[5] = 1.0 / tanHalfFovy;
        result.elements[10] = -(far + near) / (far - near);
        result.elements[11] = -1.0;
        result.elements[14] = -(2.0 * far * near) / (far - near);
        return result;
    }

    export function dot<T extends valuetype, TSize extends VecSize>(v0: vec<T, TSize>, v1: vec<T, TSize>): number {
        let result = 0;
        for (let i = 0; i < v0.size; i++) {
            result += v0.elements[i] * v1.elements[i];
        }
        return result;
    }

    export function cross<T extends valuetype>(v0: vec<T, 3>, v1: vec<T, 3>): vec<T, 3> {
        let result = v0.clone();
        result.x = v0.y * v1.z - v0.z * v1.y;
        result.y = v0.z * v1.x - v0.x * v1.z;
        result.z = v0.x * v1.y - v0.y * v1.x;
        return result;
    }

    export function length(v: vec<valuetype, any>): number {
        return v.length;
    }

    export function abs<T extends valuetype, S extends VecSize>(v: vec<T, S>): vec<T, S> {
        let result = v.clone();
        for (let i = 0; i < v.size; i++) {
            result.elements[i] = Math.abs(v.elements[i]);
        }
        return result;
    }

    export function transpose<T extends valuetype, R extends Rows, C extends Cols>(m: mat<T, R, C>): mat<T, C, R> {
        return m.transpose;
    }

    export function Vec<TSize extends VecSize, TType extends valuetype>(size: TSize, constructor: TypeConstructor<TType>,
        ...args: any[]): vec<TType, TSize> {
        return new VecBase(size, constructor, ...args);
    }


    export function vec1(...args: any[]): vec<float, 1> {
        return Vec(1, Float32Array, ...args);
    }

    export function vec2(...args: any[]): vec<float, 2> {
        return Vec(2, Float32Array, ...args);
    }

    export function vec3(...args: any[]): vec<float, 3> {
        return Vec(3, Float32Array, ...args);
    }

    export function vec4(...args: any[]): vec<float, 4> {
        return Vec(4, Float32Array, ...args);
    }

    export function ivec1(...args: any[]): vec<int, 1> {
        return Vec(1, Int32Array, ...args);
    }

    export function ivec2(...args: any[]): vec<int, 2> {
        return Vec(2, Int32Array, ...args);
    }

    export function ivec3(...args: any[]): vec<int, 3> {
        return Vec(3, Int32Array, ...args);

    }

    export function ivec4(...args: any[]): vec<int, 4> {
        return Vec(4, Int32Array, ...args);
    }


    export function uvec1(...args: any[]): vec<uint, 1> {
        return Vec(1, Uint32Array, ...args);
    }

    export function uvec2(...args: any[]): vec<uint, 2> {
        return Vec(2, Uint32Array, ...args);
    }

    export function uvec3(...args: any[]): vec<uint, 3> {
        return Vec(3, Uint32Array, ...args);
    }

    export function uvec4(...args: any[]): vec<uint, 4> {
        return Vec(4, Uint32Array, ...args);
    }

    export function dvec1(...args: any[]): vec<double, 1> {
        return Vec(1, Float64Array, ...args);
    }

    export function dvec2(...args: any[]): vec<double, 2> {
        return Vec(2, Float64Array, ...args);
    }

    export function dvec3(...args: any[]): vec<double, 3> {
        return Vec(3, Float64Array, ...args);
    }

    export function dvec4(...args: any[]): vec<double, 4> {
        return Vec(4, Float64Array, ...args);
    }

    export function Mat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<float, TR, TC> {
        return new BaseMat(row, col, Float32Array, ...args);
    }

    export function dMat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<double, TR, TC> {
        return new BaseMat(row, col, Float64Array, ...args);
    }

    export function iMat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<int, TR, TC> {
        return new BaseMat(row, col, Int32Array, ...args);
    }

    export function uMat<TR extends Rows, TC extends Cols>(row: TR, col: TC, ...args: any[]): mat<uint, TR, TC> {
        return new BaseMat(row, col, Uint32Array, ...args);
    }


    export function mat2(...args: any[]): mat<float, 2, 2> {
        return Mat(2, 2, ...args);
    }

    export function mat2x2(...args: any[]): mat<float, 2, 2> {
        return Mat(2, 2, ...args);
    }



    export function mat2x3(...args: any[]): mat<float, 2, 3> {
        return Mat(2, 3, ...args);
    }



    export function mat2x4(...args: any[]): mat<float, 2, 4> {
        return Mat(2, 4, ...args);
    }



    export function mat3(...args: any[]): mat<float, 3, 3> {
        return Mat(3, 3, ...args);
    }



    export function mat3x3(...args: any[]): mat<float, 3, 3> {
        return Mat(3, 3, ...args);
    }



    export function mat3x2(...args: any[]): mat<float, 3, 2> {
        return Mat(3, 2, ...args);
    }



    export function mat3x4(...args: any[]): mat<float, 3, 4> {
        return Mat(3, 4, ...args);
    }



    export function mat4(...args: any[]): mat<float, 4, 4> {
        return Mat(4, 4, ...args);
    }



    export function mat4x4(...args: any[]): mat<float, 4, 4> {
        return Mat(4, 4, ...args);
    }



    export function mat4x3(...args: any[]): mat<float, 4, 3> {
        return Mat(4, 3, ...args);
    }



    export function mat4x2(...args: any[]): mat<float, 4, 2> {
        return Mat(4, 2, ...args);
    }



    export function imat2(...args: any[]): mat<int, 2, 2> {
        return iMat(2, 2, ...args);
    }



    export function imat2x2(...args: any[]): mat<int, 2, 2> {
        return iMat(2, 2, ...args);
    }



    export function imat2x3(...args: any[]): mat<int, 2, 3> {
        return iMat(2, 3, ...args);
    }



    export function imat2x4(...args: any[]): mat<int, 2, 4> {
        return iMat(2, 4, ...args);
    }



    export function imat3(...args: any[]): mat<int, 3, 3> {
        return iMat(3, 3, ...args);
    }



    export function imat3x3(...args: any[]): mat<int, 3, 3> {
        return iMat(3, 3, ...args);
    }



    export function imat3x2(...args: any[]): mat<int, 3, 2> {
        return iMat(3, 2, ...args);
    }



    export function imat3x4(...args: any[]): mat<int, 3, 4> {
        return iMat(3, 4, ...args);
    }



    export function imat4(...args: any[]): mat<int, 4, 4> {
        return iMat(4, 4, ...args);
    }



    export function imat4x4(...args: any[]): mat<int, 4, 4> {
        return iMat(4, 4, ...args);
    }



    export function imat4x3(...args: any[]): mat<int, 4, 3> {
        return iMat(4, 3, ...args);
    }



    export function imat4x2(...args: any[]): mat<int, 4, 2> {
        return iMat(4, 2, ...args);
    }



    export function umat2(...args: any[]): mat<uint, 2, 2> {
        return uMat(2, 2, ...args);
    }



    export function umat2x2(...args: any[]): mat<uint, 2, 2> {
        return uMat(2, 2, ...args);
    }



    export function umat2x3(...args: any[]): mat<uint, 2, 3> {
        return uMat(2, 3, ...args);
    }



    export function umat2x4(...args: any[]): mat<uint, 2, 4> {
        return uMat(2, 4, ...args);
    }



    export function umat3(...args: any[]): mat<uint, 3, 3> {
        return uMat(3, 3, ...args);
    }



    export function umat3x3(...args: any[]): mat<uint, 3, 3> {
        return uMat(3, 3, ...args);
    }



    export function umat3x2(...args: any[]): mat<uint, 3, 2> {
        return uMat(3, 2, ...args);
    }


    export function umat3x4(...args: any[]): mat<uint, 3, 4> {
        return uMat(3, 4, ...args);
    }



    export function umat4(...args: any[]): mat<uint, 4, 4> {
        return uMat(4, 4, ...args);
    }



    export function umat4x4(...args: any[]): mat<uint, 4, 4> {
        return uMat(4, 4, ...args);
    }



    export function umat4x3(...args: any[]): mat<uint, 4, 3> {
        return uMat(4, 3, ...args);
    }



    export function umat4x2(...args: any[]): mat<uint, 4, 2> {
        return uMat(4, 2, ...args);
    }



    export function dmat2(...args: any[]): mat<double, 2, 2> {
        return dMat(2, 2, ...args);
    }



    export function dmat2x2(...args: any[]): mat<double, 2, 2> {
        return dMat(2, 2, ...args);
    }



    export function dmat2x3(...args: any[]): mat<double, 2, 3> {
        return dMat(2, 3, ...args);
    }



    export function dmat2x4(...args: any[]): mat<double, 2, 4> {
        return dMat(2, 4, ...args);
    }



    export function dmat3(...args: any[]): mat<double, 3, 3> {
        return dMat(3, 3, ...args);
    }



    export function dmat3x3(...args: any[]): mat<double, 3, 3> {
        return dMat(3, 3, ...args);
    }



    export function dmat3x2(...args: any[]): mat<double, 3, 2> {
        return dMat(3, 2, ...args);
    }



    export function dmat3x4(...args: any[]): mat<double, 3, 4> {
        return dMat(3, 4, ...args);
    }



    export function dmat4(...args: any[]): mat<double, 4, 4> {
        return dMat(4, 4, ...args);
    }



    export function dmat4x4(...args: any[]): mat<double, 4, 4> {
        return dMat(4, 4, ...args);
    }



    export function dmat4x3(...args: any[]): mat<double, 4, 3> {
        return dMat(4, 3, ...args);
    }


    export function dmat4x2(...args: any[]): mat<double, 4, 2> {
        return dMat(4, 2, ...args);
    }

}

// mul(glm.vec2(), glm.vec2())
// mul(glm.mat2(), glm.vec2())
// mul(glm.vec4(), glm.mat3())


// let vec1 = glm.vec1()
// let vec2 = glm.vec2([1, 2])
