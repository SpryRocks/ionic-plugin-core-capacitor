export class PluginError extends Error {
  constructor(public override readonly message: string) {
    super(message);
    Object.setPrototypeOf(this, new.target.prototype);
  }
}
