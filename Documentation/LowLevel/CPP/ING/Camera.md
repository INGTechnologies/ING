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
	+  [**List**](./Utils/List.md)<**Camera***>::[**Node**](./Utils/List.Node.md)* **node** **:** represents the node in the camera list of [**ING**::**CameraManager**](./CameraManager.md)
        - `Getter` **:** **GetNode**()
	+  [**List**](./Utils/List.md)<**Camera***>::[**Node**](./Utils/List.Node.md)* **nodeInScreenCameraList** **:** represents the node in the camera list of this camera's screen
        - `Getter` **:** **GetNodeInScreenCameraList**()
	+  [**CameraId**](./CameraId.md) **id**
        - `Getter` **:** **GetId**()
	+  bool **isActive**
        - `Getter` **:** **IsActive**()
	+  [**Math**::**RMatrix4x4**](./Math/RMatrix4x4.md) **viewMatrix** **:** the view matrix that will be used to rendering the scene with this camera
        - `Getter` **:** **GetViewMatrix**()
	+  [**Math**::**RMatrix4x4**](./Math/RMatrix4x4.md) **projectionMatrix** **:** the projection matrix that will be used to rendering the scene with this camera
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
-  `Methods`:
	+  **Init**() (bool) (override [**Board**](./Utils/Board.md)<**T**>::**Init**())
	+  **Run**() (bool) (override [**Board**](./Utils/Board.md)<**T**>::**Run**())
	+  **Release**() (bool) (override [**Board**](./Utils/Board.md)<**T**>::**Release**())
	+  **FrameUpdate**() (void)**:** engine will call this method every frame
	+  **AddRootPath**(const std::wstring& name, const std::wstring& value)**:** add new root path with name and value
	+  **Shutdown**() (void)**:** for shutting down engine

## Squares ##
-  [**ING::System**](./System.md)
-  [**ING::Core**](./Core.md)
-  [**ING::Time**](./Time.md)
-  [**ING::Profiler**](./Profiler.md)
-  [**ING::ResourceManager**](./ResourceManager.md)
-  [**ING::EventManager**](./EventManager.md)
-  [**ING::ThreadManager**](./ThreadManager.md)
-  [**ING::EngineThreadManager**](./EngineThreadManager.md)
-  [**ING::Rendering::Engine**](./Rendering/Engine.md)
-  [**ING::ScreenManager**](./ScreenManager.md)
-  [**ING::WindowManager**](./WindowManager.md)
-  [**ING::JobSystem**](./JobSystem.md)
-  [**ING::CameraManager**](./CameraManager.md)
-  [**ING::ObjectManager**](./ObjectManager.md)
-  [**ING::Scripting::Manager**](./Scripting/Manager.md)
-  [**ING::ApplicationManager**](./ApplicationManager.md)
 
## Macros ##
+  **ING_CREATE_ENGINE**()**:** create engine
+  **ING_INIT_ENGINE**()**:** init engine
+  **ING_RUN_ENGINE**()**:** run engine
+  **ING_ENGINE_CONFIG_PROP**(T, name, value)**:** try add new configuration property
+  **ING_ENGINE_SET_CONFIG_PROP**(T, name, value)**:** set configuration property value by name
+  **ING_ENGINE_GET_CONFIG_PROP**(T, name, value)**:** get configuration property value by name