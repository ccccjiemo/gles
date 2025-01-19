import { lang } from '@kit.ArkTS';

export interface GLObject extends lang.ISendable {
  readonly handle: number;

  bind(): void;

  unbind(): void;

  delete(): void;
}
