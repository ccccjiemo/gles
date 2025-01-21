import { lang } from '@kit.ArkTS';

interface GLContext extends lang.ISendable {
  makeCurrent(): void;
}