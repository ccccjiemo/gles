import { float, valuetype } from "./common";

interface nvec<T extends valuetype, TSize extends 1 | 2 | 3 | 4> {
  value: T
  get length(): number
}


export type vec<TType extends valuetype = float, TSize extends 1 | 2 | 3 | 4 = 1> = nvec<TType, TSize> &
(TSize extends 1 ? d1 : unknown) &
(TSize extends 2 ? d1 & d2 : unknown) &
(TSize extends 3 ? d1 & d2 & d3 : unknown) &
(TSize extends 4 ? d1 & d2 & d3 & d4 : unknown);


interface d1 {
  get x(): number

  set x(value: number)

  get r(): number

  set r(value: number)

  get s(): number

  set s(value: number)
}

interface d2 {
  get y(): number

  set y(value: number)

  get g(): number

  set g(value: number)

  get t(): number

  set t(value: number)
}

interface d3 {
  get z(): number

  set z(value: number)

  get b(): number

  set b(value: number)

  get p(): number

  set p(value: number)
}

interface d4 {
  get w(): number

  set w(value: number)

  get a(): number

  set a(value: number)

  get q(): number

  set q(value: number)
}

class VecBase<T extends valuetype> implements nvec<T, 1 | 2 | 3 | 4> {
  value: T;

  constructor(size: number, type: { new(size: number): T }, initialData: number[] = []) {
    this.value = new type(size);
    if (initialData.length === 0) {
      this.value.fill(1);
    } else if (initialData.length === 1) {
      this.value.fill(initialData[0]);
    } else {
      for (let i = 0; i < size; i++) {
        this.value[i] = initialData[i] !== undefined ? initialData[i] : 0;
      }
    }
  }

  get length(): number {
    return this.value.length;
  }
}

export class Vec1<T extends valuetype> extends VecBase<T> implements d1 {
  constructor(type: { new(size: number): T }, initialData: number[] = []) {
    super(1, type, initialData);
  }

  get x(): number {
    return this.value[0];
  }

  set x(value: number) {
    this.value[0] = value;
  }

  get r(): number {
    return this.value[0];
  }

  set r(value: number) {
    this.value[0] = value;
  }

  get s(): number {
    return this.value[0];
  }

  set s(value: number) {
    this.value[0] = value;
  }
}

export class Vec2<T extends valuetype> extends VecBase<T> implements d1, d2 {
  constructor(type: { new(size: number): T }, initialData: number[] = []) {
    super(2, type, initialData);
  }

  get x(): number {
    return this.value[0];
  }

  set x(value: number) {
    this.value[0] = value;
  }

  get r(): number {
    return this.value[0];
  }

  set r(value: number) {
    this.value[0] = value;
  }

  get s(): number {
    return this.value[0];
  }

  set s(value: number) {
    this.value[0] = value;
  }

  get y(): number {
    return this.value[1];
  }

  set y(value: number) {
    this.value[1] = value;
  }

  get g(): number {
    return this.value[1];
  }

  set g(value: number) {
    this.value[1] = value;
  }

  get t(): number {
    return this.value[1];
  }

  set t(value: number) {
    this.value[1] = value;
  }
}

export class Vec3<T extends valuetype> extends VecBase<T> implements d1, d2, d3 {
  constructor(type: { new(size: number): T }, initialData: number[] = []) {
    super(3, type, initialData);
  }

  get x(): number {
    return this.value[0];
  }

  set x(value: number) {
    this.value[0] = value;
  }

  get r(): number {
    return this.value[0];
  }

  set r(value: number) {
    this.value[0] = value;
  }

  get s(): number {
    return this.value[0];
  }

  set s(value: number) {
    this.value[0] = value;
  }

  get y(): number {
    return this.value[1];
  }

  set y(value: number) {
    this.value[1] = value;
  }

  get g(): number {
    return this.value[1];
  }

  set g(value: number) {
    this.value[1] = value;
  }

  get t(): number {
    return this.value[1];
  }

  set t(value: number) {
    this.value[1] = value;
  }

  get z(): number {
    return this.value[2];
  }

  set z(value: number) {
    this.value[2] = value;
  }

  get b(): number {
    return this.value[2];
  }

  set b(value: number) {
    this.value[2] = value;
  }

  get p(): number {
    return this.value[2];
  }

  set p(value: number) {
    this.value[2] = value;
  }
}

export class Vec4<T extends valuetype> extends VecBase<T> implements d1, d2, d3, d4 {
  constructor(type: { new(size: number): T }, initialData: number[] = []) {
    super(4, type, initialData);
  }

  get x(): number {
    return this.value[0];
  }

  set x(value: number) {
    this.value[0] = value;
  }

  get r(): number {
    return this.value[0];
  }

  set r(value: number) {
    this.value[0] = value;
  }

  get s(): number {
    return this.value[0];
  }

  set s(value: number) {
    this.value[0] = value;
  }

  get y(): number {
    return this.value[1];
  }

  set y(value: number) {
    this.value[1] = value;
  }

  get g(): number {
    return this.value[1];
  }

  set g(value: number) {
    this.value[1] = value;
  }

  get t(): number {
    return this.value[1];
  }

  set t(value: number) {
    this.value[1] = value;
  }

  get z(): number {
    return this.value[2];
  }

  set z(value: number) {
    this.value[2] = value;
  }

  get b(): number {
    return this.value[2];
  }

  set b(value: number) {
    this.value[2] = value;
  }

  get p(): number {
    return this.value[2];
  }

  set p(value: number) {
    this.value[2] = value;
  }

  get w(): number {
    return this.value[3];
  }

  set w(value: number) {
    this.value[3] = value;
  }

  get a(): number {
    return this.value[3];
  }

  set a(value: number) {
    this.value[3] = value;
  }

  get q(): number {
    return this.value[3];
  }

  set q(value: number) {
    this.value[3] = value;
  }
}