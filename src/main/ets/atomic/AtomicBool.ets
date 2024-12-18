import { createAtomicBool_, getAtomicBoolValue_, setAtomicBoolValue_ } from "libgles.so";

export class AtomicBool {
  constructor(init?: boolean) {
    createAtomicBool_(this, init ?? false);
  }

  get value(): boolean {
    return Boolean(getAtomicBoolValue_(this));
  }

  set value(val: boolean) {
    setAtomicBoolValue_(this, val);
  }
}