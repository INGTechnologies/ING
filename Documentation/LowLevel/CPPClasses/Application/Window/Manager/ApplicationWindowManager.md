# ING::ApplicationWindowManager class #  


## Basic Info ##
-  `Description`: Manage application windows
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationWindowManager**([**IApplication**](../../IApplication.md)* app)
-  `Destructor`:
	+  **~ApplicationWindowManager**()
-  `Properties`:
	+  **application** (IApplication*)**:** application
		*  `Getter`: **GetApplication**()
	+  **name2WindowMap** (std::unordered_map<std::string, IWindow*>)**:** name to window map
		*  `ItemGetter`: **GetWindow**(const std::string& name) (IWindow*): get window by name
-  `Methods`:
	+  **Release**() (void) (virtual): use to release application window manager
	+  **AddWindow**([**IWindow**]()* window) (void)**:** add a window for managing
	+  **RemoveWindow**([**IWindow**]()* window) (void)**:** remove a window which is being managed