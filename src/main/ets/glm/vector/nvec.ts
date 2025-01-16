export type int = Int32Array;

export type uint = Uint32Array;

export type float = Float32Array;

export type double = Float64Array;

type valuetype = int | uint | float | double;

interface nvec<T extends valuetype> {
  value: T

  get length(): number
}

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

export class d1nvec<T extends valuetype> implements d1, nvec<T> {
  value: T;

  get length(): number {
    return this.d1;
  }

  protected set d1(value: number) {
    this.value[0] = value;
  }

  protected get d1(): number {
    return this.value[0];
  }

  get x(): number {
    return this.d1;
  }

  set x(value: number) {
    this.d1 = value;
  }

  get r(): number {
    return this.d1;
  }

  set r(value: number) {
    this.d1 = value;
  }

  get s(): number {
    return this.d1;
  }

  set s(value: number) {
    this.d1 = value;
  }
}

export class d2nvec<T extends valuetype> extends d1nvec<T> implements d2 {
  protected set d2(value: number) {
    this.value[1] = value;
  }

  protected get d2(): number {
    return this.value[1];
  }

  get length(): number {
    return Math.sqrt(this.d1 * this.d1 + this.d2 * this.d2);
  }

  get y(): number {
    return this.d2;
  }

  set y(value: number) {
    this.d2 = value;
  }

  get g(): number {
    return this.d2;
  }

  set g(value: number) {
    this.d2 = value;
  }

  get t(): number {
    return this.d2;
  }

  set t(value: number) {
    this.d2 = value;
  }
}

export class d3nvec<T extends valuetype> extends d2nvec<T> implements d3 {
  protected get d3(): number {
    return this.value[2];
  }

  protected set d3(value: number) {
    this.value[2] = value;
  }

  get length(): number {
    return Math.sqrt(this.d1 * this.d1 + this.d2 * this.d2 + this.d3 * this.d3)
  }

  get z(): number {
    return this.d3;
  }

  set z(value: number) {
    this.d3 = value;
  }

  get b(): number {
    return this.d3;
  }

  set b(value: number) {
    this.d3 = value;
  }

  get p(): number {
    return this.d3;
  }

  set p(value: number) {
    this.d3 = value;
  }
}

export class d4nvec<T extends valuetype> extends d3nvec<T> implements d4 {
  protected get d4(): number {
    return this.value[3];
  }

  protected set d4(value: number) {
    this.value[3] = value;
  }

  get length(): number {
    return Math.sqrt(this.d1 * this.d1 + this.d2 * this.d2 + this.d3 * this.d3 + this.d4 * this.d4);
  }

  get w(): number {
    return this.d4;
  }

  set w(value: number) {
    this.d4 = value;
  }

  get a(): number {
    return this.d4;
  }

  set a(value: number) {
    this.d4 = value;
  }

  get q(): number {
    return this.d4;
  }

  set q(value: number) {
    this.d4 = value;
  }
}