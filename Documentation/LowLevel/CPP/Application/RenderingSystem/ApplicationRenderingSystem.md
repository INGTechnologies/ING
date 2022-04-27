# ING::ApplicationRenderingSystem class #  


## Basic Info ##
-  `Description`: Manage application rendering features
-  `Parent Class`: [**IApplicationComponent**](../Component/IApplicationComponent.md)
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationRenderingSystem**([**IApplication**](../../IApplication.md)* app)
-  `Destructor`:
	+  **~ApplicationRenderingSystem**()
-  `Properties`:
	+  **defaultPipeline** ([**Rendering**::**IPipeline**]()*)**:** default rendering pipeline
		*  `Getter`: **GetDefaultPipeline**()
	+  **pipeline** ([**Rendering**::**IPipeline**]()*)**:** currently using rendering pipeline
		*  `Getter`: **GetPipeline**()
		*  `Setter`: **SetPipeline**([**Rendering**::**IPipeline**]()* newPipeline)**:** this method will set targetPipeline to newPipeline and pipeline will be set to targetPipeline in next frame
	+  **targetPipeline** ([**Rendering**::**IPipeline**]()*)**:** rendering pipeline that will be used in next render frame
		*  `Getter`: **GetTargetPipeline**()
	+  **defaultDevice** ([**Rendering**::**IDevice**]()*)**:** default rendering device
		*  `Getter`: **GetDefaultDevice**()
	+  **device** ([**Rendering**::**IDevice**]()*)**:** currently using rendering device
		*  `Getter`: **GetDevice**()
		*  `Setter`: **SetDevice**([**Rendering**::**IDevice**]()* newDevice)**:** this method will set targetDevice to newDevice and device will be set to targetDevice in next frame
	+  **targetDevice** ([**Rendering**::**IDevice**]()*)**:** rendering device that will be used in next render frame
		*  `Getter`: **GetTargetDevice**()
-  `Methods`:
	+  **Init**() (bool) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**Init**())
	+  **Release**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**Release**())
	+  **Start**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**Start**())
	+  **PreUpdate**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**PreUpdate**())
	+  **Update**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**Update**())
	+  **LateUpdate**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**LateUpdate**())
	+  **PreRender**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**PreRender**())
	+  **Render**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**Render**())
	+  **LateRender**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent.md)::**LateRender**())