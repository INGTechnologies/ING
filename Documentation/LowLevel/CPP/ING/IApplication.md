# ING::IApplication class #  


## Basic Info ##
-  `Description`: Represent for application, managed by [**ApplicationManager**](./ApplicationManager.md)
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
	+  **configuration** ([**Configuration**]()*)**:** application configuration
		*  `Getter`: **GetConfiguration**()
	+  **windowManager** ([**ApplicationWindowManager**](./ApplicationWindowManager.md)*)**:** application window manager
		*  `Getter`: **GetWindowManager**()
	+  **renderingSystem** ([**ApplicationRenderingSystem**](./ApplicationRenderingSystem.md)*)**:** application rendering system
		*  `Getter`: **GetRenderingSystem**()
	+  **name2ComponentIndexMap** (std::unordered_map<std::string, unsigned int>)**:** name to component index map
	+  **componentVector** (std::vector<[**IApplicationComponent**](./IApplicationComponent.md)*>)**:** name to component index map
		*  `ItemGetter`:
			+ **GetComponent**(const std::string& name) ([**IApplicationComponent**](./IApplicationComponent.md)*)**:** get component by name
			+  **GetComponent**(unsigned int index) ([**IApplicationComponent**](./IApplicationComponent.md)*)**:** get component by index
-  `Methods`:
	+  **AddComponent**([**IApplicationComponent**](./IApplicationComponent.md)* component) (bool)**:** add component
	+  **RemoveComponent**([**IApplicationComponent**](./IApplicationComponent.md)* component) (bool)**:** remove component
	+  **Init**() (bool) (virtual)**:** init application
	+  **Release**() (void) (virtual)**:** release application
	+  **Start**() (void) (virtual)**:** this method is called when the application start
	+  **PreUpdate**() (void) (virtual)**:** this method is called when before **Update** method
	+  **Update**() (void) (virtual)**:** this method is called every frame
	+  **LateUpdate**() (void) (virtual)**:** this method is called when after **Update** method
	+  **PreRender**() (void) (virtual)**:** this method is called when before **Render** method
	+  **Render**() (void) (virtual)**:** this method is called when engine render
	+  **LateRender**() (void) (virtual)**:** this method is called when after **Render** method