import {PluginError} from './error';

type RawError = {message: unknown; code: unknown; data: unknown};

export interface ErrorDetails {
  message: string | undefined;
}

export abstract class Mappers<TErrorDetails extends ErrorDetails> {
  protected mapError(details: TErrorDetails): PluginError {
    return new PluginError(details.message ?? 'Unknown error');
  }

  protected mapUnknownError(error: unknown): PluginError {
    let message: string | undefined;
    if (typeof error === 'object' && error != null) {
      const error_ = error as RawError;
      if (error_.message && typeof error_.message === 'string') {
        message = error_.message;
      }
    }
    if (typeof error === 'string') {
      message = error;
    }
    throw new PluginError(message ?? 'Unknown error');
  }

  handlePluginError<T>(error: RawError | unknown): T {
    console.log('Mappers', 'handlePluginError', {error});
    if (typeof error === 'object' && error != null) {
      const error_ = error as RawError;
      if (error_.data && typeof error_.data === 'object') {
        throw this.mapError(error_.data as TErrorDetails);
      }
      if (error_.code && typeof error_.code === 'string') {
        const details = this.decodeErrorDetailsFromCode(error_.code);
        if (details) throw this.mapError(details);
      }
    }
    throw this.mapUnknownError(error);
  }

  private decodeErrorDetailsFromCode(code: string): TErrorDetails | undefined {
    try {
      return JSON.parse(code) as TErrorDetails;
    } catch (e) {
      return undefined;
    }
  }
}
