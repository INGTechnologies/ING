# ING::Engine class #  


## Basic Info ##
-  `Description`: Represent for game engine and manage all engine's systems, managers,...
-  `Parent Class`: [**Board**](../Utils/Board/Board.md)<**ING**::**Engine**>
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **Engine**()
-  `Destructor`:
	+  **~Engine**()
-  `Properties`:
	+  **configuration** ([**Configuration**](../Configuration/Configuration.md)*)**:** store engine options,...
		*  `Getter`: **GetConfiguration**()
	+  **state** ([**EngineState**](State/EngineState.md))**:** game engine state
		*  `Getter`: **GetState**()
	+  **gameDir** (std::string)**:** game directory
	+  **gameDir_wstr** (std::wstring)**:** game directory but in std::wstring type
	+  **workingDir** (std::string)**:** current working directory
	+  **workingDir_wstr** (std::wstring):**:** current working directory but in std::wstring type
	+  **name** (std::string)**:** engine name
	+  **rootPath2AbsolutePath** (std::unordered_map<std::wstring,  std::wstring>)**:** root path to absolute path map
-  `Methods`:
	+  **Init**() (bool) (override [**Board**](../Utils/Board/Board.md)<**T**>::**Init**())
	+  **Run**() (bool) (override [**Board**](../Utils/Board/Board.md)<**T**>::**Run**())
	+  **Release**() (bool) (override [**Board**](../Utils/Board/Board.md)<**T**>::**Release**())
	+  **FrameUpdate**() (void)**:** engine will call this method every frame
	+  **AddRootPath**(const std::wstring& name, const std::wstring& value)**:** add new root path with name and value
	+  **Shutdown**() (void)**:** for shutting down engine

## Squares ##
-  [**ING::System**](../System/System.md)
-  [**ING::Core**](../Core/Core.md)
-  [**ING::Time**](../Time/Time.md)
-  [**ING::Profiler**](../Profiler/Profiler.md)
-  [**ING::ResourceManager**](../Resource/Manager/ResourceManager.md)
-  [**ING::EventManager**](../Event/Manager/EventManager.md)
-  [**ING::ThreadManager**](../Thread/Manager/ThreadManager.md)
-  [**ING::EngineThreadManager**](Thread/Manager/EngineThreadManager.md)
-  [**ING::Rendering::Engine**](../Rendering/Engine/Engine.md)
-  [**ING::ScreenManager**](../Screen/Manager/ScreenManager.md)
-  [**ING::WindowManager**](../Window/Manager/WindowManager.md)
-  [**ING::JobSystem**](../Job/System/JobSystem.md)
-  [**ING::CameraManager**](../Camera/Manager/CameraManager.md)
-  [**ING::ObjectManager**](../Object/Manager/ObjectManager.md)
-  [**ING::Scripting::Manager**](../Scripting/Manager/Manager.md)
-  [**ING::ApplicationManager**](../Application/Manager/ApplicationManager.md)
 
## Macros ##
+  **ING_CREATE_ENGINE**()**:** create engine
+  **ING_INIT_ENGINE**()**:** init engine
+  **ING_RUN_ENGINE**()**:** run engine
+  **ING_ENGINE_CONFIG_PROP**(T, name, value)**:** try add new configuration property
+  **ING_ENGINE_SET_CONFIG_PROP**(T, name, value)**:** set configuration property value by name
+  **ING_ENGINE_GET_CONFIG_PROP**(T, name, value)**:** get configuration property value by name