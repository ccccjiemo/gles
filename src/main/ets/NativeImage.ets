import { attachContext_, bindNativeImage_, destroyNativeImage_, detachContext_, updateSurfaceImage_ } from 'libgles.so';
import { AtomicInt } from './atomic/AtomicInt';
import { Texture } from './globjects/Texture';

@Sendable
export class NativeImage {
  private _flag: AtomicInt;
  private _surfaceId: string;
  private _texture_id: number;

  constructor()

  constructor(texture: Texture)

  constructor(texture_id: number)

  constructor(value?: number | Texture) {
    this._flag = new AtomicInt(0);
    if (typeof value == 'undefined') {
      this._texture_id = -1;
    } else {
      this._texture_id = typeof value == 'number' ? value : value.id;
    }
    this._surfaceId = bindNativeImage_(this, this._texture_id, this._flag);
    if (!this._surfaceId) {
      throw Error('create NativeImage failed')
    }
  }

  get surfaceId(): string {
    return this._surfaceId
  }

  get isAvailable(): boolean {
    return this._flag.value != 0;
  }

  get textureId(): number {
    return this._texture_id;
  }

  attachContext(texture_id: number): OHNativeErrorCode {
    this._texture_id = texture_id;
    return attachContext_(this, texture_id);
  }

  detachContext(): OHNativeErrorCode {
    return detachContext_(this);
  }

  updateSurfaceImage(): OHNativeErrorCode {
    this._flag.sub(1);
    let error = updateSurfaceImage_(this);
    return error;
  }

  destroy(): void {
    if (this._surfaceId == '') {
      return;
    }
    destroyNativeImage_(this);
    this._surfaceId = '';
    this._texture_id = -1;
  }
}

export enum OHNativeErrorCode {
  /** @error succeed */
  NATIVE_ERROR_OK = 0,
  /** @error input invalid parameter */
  NATIVE_ERROR_INVALID_ARGUMENTS = 40001000,
  /** @error unauthorized operation */
  NATIVE_ERROR_NO_PERMISSION = 40301000,
  /** @error no idle buffer is available */
  NATIVE_ERROR_NO_BUFFER = 40601000,
  /** @error the consumer side doesn't exist */
  NATIVE_ERROR_NO_CONSUMER = 41202000,
  /** @error uninitialized */
  NATIVE_ERROR_NOT_INIT = 41203000,
  /** @error the consumer is connected */
  NATIVE_ERROR_CONSUMER_CONNECTED = 41206000,
  /** @error the buffer status did not meet expectations */
  NATIVE_ERROR_BUFFER_STATE_INVALID = 41207000,
  /** @error buffer is already in the cache queue */
  NATIVE_ERROR_BUFFER_IN_CACHE = 41208000,
  /** @error the buffer queue is full */
  NATIVE_ERROR_BUFFER_QUEUE_FULL = 41209000,
  /** @error buffer is not in the cache queue */
  NATIVE_ERROR_BUFFER_NOT_IN_CACHE = 41210000,
  /** @error the consumer is disconnected */
  NATIVE_ERROR_CONSUMER_DISCONNECTED = 41211000,
  /** @error the consumer not register listener */
  NATIVE_ERROR_CONSUMER_NO_LISTENER_REGISTERED = 41212000,
  /** @error the current device or platform does not support it */
  NATIVE_ERROR_UNSUPPORTED = 50102000,
  /** @error unknown error, please check log */
  NATIVE_ERROR_UNKNOWN = 50002000,
  /** @error hdi interface error */
  NATIVE_ERROR_HDI_ERROR = 50007000,
  /** @error ipc send failed */
  NATIVE_ERROR_BINDER_ERROR = 50401000,
  /** @error the egl environment is abnormal */
  NATIVE_ERROR_EGL_STATE_UNKNOWN = 60001000,
  /** @error egl interface invocation failed */
  NATIVE_ERROR_EGL_API_FAILED = 60002000,
}

