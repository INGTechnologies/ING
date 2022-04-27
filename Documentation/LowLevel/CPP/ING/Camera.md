# ING::Camera class #


## Basic Info ##
-  `Description`: **ING**::**Camera** is a class whose instance through which the player views the world,...
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Friends ##
-  class [**ING**::**CameraManager**](./CameraManager.md)

## Members ##
-  `Constructor`:
	+  **Camera**()
-  `Destructor`:
	+  **~Camera**()
-  `Properties`:
	+  [**ING**::**List**](./Utils/List.md)<**Camera***>::[**Node**](./Utils/List.Node.md)* **node** **:** represents the node in the camera list of [**ING**::**CameraManager**](./CameraManager.md)
        - `Getter` **:** **GetNode**()
	+  [**ING**::**List**](./Utils/List.md)<**Camera***>::[**Node**](./Utils/List.Node.md)* **nodeInScreenCameraList** **:** represents the node in the camera list of this camera's screen
        - `Getter` **:** **GetNodeInScreenCameraList**()
	+  [**ING**::**CameraId**](./CameraId.md) **id**
        - `Getter` **:** **GetId**()
	+  bool **isActive**
        - `Getter` **:** **IsActive**()
	+  [**ING**::**Math**::**RMatrix4x4**](./Math/RMatrix4x4.md) **viewMatrix** **:** the view matrix that will be used to rendering the scene with this camera
        - `Getter` **:** **GetViewMatrix**()
	+  [**ING**::**Math**::**RMatrix4x4**](./Math/RMatrix4x4.md) **projectionMatrix** **:** the projection matrix that will be used to rendering the scene with this camera
        - `Getter` **:** **GetProjectionMatrix**()
	+  [**ING**::**TransformM**](./TransformM.md) **transformM** **:** the camera transform that is stored in matrices
        - `Getter` **:** **GetTransform**()
        - `Setter` **:** **GetTransform**([**ING**::**TransformM**](./TransformM.md) **newTransformM**)
	+  float **fov** **:** the camera field of view
        - `Getter` **:** **GetFOV**()
        - `Setter` **:** **SetFOV**(float **newFOV**)
	+  float **nearPlane**
        - `Getter` **:** **GetFOV**()
        - `Setter` **:** **SetFOV**(float **newFOV**)
	+  float **farPlane**
        - `Getter` **:** **GetFOV**()
        - `Setter` **:** **SetFOV**(float **newFOV**)
	+  [**ING**::**Screen**](./Screen.md)* **screen**
        - `Getter` **:** **GetScreen**()
        - `Setter` **:** **SetScreen**([**ING**::**Screen**](./Screen.md)* **newScreen**)
	+  float **oldScreenWidth**
	+  float **oldScreenHeight**
	+  [**ING**::**Rendering**:**Scene**](./Rendering/Scene.md)* **screen**
        - `Getter` **:** **GetRenderingScene**()
        - `Setter` **:** **SetRenderingScene**([**ING**::**Rendering**:**Scene**](./Rendering/Scene.md)* **newScene**)
	+  [**ING**::**Rendering**:**ICameraData**](./Rendering/ICameraData.md)* **renderingData**
        - `Getter` **:** **GetRenderingData**()
        - `Setter` **:** **SetRenderingData**([**ING**::**Rendering**:**ICameraData**](./Rendering/ICameraData.md)* **newRenderingData**)
	+  [**ING**::**Rendering**:**IPipeline**](./Rendering/IPipeline.md)* **renderingPipeline**
        - `Getter` **:** **GetRenderingPipeline**()
        - `Setter` **:** **SetRenderingPipeline**([**ING**::**Rendering**:**IPipeline**](./Rendering/IPipeline.md)* **newRenderingPipeline**)
	+  [**ING**::**CameraTargetMode**](./CameraTargetMode.md)* **cameraTargetMode**
        - `Getter` **:** **GetTargetMode**()
        - `Setter` **:** **SetTargetMode**([**ING**::**CameraTargetMode**](./CameraTargetMode.md)* **newCameraTargetMode**)
	+  unsigned int **clientWidth**
        - `Getter` **:** **GetClientWidth**()
	+  unsigned int **clientHeight**
        - `Getter` **:** **GetClientHeight**()
-  `Methods`:
	+  void **Update**() **:** engine will call this method every frame