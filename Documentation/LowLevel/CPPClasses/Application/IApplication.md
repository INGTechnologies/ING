# ING::IApplication class #  


## Basic Info ##
-  `Description`: Represent for application
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **IApplication**(const std::string& configPath)
-  `Destructor`:
	+  **~IApplication**()
-  `Properties`:
	+  **name** (std::string)**:** application name
		*  `Getter`: **GetName**()
	+  **configPath** (std::string)**:** application configuration file path
		*  `Getter`: **GetConfigPath**()
	+  **configuration** (Configuration*)**:** application configuration
		*  `Getter`: **GetConfiguration**()
	+  **windowManager** (ApplicationWindowManager*)**:** application window manager
		*  `Getter`: **GetWindowManager**()
-  `Methods`:
	+  **Start**() (void) (virtual)**:** this method is called when the application start
	+  **PreUpdate**() (void) (virtual)**:** this method is called when before **Update** method
	+  **Update**() (void) (virtual)**:** this method is called every frame
	+  **LateUpdate**() (void) (virtual)**:** this method is called when after **Update** method
	+  **PreRender**() (void) (virtual)**:** this method is called when before **Render** method
	+  **Render**() (void) (virtual)**:** this method is called when engine render
	+  **LateRender**() (void) (virtual)**:** this method is called when after **Render** method