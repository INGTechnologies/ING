
# ING::IApplicationComponent class #  


## Basic Info ##
-  `Description`: An **ING**::**IApplicationComponent** is a component of an application.
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **IApplicationComponent**([**ING**::**IApplication**](./IApplication.md)* application, const std::string& name)
-  `Destructor`:
	+  **~IApplicationComponent**()
-  `Properties`:
	+  std::string **name** **:** component name
		*  `Getter`: **GetName**()
	+  [**ING**::**IApplication**](./IApplication.md)* **application** **:** an application that has this component
		*  `Getter`: **GetApplication**()
-  `Methods`:
	+  virtual bool **Init**() **:** init component
	+  virtual void **Release**() **:** release component
	+  virtual void **Start**() **:** this method is called when the component start
	+  virtual void **PreUpdate**() **:** this method is called when before **Update** method
	+  virtual void **Update**() **:** this method is called every frame
	+  virtual void **LateUpdate**() **:** this method is called when after **Update** method
	+  virtual void **PreRender**() **:** this method is called when before **Render** method
	+  virtual void **Render**() **:** this method is called when engine render
	+  virtual void **LateRender**() **:** this method is called when after **Render** method