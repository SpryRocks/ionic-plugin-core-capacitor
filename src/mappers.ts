import {PluginError} from './error';

type RawError = {message: unknown; code: unknown};

export abstract class Mappers {
  protected abstract mapError(
    message: string | undefined,
    details: object | undefined,
  ): PluginError;

  handlePluginError<T>(error: RawError | unknown): Promise<T> {
    let message: string | undefined;
    let details: object | undefined;
    if (typeof error === 'object' && error != null) {
      const error_ = error as RawError;
      if (error_.message && typeof error_.message === 'string') {
        message = error_.message;
      }
      if (error_.code && typeof error_.code === 'string') {
        try {
          details = JSON.parse(error_.code);
        } catch (e) {
          details = {};
        }
      }
    }
    return Promise.reject(this.mapError(message, details));
  }
}
