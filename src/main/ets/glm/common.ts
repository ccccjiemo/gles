export type int = Int32Array;

export type uint = Uint32Array;

export type float = Float32Array;

export type double = Float64Array;

export type VecSize = 1 | 2 | 3 | 4;

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
  TSize extends 1? [number] :
    TSize extends 2? [number] | [number, number] :
      TSize extends 3? [number] | [number, number] | [number, number, number] :
      [number] | [number, number] | [number, number, number] | [number, number, number, number];


export type GOE<T1 extends number, T2 extends number> = IsGreaterOrEqual<T1, T2> extends true ? T2 : never

export type TupleBySub<T1 extends number, T2 extends number> =Tuple<number, Subtract<T1, T2>>

export type TupleByMul<T1 extends Rows, T2 extends Cols> =Tuple<number, Multiply<T1, T2>>