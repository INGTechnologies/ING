# ING::IApplication class #  


## Basic Info ##
-  `Description`: Represents application, managed by [**ING**::**ApplicationManager**](./ApplicationManager.md)
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **IApplication**(const std::string& configPath)
-  `Destructor`:
	+  **~IApplication**()
-  `Properties`:
	+  std::string **name** **:** application name
		*  `Getter`: **GetName**()
	+  std::string **configPath** **:** application configuration file path
		*  `Getter`: **GetConfigPath**()
	+  [**ING**::**Configuration**](./Configuration.md)* **configuration** **:** application configuration
		*  `Getter`: **GetConfiguration**()
	+  [**ING**::**ApplicationWindowManager**](./ApplicationWindowManager.md)* **windowManager** **:** application window manager
		*  `Getter`: **GetWindowManager**()
	+  [**ING**::**ApplicationRenderingSystem**](./ApplicationRenderingSystem.md)* **renderingSystem** **:** application rendering system
		*  `Getter`: **GetRenderingSystem**()
	+  std::unordered_map<std::string, unsigned int> **name2ComponentIndexMap** **:** name to component index map
	+  std::vector<[**ING**::**IApplicationComponent**](./IApplicationComponent.md)*> **componentVector** **:** name to component index map
		*  `ItemGetter`:
			+ [**ING**::**IApplicationComponent**](./IApplicationComponent.md)* **GetComponent**(const std::string& name) **:** get component by name
			+ [**ING**::**IApplicationComponent**](./IApplicationComponent.md)* **GetComponent**(unsigned int index) **:** get component by index
-  `Methods`:
	+  void **AddComponent**([**ING**::**IApplicationComponent**](./IApplicationComponent.md)* component) **:** add component
	+  void **RemoveComponent**([**ING**::**IApplicationComponent**](./IApplicationComponent.md)* component) **:** remove component
	+  virtual bool **Init**() **:** init application
	+  virtual void **Release**() **:** release application
	+  virtual void **Start**() **:** this method is called when the component start
	+  virtual void **PreUpdate**() **:** this method is called when before **Update** method
	+  virtual void **Update**() **:** this method is called every frame
	+  virtual void **LateUpdate**() **:** this method is called when after **Update** method
	+  virtual void **PreRender**() **:** this method is called when before **Render** method
	+  virtual void **Render**() **:** this method is called when engine render
	+  virtual void **LateRender**() **:** this method is called when after **Render** method