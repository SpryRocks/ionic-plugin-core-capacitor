export class PluginError extends Error {
  constructor(message?: string) {
    super(message ?? 'Unknown error');
    Object.setPrototypeOf(this, new.target.prototype);
  }
}
