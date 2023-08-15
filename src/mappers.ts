import {PluginError} from './error';

type RawError = {message: unknown; code: unknown; data: unknown};

export interface ErrorDetails {
  message: string | undefined;
}

export abstract class Mappers<TErrorDetails extends ErrorDetails = ErrorDetails> {
  protected decodePluginError(details: TErrorDetails): PluginError {
    return new PluginError(details.message);
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
    return new PluginError(message);
  }

  protected mapError(error: PluginError): PluginError {
    return error;
  }

  createPluginError(error: RawError | unknown): PluginError {
    const pluginError = this.decodeCapacitorError(error);
    return this.mapError(pluginError);
  }

  private decodeCapacitorError(error: unknown): PluginError {
    if (typeof error === 'object' && error != null) {
      const error_ = error as RawError;
      if (error_.data && typeof error_.data === 'object') {
        return this.decodePluginError(error_.data as TErrorDetails);
      }
      if (error_.code && typeof error_.code === 'string') {
        const details = this.decodeErrorDetailsFromCode(error_.code);
        if (details) return this.decodePluginError(details);
      }
    }
    return this.mapUnknownError(error);
  }

  private decodeErrorDetailsFromCode(code: string): TErrorDetails | undefined {
    try {
      return JSON.parse(code) as TErrorDetails;
    } catch (e) {
      return undefined;
    }
  }
}
