# ING::ApplicationManager class #  


## Basic Info ##
-  `Description`: Manages applications
-  `Parent Class`: [**ING**::**Singleton**]()<**ING**::**Engine**>, [**ING**::**Square**]()
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationManager**()
-  `Destructor`:
	+  **~ApplicationManager**()
-  `Properties`:
	+  **name2ApplicationMap** (std::unordered_map<std::string, IApplication*>)**:** name to application map
		*  `ItemGetter`: **GetApplication**(const std::string& name) ([**ING**::**IApplication**](./IApplication.md)*): get application by name
-  `Methods`:
	+  virtual bool **Init**() **:** override [**ING**::**Square**]()::**Init**()
	+  virtual bool **Run**() **:** override [**ING**::**Square**]()::**Run**()
	+  virtual bool **Release**() **:** override [**Square**]()::**Release**()
	+  void **AddApplication**([**IApplication**](./IApplication.md)* app) **:** add an application for managing
	+  void **RemoveApplication**([**IApplication**](./IApplication.md)* app) **:** remove an application which is being managed
	+  virtual void **Start**() **:** this method is called when the engine start
	+  virtual void **PreUpdate**() **:** this method is called when before **Update** method
	+  virtual void **Update**() **:** this method is called every frame
	+  virtual void **LateUpdate**() **:** this method is called when after **Update** method
	+  virtual void **PreRender**() **:** this method is called when before **Render** method
	+  virtual void **Render**() **:** this method is called when engine render
	+  virtual void **LateRender**() **:** this method is called when after **Render** method