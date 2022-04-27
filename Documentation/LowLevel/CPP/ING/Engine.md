# ING::Engine class #  


## Basic Info ##
-  `Description`: Represents game engine and manages all engine's systems, managers,...
-  `Parent Class`: [**ING**::**Board**](./Utils/Board.md)<[**ING**::**Engine**](./Engine.md)>
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **Engine**()
-  `Destructor`:
	+  **~Engine**()
-  `Properties`:
	+  [**ING**::**Configuration**](./Configuration.md)* **configuration**
		*  `Getter`: **GetConfiguration**()
	+  [**ING**::**EngineState**](./EngineState.md) **state**
		*  `Getter`: **GetState**()
	+  std::string **gameDir** **:** game directory
	+  std::wstring **gameDir_wstr** **:** game directory but in std::wstring type
	+  std::string **workingDir** **:** current working directory
	+  std::wstring **workingDir_wstr** :**:** current working directory but in std::wstring type
	+  std::string **name**
	+  std::unordered_map<std::wstring,  std::wstring> **rootPath2AbsolutePath** **:** root path to absolute path map
-  `Methods`:
	+  virtual bool **Init**() **:** override [**ING**::**Board**](./Utils/Board.md)<**[**ING**::**Engine**](./Engine.md)**>::**Init**()
	+  virtual bool **Run**() **:** override [**ING**::**Board**](./Utils/Board.md)<**[**ING**::**Engine**](./Engine.md)**>::**Run**()
	+  virtual bool **Release**() **:** override [**ING**::**Board**](./Utils/Board.md)<**[**ING**::**Engine**](./Engine.md)**>::**Release**()
	+  void **FrameUpdate**() **:** engine will call this method every frame
	+  void **AddRootPath**(const std::wstring& name, const std::wstring& value)**:** add new root path with name and value
	+  void **Shutdown**() **:** for shutting down engine

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