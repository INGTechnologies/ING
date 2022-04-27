# ING::ApplicationRenderingSystem class #  


## Basic Info ##
-  `Description`: Manages application rendering features
-  `Parent Class`: [**ING**::**IApplicationComponent**](./IApplicationComponent.md)
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **ApplicationRenderingSystem**([**ING**::**IApplication**](./IApplication.md)* app)
-  `Destructor`:
	+  **~ApplicationRenderingSystem**()
-  `Properties`:
	+  [**ING**::**Rendering**::**IPipeline**]()* **defaultPipeline** **:** default rendering pipeline
		*  `Getter`: **GetDefaultPipeline**()
	+  [**ING**::**Rendering**::**IPipeline**]()* **pipeline** **:** currently using rendering pipeline
		*  `Getter`: **GetPipeline**()
		*  `Setter`: **SetPipeline**([**ING**::**Rendering**::**IPipeline**]()* newPipeline)**:** this method will set targetPipeline to newPipeline and pipeline will be set to targetPipeline in next frame
	+  [**ING**::**Rendering**::**IPipeline**]()* **targetPipeline** **:** rendering pipeline that will be used in next render frame
		*  `Getter`: **GetTargetPipeline**()
	+  [**ING**::**Rendering**::**IDevice**]()* **defaultDevice** **:** default rendering device
		*  `Getter`: **GetDefaultDevice**()
	+  [**ING**::**Rendering**::**IDevice**]()* **device** **:** currently using rendering device
		*  `Getter`: **GetDevice**()
		*  `Setter`: **SetDevice**([**ING**::**Rendering**::**IDevice**]()* newDevice)**:** this method will set targetDevice to newDevice and device will be set to targetDevice in next frame
	+  [**ING**::**Rendering**::**IDevice**]()* **targetDevice** **:** rendering device that will be used in next render frame
		*  `Getter`: **GetTargetDevice**()
-  `Methods`:
	+  bool **Init**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Init**())
	+  void **Release**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Release**())
	+  void **Start**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Start**())
	+  void **PreUpdate**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**PreUpdate**())
	+  void **Update**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Update**())
	+  void **LateUpdate**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**LateUpdate**())
	+  void **PreRender**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**PreRender**())
	+  void **Render**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**Render**())
	+  void **LateRender**() **:** override [**ING**::**IApplicationComponent**](./IApplicationComponent.md)::**LateRender**())