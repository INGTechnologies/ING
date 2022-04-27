# ING::Engine class #  


## Basic Info ##
-  `Description`: Represent for game engine and manage all engine's systems, managers,...
-  `Parent Class`: [**Board**](./Utils/Board.md)<[**ING**::**Engine**](./Engine.md)>
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **Engine**()
-  `Destructor`:
	+  **~Engine**()
-  `Properties`:
	+  **configuration** ([**Configuration**](./Configuration.md)*)**:** store engine options,...
		*  `Getter`: **GetConfiguration**()
	+  **state** ([**EngineState**](./EngineState.md))**:** game engine state
		*  `Getter`: **GetState**()
	+  **gameDir** (std::string)**:** game directory
	+  **gameDir_wstr** (std::wstring)**:** game directory but in std::wstring type
	+  **workingDir** (std::string)**:** current working directory
	+  **workingDir_wstr** (std::wstring):**:** current working directory but in std::wstring type
	+  **name** (std::string)**:** engine name
	+  **rootPath2AbsolutePath** (std::unordered_map<std::wstring,  std::wstring>)**:** root path to absolute path map
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