import { IsGreaterOrEqual, valuetype, VecSize, Rows, Cols } from './common';
import { mat, } from './mat';
import { vec } from './vec';



export function mul<T extends valuetype, S extends VecSize>(v1: vec<T, S>,
  v2: vec<T, S extends S ? S : never>): vec<T, S>

export function mul<T extends valuetype, S1 extends Rows, S2 extends VecSize, C extends Cols>(v1: mat<T, S1, C>,
  v2: vec<T, IsGreaterOrEqual<S2, S1> extends true ? S2 : never>): mat<T, S1, C>

export function mul<T extends valuetype, S1 extends Rows, S2 extends Rows, C extends Cols >(v1: vec<T, S1>, v2: mat<T, IsGreaterOrEqual<S1, S2> extends true ? S2 : never, C>) : mat<T, S2, C>

export function mul<T extends valuetype, S extends Rows, R extends Rows, C extends Cols>(v1: mat<T, S, C>,
  v2: mat<T, R, S extends S ? S : never>): mat<T, R, C>

export function mul<T extends valuetype, S extends VecSize, R extends Rows, C
extends Cols>(v1: vec<T, S> | mat<T, R, C>, v2: vec<T, S> | mat<T, R, C>): vec<T, S> | mat<T, R, C> {
  throw Error('')
}

