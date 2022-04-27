# ING::ApplicationWindowManager class #  


## Basic Info ##
-  `Description`: Manage application windows
-  `Parent Class`: [**IApplicationComponent**](../Component/IApplicationComponent)
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationWindowManager**([**IApplication**](../../IApplication.md)* app)
-  `Destructor`:
	+  **~ApplicationWindowManager**()
-  `Properties`:
	+  **name2WindowMap** (std::unordered_map<std::string, [**IWindow**]()*>)**:** name to window map
		*  `ItemGetter`: **GetWindow**(const std::string& name) ([**IWindow**]()*): get window by name
-  `Methods`:
	+  **Init**() (bool) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Init**())
	+  **Release**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Release**())
	+  **AddWindow**([**IWindow**]()* window) (void)**:** add a window for managing
	+  **RemoveWindow**([**IWindow**]()* window) (void)**:** remove a window which is being managed
	+  **Start**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Start**())
	+  **PreUpdate**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**PreUpdate**())
	+  **Update**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Update**())
	+  **LateUpdate**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**LateUpdate**())
	+  **PreRender**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**PreRender**())
	+  **Render**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Render**())
	+  **LateRender**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**LateRender**())