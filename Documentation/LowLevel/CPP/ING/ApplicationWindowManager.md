# ING::ApplicationWindowManager class #  


## Basic Info ##
-  `Description`: Manages application windows
-  `Parent Class`: [**IApplicationComponent**](./IApplicationComponent.md)
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationWindowManager**([**IApplication**](./IApplication.md)* app)
-  `Destructor`:
	+  **~ApplicationWindowManager**()
-  `Properties`:
	+  **name2WindowMap** (std::unordered_map<std::string, [**IWindow**]()*>)**:** name to window map
		*  `ItemGetter`: **GetWindow**(const std::string& name) ([**IWindow**]()*): get window by name
-  `Methods`:
	+  **Init**() (bool) (override [**IApplicationComponent**](./IApplicationComponent.md)::**Init**())
	+  **Release**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**Release**())
	+  **AddWindow**([**IWindow**]()* window) (void)**:** add a window for managing
	+  **RemoveWindow**([**IWindow**]()* window) (void)**:** remove a window which is being managed
	+  **Start**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**Start**())
	+  **PreUpdate**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**PreUpdate**())
	+  **Update**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**Update**())
	+  **LateUpdate**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**LateUpdate**())
	+  **PreRender**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**PreRender**())
	+  **Render**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**Render**())
	+  **LateRender**() (void) (override [**IApplicationComponent**](./IApplicationComponent.md)::**LateRender**())