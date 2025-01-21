import { Cols, Rows, TypeConstructor, valuetype } from "./common";
import { VecBase } from "./vec";



export interface mat<T extends valuetype, R extends Rows, C extends Cols> {
    elements: T;
    rows: R;
    cols: C;

    clone(): mat<T, R, C>;
    get determinant(): number;
    get adjugate(): mat<T, R, C>
    get inverse(): mat<T, R, C>
    get transpose(): mat<T, C, R>;


    mul<R1 extends Rows>(m: mat<T, R1, R>): mat<T, R1, C>;
    add(m: mat<T, R, C>): mat<T, R, C>;
    sub(m: mat<T, R, C>): mat<T, R, C>;
    div(m: mat<T, R, R>): mat<T, R, C>;

}

// export type mat<T extends valuetype, R extends Rows, C extends Cols> = tmat<T, R, C>;

export class MatBase<T extends valuetype, R extends Rows, C extends Cols> implements mat<T, R, C> {
    readonly elements: T;
    readonly rows: R;
    readonly cols: C;


    constructor(row: R, col: C, type: TypeConstructor<T>, ...data: any[]) {
        this.rows = row;
        this.cols = col;
        const size = row * col;
        let v0 = data[0];


        this.elements = new type(size);

        if (v0 && v0.constructor == type && v0.length == size) {
            this.elements = v0;
            return;
        }

        //mat2()
        if (data.length == 0) {
            return;
        }

        if (typeof v0 === 'number') {
            //标准矩阵mat(1)
            if (data.length == 1) {
                let t = Math.min(row, col);
                for (let i = 0; i < t; i++) {
                    this.elements[col * i + i] = v0;
                }
            } else {
                //不定数组mat2(1,2,3,4)
                this.elements.set(data);
            }
        } else if (Array.isArray(v0)) { //mat2([1,2,3,4])
            this.elements.set(v0);
        } else if (v0 instanceof MatBase) { //mat3(mat2)
            for (let i = 0; i < v0.rows; i++) {
                for (let j = 0; j < v0.cols; j++) {
                    this.elements[this.cols * i + j] = v0.elements[v0.cols * i + j];
                }
            }
        } else if (v0 instanceof VecBase) { //mat3(vec3,vec3,vec3)
            for (let i = 0; i < data.length; i++) {
                for (let j = 0; j < this.cols; j++) {
                    this.elements[this.cols * i + j] = data[i].elements[j];
                }
            }
        } else {
            throw Error("invalid argument");
        }

    }

    static createNew<T extends valuetype, R extends Rows, C extends Cols>(m: mat<T, R, C>, data: T): mat<T, R, C> {
        let t = m as MatBase<T, R, C>;
        return new MatBase(t.rows, t.cols, t.elements.constructor as TypeConstructor<T>, data);
    }

    clone(): mat<T, R, C> {
        return new MatBase(this.rows, this.cols, this.elements.constructor as TypeConstructor<T>, (this.elements.constructor as TypeConstructor<T>).from(this.elements));
    }

    get determinant(): number {
        if (this.rows as number != this.cols) {
            throw new Error("Determinant can only be calculated for square matrices.");
        }

        //return this.calculateDeterminant(this.elements, this.rows);
        switch (this.cols) {
            case 2:
                return determinant2x2(this.elements);
            case 3:
                return determinant3x3(this.elements);
            case 4:
                return determinant4x4(this.elements);
            default:
                throw new Error("Determinant can only be calculated for 2x2, 3x3 and 4x4 matrices.");
        }

    }

    get transpose(): mat<T, C, R> {
        const result = new MatBase(this.cols, this.rows, this.elements.constructor as TypeConstructor<T>);
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                result.elements[j * this.rows + i] = this.elements[i * this.cols + j];
            }
        }
        return result
    }


    get adjugate(): mat<T, R, C> {
        return new MatBase(this.rows, this.cols, this.elements.constructor as TypeConstructor<T>, this.adjugate2());
    }

    private adjugate2(): T {
        if (this.rows as number !== this.cols) {
            throw new Error("Adjugate can only be calculated for square matrices.");
        }

        switch (this.cols) {
            case 2:
                return adjoint2x2(this.elements);
            case 3:
                return adjoint3x3(this.elements);
            case 4:
                return adjoint4x4(this.elements);
        }

    }

    get inverse(): mat<T, R, C> {
        const det = this.determinant;
        if (det === 0) {
            throw new Error("Matrix is singular and cannot be inverted.");
        }

        const adjugateMatrix = this.adjugate2();
        const invDet = 1 / det;

        const size = Number(this.rows);
        const inverseMatrix = new (this.elements.constructor as TypeConstructor<T>)(size * size);

        for (let i = 0; i < size * size; i++) {
            inverseMatrix[i] = adjugateMatrix[i] * invDet;
        }

        return new MatBase(this.rows, this.cols, this.elements.constructor as TypeConstructor<T>, inverseMatrix);
    }

    private calculateDeterminant(elements: T, size: number): number {
        if (size === 2) {
            return elements[0] * elements[3] - elements[1] * elements[2];
        }

        let determinant = 0;
        for (let i = 0; i < size; i++) {
            const subMatrix = this.getSubMatrix(elements, size, 0, i);
            determinant += ((i % 2 === 0 ? 1 : -1) * elements[i] * this.calculateDeterminant(subMatrix, size - 1));
        }
        return determinant;
    }

    private getSubMatrix(elements: T, size: number, row: number, col: number): T {
        const subMatrix = new (elements.constructor as TypeConstructor<T>)(size * size - 1);
        let subMatrixIndex = 0;
        for (let i = 0; i < size; i++) {
            if (i === row) continue;
            for (let j = 0; j < size; j++) {
                if (j === col) continue;
                subMatrix[subMatrixIndex++] = elements[size * i + j];
            }
        }
        return subMatrix;
    }

    mul<R1 extends Rows>(m: mat<T, R1, R>): mat<T, R1, C> {
        if (this.rows !== m.cols) {
            throw new Error("Matrix multiplication is not possible: columns of the first matrix must match rows of the second matrix.");
        }

        const result = new MatBase(m.rows, this.cols, this.elements.constructor as TypeConstructor<T>);
        for (let i = 0; i < m.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                let sum = 0;
                for (let k = 0; k < this.rows; k++) {
                    sum += m.elements[i * m.cols + k] * this.elements[k * this.cols + j];
                }
                result.elements[i * this.cols + j] = sum;
            }
        }
        return result;
    }

    add(m: mat<T, R, C>): mat<T, R, C> {
        if (this.rows !== m.rows || this.cols !== m.cols) {
            throw new Error("Matrix addition is not possible: matrices must have the same dimensions.");
        }
        const result = this.clone();
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                result.elements[i * this.cols + j] = this.elements[i * this.cols + j] + m.elements[i * this.cols + j];
            }
        }
        return result;

    }

    sub(m: mat<T, R, C>): mat<T, R, C> {
        if (this.rows !== m.rows || this.cols !== m.cols) {
            throw new Error("Matrix subtraction is not possible: matrices must have the same dimensions.");
        }
        const result = this.clone();
        for (let i = 0; i < this.rows; i++) {
            for (let j = 0; j < this.cols; j++) {
                result.elements[i * this.cols + j] = this.elements[i * this.cols + j] - m.elements[i * this.cols + j];
            }
        }
        return result;
    }

    div(m: mat<T, R, R>): mat<T, R, C> {
        return this.mul(m.inverse);
    }

    toString(): string {
        return this.elements.toString();
    }

}


function determinant2x2(matrix: valuetype): number {
    return matrix[0] * matrix[3] - matrix[1] * matrix[2];
}

// 计算 3x3 矩阵的行列式
function determinant3x3(matrix: valuetype, offset: number = 0): number {
    return matrix[0 + offset] * (matrix[4 + offset] * matrix[8 + offset] - matrix[5 + offset] * matrix[7 + offset])
        - matrix[1 + offset] * (matrix[3 + offset] * matrix[8 + offset] - matrix[5 + offset] * matrix[6 + offset])
        + matrix[2 + offset] * (matrix[3 + offset] * matrix[7 + offset] - matrix[4 + offset] * matrix[6 + offset]);
}

// 计算 4x4 矩阵的行列式（拉普拉斯展开）
function determinant4x4(matrix: valuetype) {
    let det = 0;
    // 按第一行展开
    det += matrix[0] * determinant3x3(matrix, 5);
    det -= matrix[1] * determinant3x3(matrix, 6);
    det += matrix[2] * determinant3x3(matrix, 7);
    det -= matrix[3] * determinant3x3(matrix, 8);
    return det;
}



// 计算 2x2 矩阵的伴随矩阵
function adjoint2x2<T extends valuetype>(matrix: T) {
    let adjoint = new (matrix.constructor as TypeConstructor<T>)(matrix.length);

    adjoint[0] = matrix[3];
    adjoint[1] = -matrix[1];
    adjoint[2] = -matrix[2];
    adjoint[3] = matrix[0];
    return adjoint;
}

// 计算 3x3 矩阵的伴随矩阵
function adjoint3x3<T extends valuetype>(matrix: valuetype) {
    let adjoint = new (matrix.constructor as TypeConstructor<T>)(matrix.length);

    adjoint[0] = matrix[4] * matrix[8] - matrix[5] * matrix[7];
    adjoint[1] = -(matrix[3] * matrix[8] - matrix[5] * matrix[6]);
    adjoint[2] = matrix[3] * matrix[7] - matrix[4] * matrix[6];
    adjoint[3] = -(matrix[1] * matrix[8] - matrix[2] * matrix[7]);
    adjoint[4] = matrix[0] * matrix[8] - matrix[2] * matrix[6];
    adjoint[5] = -(matrix[0] * matrix[7] - matrix[1] * matrix[6]);
    adjoint[6] = matrix[1] * matrix[5] - matrix[2] * matrix[4];
    adjoint[7] = -(matrix[0] * matrix[5] - matrix[2] * matrix[3]);
    adjoint[8] = matrix[0] * matrix[4] - matrix[1] * matrix[3];
    return adjoint;
}


function adjoint4x4<T extends valuetype>(matrix: T) {
    let adjoint = new (matrix.constructor as TypeConstructor<T>)(matrix.length);

    let submatrix = new (matrix.constructor as TypeConstructor<T>)(9);
    for (let i = 0; i < 4; ++i) {
        for (let j = 0; j < 4; ++j) {

            let index = 0;
            for (let m = 0; m < 4; ++m) {
                if (m == i) continue;
                for (let n = 0; n < 4; ++n) {
                    if (n == j) continue;
                    submatrix[index++] = matrix[m * 4 + n];
                }
            }
            adjoint[j * 4 + i] = Math.pow(-1, i + j) * determinant3x3(submatrix);
        }
    }
    return adjoint;
}

