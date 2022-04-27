# ING::ApplicationRenderingSystem class #  


## Basic Info ##
-  `Description`: Manage application rendering features
-  `Parent Class`: [**IApplicationComponent**](../Component/IApplicationComponent)
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
	+  **Init**() (bool) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Init**())
	+  **Release**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Release**())
	+  **Start**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Start**())
	+  **PreUpdate**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**PreUpdate**())
	+  **Update**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Update**())
	+  **LateUpdate**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**LateUpdate**())
	+  **PreRender**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**PreRender**())
	+  **Render**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**Render**())
	+  **LateRender**() (void) (override [**IApplicationComponent**](../Component/IApplicationComponent)::**LateRender**())