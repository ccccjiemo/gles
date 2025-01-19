import { Cols, float, GE,  Range, Rows, TypeConstructor, valuetype } from "./common";
import { BaseMat, mat } from "./mat";

type VecSize = 1 | 2 | 3 | 4;





interface nvec<T extends valuetype, TSize extends VecSize> {
    readonly elements: T
    readonly size: TSize

    add(v: vec<T, TSize>): vec<T, TSize>
    sub(v: vec<T, TSize>): vec<T, TSize>

    mul(v: number): vec<T, TSize>
    mul(v: vec<T, TSize>): vec<T, TSize>
    mul<R extends Range<TSize, 2>, C extends Cols>(v: mat<T, R extends Rows ? R : never, C>): vec<T, C>
    div(v: vec<T, TSize>): vec<T, TSize>

    clone(): vec<T, TSize>

    get length(): number
}



export type vec<TType extends valuetype = float, TSize extends VecSize = 1> = nvec<TType, TSize> &
    (TSize extends 1 ? d1 : unknown) &
    (TSize extends 2 ? d2 : unknown) &
    (TSize extends 3 ? d3 : unknown) &
    (TSize extends 4 ? d4 : unknown);




interface d1 {
    get x(): number

    set x(value: number)

    get r(): number

    set r(value: number)

    get s(): number

    set s(value: number)
}

interface d2 extends d1 {
    get y(): number

    set y(value: number)

    get g(): number

    set g(value: number)

    get t(): number

    set t(value: number)

    get xy(): vec<any, 2>

    get rg(): vec<any, 2>

    get st(): vec<any, 2>

}

interface d3 extends d2 {
    get z(): number

    set z(value: number)

    get b(): number

    set b(value: number)

    get p(): number

    set p(value: number)

    get xyz(): vec<any, 3>

    get rgb(): vec<any, 3>

    get stp(): vec<any, 3>
}

interface d4 extends d3 {
    get w(): number

    set w(value: number)

    get a(): number

    set a(value: number)

    get q(): number

    set q(value: number)

}


export class VecBase<T extends valuetype, TSize extends VecSize> implements nvec<T, TSize>, d4 {
    readonly elements: T;
    readonly size: TSize;

    static createNew<T extends valuetype, TSize extends VecSize>(v: vec<T, TSize>, data: T): vec<T, TSize> {
        return new VecBase(v.size, v.elements.constructor as TypeConstructor<T>, data);
    }


    //constructor(size: TSize, type: TypeConstructor<T>)
    //constructor(size: TSize, type: TypeConstructor<T>, scalar: number)
    //constructor(size: TSize, type: TypeConstructor<T>, ...args: any[])
    //constructor(size: TSize, type: TypeConstructor<T>, data: Tuple<number, TSize>)

    constructor(size: TSize, type: TypeConstructor<T>, ...initialData: any[]) {
        this.size = size;
        let v0 = initialData[0];

        if (v0 && v0.constructor == type && v0.length == size) {
            this.elements = v0;
            return;
        }

        this.elements = new type(size);
        //constructor()
        if (initialData.length == 0) {
            return;
        }


        //vec3(vec1, 1,2)
        if (v0 instanceof VecBase) {
            this.elements.set(v0.elements);
            for (let i = 0; i < initialData.length - 1; i++) {
                this.elements[v0.size + i] = initialData[i + 1] as unknown as number;
            }
            return;
        }

        //vec3(1)
        if (typeof v0 == 'number' && initialData.length == 1) {
            this.elements.fill(v0);
            return;
        }

        //vec3([1,2,3])
        if (Array.isArray(v0)) {
            this.elements.set(v0);
            return;
        }

        //vec3(1,2,3)
        this.elements.set(initialData as unknown as number[])
    }

    clone(): vec<T, TSize> {
        return new VecBase(this.size, this.elements.constructor as TypeConstructor<T>, (this.elements.constructor as TypeConstructor<T>).from(this.elements));
    }


    get length(): number {
        let sum = 0;
        for (let i = 0; i < this.size; i++) {
            sum += this.elements[i] * this.elements[i];
        }
        return Math.sqrt(sum);
    }

    add(v: vec<T, TSize>): vec<T, TSize> {
        let result = this.clone();
        for (let i = 0; i < this.size; i++) {
            result.elements[i] += v.elements[i];
        }
        return result;
    }

    sub(v: vec<T, TSize>): vec<T, TSize> {
        let result = this.clone();
        for (let i = 0; i < this.size; i++) {
            result.elements[i] -= v.elements[i];
        }
        return result;
    }

    mul<R extends Rows, C extends Cols>(v: vec<T, TSize> | mat<T, GE<TSize extends 1 ? never : TSize, R>, C> | number): any {
        if (v instanceof VecBase) {
            let result = this.clone();
            for (let i = 0; i < this.size; i++) {
                result.elements[i] *= v.elements[i];
            }
            return result;
        }
        if (v instanceof BaseMat) {
            let result = new VecBase(v.cols, this.elements.constructor as TypeConstructor<T>);
            for (let i = 0; i < v.cols; i++) {
                let sum = 0;
                for (let j = 0; j < v.rows; j++) {
                    sum += this.elements[j] * v.elements[v.cols * j + i];
                }
                result.elements[i] = sum;
            }
            return result;
        }
        if (typeof v == 'number') {
            let result = this.clone();
            for (let i = 0; i < this.size; i++) {
                result.elements[i] *= v;
            }
            return result;
        }


    }



    div(v: vec<T, TSize>): vec<T, TSize> {
        let result = this.clone();
        for (let i = 0; i < this.size; i++) {
            result.elements[i] /= v.elements[i];
        }
        return result;
    }

    toString(): string {
        let result = `{ x: ${this.x}, r: ${this.r}, s: ${this.s}}\n`;
        if (this.size >= 2) {
            result += `{ y: ${this.y}, g: ${this.g}, t: ${this.t}}\n`;
        }
        if (this.size >= 3) {
            result += `{ z: ${this.z}, b: ${this.b}, p: ${this.p}}\n`;
        }
        if (this.size >= 4) {
            result += `{ w: ${this.w}, a: ${this.a}, q: ${this.q}}\n`;
        }
        return result;
    }
    get x(): number {
        return this.elements[0];
    }

    set x(value: number) {
        this.elements[0] = value;
    }

    get r(): number {
        return this.elements[0];
    }

    set r(value: number) {
        this.elements[0] = value;
    }

    get s(): number {
        return this.elements[0];
    }

    set s(value: number) {
        this.elements[0] = value;
    }

    get y(): number {
        return this.elements[1];
    }

    set y(value: number) {
        this.elements[1] = value;
    }

    get g(): number {
        return this.elements[1];
    }

    set g(value: number) {
        this.elements[1] = value;
    }

    get t(): number {
        return this.elements[1];
    }

    set t(value: number) {
        this.elements[1] = value;
    }

    get z(): number {
        return this.elements[2];
    }

    set z(value: number) {
        this.elements[2] = value;
    }

    get b(): number {
        return this.elements[2];
    }

    set b(value: number) {
        this.elements[2] = value;
    }

    get p(): number {
        return this.elements[2];
    }

    set p(value: number) {
        this.elements[2] = value;
    }

    get w(): number {
        return this.elements[3];
    }

    set w(value: number) {
        this.elements[3] = value;
    }

    get a(): number {
        return this.elements[3];
    }

    set a(value: number) {
        this.elements[3] = value;
    }

    get q(): number {
        return this.elements[3];
    }

    set q(value: number) {
        this.elements[3] = value;
    }

    get xyz(): vec<T, 3> {
        return new VecBase(3, this.elements.constructor as TypeConstructor<T>, this.elements.slice(0, 3))
    }

    get rgb(): vec<T, 3> {
        return this.xyz;
    }

    get stp(): vec<T, 3> {
        return this.xyz
    }

    get xy(): vec<T, 2> {
        return new VecBase(2, this.elements.constructor as TypeConstructor<T>, this.elements.slice(0, 2))
    }

    get rg(): vec<T, 2> {
        return this.xy;
    }

    get st(): vec<T, 2> {
        return this.xy;
    }
}

//
// export class Vec1<T extends valuetype> extends VecBase<T, 1> implements d1 {
//   constructor(type: TypeConstructor<T>, initialData: number[] | VecBase<T, 1>) {
//     super(1, type, initialData);
//   }
//
//   get x(): number {
//     return this.value[0];
//   }
//
//   set x(value: number) {
//     this.value[0] = value;
//   }
//
//   get r(): number {
//     return this.value[0];
//   }
//
//   set r(value: number) {
//     this.value[0] = value;
//   }
//
//   get s(): number {
//     return this.value[0];
//   }
//
//   set s(value: number) {
//     this.value[0] = value;
//   }
// }
//
// export class Vec2<T extends valuetype> extends VecBase<T, 2> implements d2 {
//   constructor(type: TypeConstructor<T>, initialData: number[] | VecBase<T, 2>) {
//     super(2, type, initialData);
//   }
//
//   get x(): number {
//     return this.value[0];
//   }
//
//   set x(value: number) {
//     this.value[0] = value;
//   }
//
//   get r(): number {
//     return this.value[0];
//   }
//
//   set r(value: number) {
//     this.value[0] = value;
//   }
//
//   get s(): number {
//     return this.value[0];
//   }
//
//   set s(value: number) {
//     this.value[0] = value;
//   }
//
//   get y(): number {
//     return this.value[1];
//   }
//
//   set y(value: number) {
//     this.value[1] = value;
//   }
//
//   get g(): number {
//     return this.value[1];
//   }
//
//   set g(value: number) {
//     this.value[1] = value;
//   }
//
//   get t(): number {
//     return this.value[1];
//   }
//
//   set t(value: number) {
//     this.value[1] = value;
//   }
// }
//
// export class Vec3<T extends valuetype> extends VecBase<T, 3> implements d3 {
//   constructor(type: TypeConstructor<T>, initialData: number[] = []) {
//     super(3, type, initialData);
//   }
//
//   get x(): number {
//     return this.value[0];
//   }
//
//   set x(value: number) {
//     this.value[0] = value;
//   }
//
//   get r(): number {
//     return this.value[0];
//   }
//
//   set r(value: number) {
//     this.value[0] = value;
//   }
//
//   get s(): number {
//     return this.value[0];
//   }
//
//   set s(value: number) {
//     this.value[0] = value;
//   }
//
//   get y(): number {
//     return this.value[1];
//   }
//
//   set y(value: number) {
//     this.value[1] = value;
//   }
//
//   get g(): number {
//     return this.value[1];
//   }
//
//   set g(value: number) {
//     this.value[1] = value;
//   }
//
//   get t(): number {
//     return this.value[1];
//   }
//
//   set t(value: number) {
//     this.value[1] = value;
//   }
//
//   get z(): number {
//     return this.value[2];
//   }
//
//   set z(value: number) {
//     this.value[2] = value;
//   }
//
//   get b(): number {
//     return this.value[2];
//   }
//
//   set b(value: number) {
//     this.value[2] = value;
//   }
//
//   get p(): number {
//     return this.value[2];
//   }
//
//   set p(value: number) {
//     this.value[2] = value;
//   }
// }
//
// export class Vec4<T extends valuetype> extends VecBase<T, 4> implements d4 {
//   constructor(type: TypeConstructor<T>, initialData: number[] = []) {
//     super(4, type, initialData);
//   }
//
//   get x(): number {
//     return this.value[0];
//   }
//
//   set x(value: number) {
//     this.value[0] = value;
//   }
//
//   get r(): number {
//     return this.value[0];
//   }
//
//   set r(value: number) {
//     this.value[0] = value;
//   }
//
//   get s(): number {
//     return this.value[0];
//   }
//
//   set s(value: number) {
//     this.value[0] = value;
//   }
//
//   get y(): number {
//     return this.value[1];
//   }
//
//   set y(value: number) {
//     this.value[1] = value;
//   }
//
//   get g(): number {
//     return this.value[1];
//   }
//
//   set g(value: number) {
//     this.value[1] = value;
//   }
//
//   get t(): number {
//     return this.value[1];
//   }
//
//   set t(value: number) {
//     this.value[1] = value;
//   }
//
//   get z(): number {
//     return this.value[2];
//   }
//
//   set z(value: number) {
//     this.value[2] = value;
//   }
//
//   get b(): number {
//     return this.value[2];
//   }
//
//   set b(value: number) {
//     this.value[2] = value;
//   }
//
//   get p(): number {
//     return this.value[2];
//   }
//
//   set p(value: number) {
//     this.value[2] = value;
//   }
//
//   get w(): number {
//     return this.value[3];
//   }
//
//   set w(value: number) {
//     this.value[3] = value;
//   }
//
//   get a(): number {
//     return this.value[3];
//   }
//
//   set a(value: number) {
//     this.value[3] = value;
//   }
//
//   get q(): number {
//     return this.value[3];
//   }
//
//   set q(value: number) {
//     this.value[3] = value;
//   }
// }