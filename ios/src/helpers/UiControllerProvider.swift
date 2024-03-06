import Capacitor

public protocol WithUiViewControllerProvider {
    func setUiViewControllerProvider(viewControllerProvider: IUiViewControllerProvider)
}

public extension IUiViewControllerProvider? {
    func requireViewController() throws -> UIViewController {
        guard let viewController = self?.getViewController() else {
            throw PluginError(message: "viewControllerProvider is nil")
        }
        return viewController
    }
}

public protocol IUiViewControllerProvider {
    func getViewController() -> UIViewController?
}

public class UiViewControllerProvider: IUiViewControllerProvider {
    private let plugin: CAPPlugin

    public init(plugin: CAPPlugin) {
        self.plugin = plugin
    }

    public func getViewController() -> UIViewController? {
        return plugin.bridge?.viewController
    }
}
