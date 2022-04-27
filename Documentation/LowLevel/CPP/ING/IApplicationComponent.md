
# ING::IApplicationComponent class #  


## Basic Info ##
-  `Description`: An IApplicationComponent is a component of an application.
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **IApplicationComponent**([**IApplication**](./IApplication.md)* application, const std::string& name)
-  `Destructor`:
	+  **~IApplicationComponent**()
-  `Properties`:
	+  **name** (std::string)**:** component name
		*  `Getter`: **GetName**()
	+  **application** ([**IApplication**](./IApplication.md)*)**:** an application that has this component
		*  `Getter`: **GetApplication**()
-  `Methods`:
	+  **Init**() (bool) (virtual)**:** init component
	+  **Release**() (void) (virtual)**:** release component
	+  **Start**() (void) (virtual)**:** this method is called when the component start
	+  **PreUpdate**() (void) (virtual)**:** this method is called when before **Update** method
	+  **Update**() (void) (virtual)**:** this method is called every frame
	+  **LateUpdate**() (void) (virtual)**:** this method is called when after **Update** method
	+  **PreRender**() (void) (virtual)**:** this method is called when before **Render** method
	+  **Render**() (void) (virtual)**:** this method is called when engine render
	+  **LateRender**() (void) (virtual)**:** this method is called when after **Render** method