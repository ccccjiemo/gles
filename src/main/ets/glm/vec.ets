import { glUniform2f, glUniform4f, glUniform3f, glUniform2i, glUniform3i, glUniform4i } from '../GLES';

export interface vec {
  setUniformf(location: number): void;
}

export interface ivec {
  setUniformi(location: number): void;
}

const parseValue: (value: number) => number = (value) => {
  return Math.trunc(value);
}


export class vec2 implements vec {
  private _x: number;
  private _y: number;


  constructor(scalar: number);

  constructor(x: number, y: number);

  constructor(xOrScalar: number, y?: number) {
    this._x = xOrScalar;
    this._y = y ?? xOrScalar;
  }

  get x(): number {
    return this._x;
  }

  get y(): number {
    return this._y;
  }

  setUniformf(location: number): void {
    glUniform2f(location, this._x, this._y);
  }
}

export class vec3 implements vec {
  private _x: number;
  private _y: number;
  private _z: number;

  constructor(scalar: number);

  constructor(x: number, y: number, z: number);

  constructor(xOrScalar: number, y?: number, z?: number) {
    this._x = xOrScalar;
    this._y = y ?? xOrScalar;
    this._z = z ?? xOrScalar;
  }

  get x(): number {
    return this._x;
  }

  get y(): number {
    return this._y;
  }

  get z(): number {
    return this._z;
  }

  setUniformf(location: number): void {
    glUniform3f(location, this._x, this._y, this._z);
  }
}

export class vec4 implements vec {
  private _x: number;
  private _y: number;
  private _z: number;
  private _w: number;

  constructor(scalar: number);

  constructor(x: number, y: number, z: number, w: number);

  constructor(xOrScalar: number, y?: number, z?: number, w?: number) {
    this._x = xOrScalar;
    this._y = y ?? xOrScalar;
    this._z = z ?? xOrScalar;
    this._w = w ?? xOrScalar;
  }

  get x(): number {
    return this._x;
  }

  get y(): number {
    return this._y;
  }

  get z(): number {
    return this._z;
  }

  get w(): number {
    return this._w;
  }

  setUniformf(location: number): void {
    glUniform4f(location, this._x, this._y, this._z, this._w);
  }
}


export class ivec2 implements ivec {
  private _x: number;
  private _y: number;

  constructor(scalar: number);

  constructor(x: number, y: number);

  constructor(xOrScalar: number, y?: number) {
    this._x = parseValue(xOrScalar);
    this._y = parseValue(y ?? xOrScalar);
  }

  get x(): number {
    return this._x;
  }

  get y(): number {
    return this._y;
  }

  setUniformi(location: number): void {
    glUniform2i(location, this._x, this._y);
  }
}

export class ivec3 implements ivec {
  private _x: number;
  private _y: number;
  private _z: number;

  constructor(scalar: number);

  constructor(x: number, y: number, z: number);

  constructor(xOrScalar: number, y?: number, z?: number) {
    this._x = parseValue(xOrScalar);
    this._y = parseValue(y ?? xOrScalar);
    this._z = parseValue(z ?? xOrScalar);
  }

  get x(): number {
    return this._x;
  }

  get y(): number {
    return this._y;
  }

  get z(): number {
    return this._z;
  }

  setUniformi(location: number): void {
    glUniform3i(location, this._x, this._y, this._z);
  }
}

export class ivec4 implements ivec {
  private _x: number;
  private _y: number;
  private _z: number;
  private _w: number;

  constructor(scalar: number);

  constructor(x: number, y: number, z: number, w: number);

  constructor(xOrScalar: number, y?: number, z?: number, w?: number) {
    this._x = parseValue(xOrScalar);
    this._y = parseValue(y ?? xOrScalar);
    this._z = parseValue(z ?? xOrScalar);
    this._w = parseValue(w ?? xOrScalar);
  }

  get x(): number {
    return this._x;
  }

  get y(): number {
    return this._y;
  }

  get z(): number {
    return this._z;
  }

  get w(): number {
    return this._w;
  }

  setUniformi(location: number): void {
    glUniform4i(location, this._x, this._y, this._z, this._w);
  }
}
