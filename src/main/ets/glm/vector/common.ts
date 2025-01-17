export type int = Int32Array;

export type uint = Uint32Array;

export type float = Float32Array;

export type double = Float64Array;

export type valuetype = int | uint | float | double;

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
