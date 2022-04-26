# ING::ApplicationManager class #  


## Basic Info ##
-  `Description`: Represent for application
-  `Parent Class`: [**Singleton**]()<**ING**::**Engine**>, [**Square**]()
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationManager**()
-  `Destructor`:
	+  **~ApplicationManager**()
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
	+  **Init**() (bool) (override [**Square**]()::**Init**())
	+  **Run**() (bool) (override [**Square**]()::**Run**())
	+  **Release**() (bool) (override [**Square**]()::**Release**())
	+  **AddApplication**([**IApplication**](../IApplication.md)* app) (void)**:** add an application for managing
	+  **RemoveApplication**([**IApplication**](../IApplication.md)* app) (void)**:** remove an application which is being managed
	+  **Start**() (void) (virtual)**:** this method is called when the application start
	+  **PreUpdate**() (void) (virtual)**:** this method is called when before **Update** method
	+  **Update**() (void) (virtual)**:** this method is called every frame
	+  **LateUpdate**() (void) (virtual)**:** this method is called when after **Update** method
	+  **PreRender**() (void) (virtual)**:** this method is called when before **Render** method
	+  **Render**() (void) (virtual)**:** this method is called when engine render
	+  **LateRender**() (void) (virtual)**:** this method is called when after **Render** method