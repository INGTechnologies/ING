# ING::ApplicationWindowManager class #  


## Basic Info ##
-  `Description`: Manages application windows
-  `Parent Class`: [**ING**::**IApplicationComponent**](./IApplicationComponent.md)
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationWindowManager**([**ING**::**IApplication**](./IApplication.md)* app)
-  `Destructor`:
	+  **~ApplicationWindowManager**()
-  `Properties`:
	+  std::unordered_map<std::string, [**ING**::**IWindow**]()*> **name2WindowMap** **:** name to window map
		*  `ItemGetter`: [**ING**::**IWindow**]()* **GetWindow**(const std::string& name) **:** get window by name
-  `Methods`:
	+  bool **Init**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Init**())
	+  void **Release**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Release**())
	+  **AddWindow**([**ING**::**IWindow**](./IWindow.md)* window) (void)**:** add a window for managing
	+  **RemoveWindow**([**ING**::**IWindow**](./IWindow.md)* window) (void)**:** remove a window which is being managed
	+  void **Start**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Start**())
	+  void **PreUpdate**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**PreUpdate**())
	+  void **Update**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Update**())
	+  void **LateUpdate**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**LateUpdate**())
	+  void **PreRender**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**PreRender**())
	+  void **Render**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Render**())
	+  void **LateRender**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**LateRender**())