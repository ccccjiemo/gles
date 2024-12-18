import { createAtomicInt_, getAtomicIntValue_, subAtomicIntValue_ } from "libgles.so";

export class AtomicInt {
  constructor(init?: number) {
    createAtomicInt_(this, init ?? 0);
  }

  get value(): number {
    return getAtomicIntValue_(this);
  }

  sub(value: number) {
    subAtomicIntValue_(this, value);
  }
}