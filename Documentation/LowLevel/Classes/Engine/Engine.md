# ING::Engine class #

  

## Basic Info ##
-  `Description`: Represent for game engine and manage all engine's systems, managers,...
-  `Parent Class`: [**Board**]()<**ING**::**Engine**>
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **Engine()**
-  `Destructor`:
	+  **~Engine()**
-  `Properties`:
	+  **configuration** (Configuration*)**:** store engine options,...
		*  `Getter`: **GetConfiguration**()
	+  **state** (EngineState)**:** game engine state
		*  `Getter`: **GetState**()
	+  **gameDir** (std::string)**:** game directory
	+  **gameDir_wstr** (std::wstring)**:** game directory but in std::wstring type
	+  **workingDir** (std::string)**:** current working directory
	+  **workingDir_wstr** (std::wstring):**:** current working directory but in std::wstring type
	+  **name** (std::string)**:** engine name
	+  **rootPath2AbsolutePath** (std::unordered_map<std::wstring,  std::wstring>)**:** root path to absolute path map
-  `Methods`:
	+  **FrameUpdate**() (void)**:** engine will call this method every frame
	+  **AddRootPath**(const std::wstring& name, const std::wstring& value)**:** add new root path with name and value
	+  **Init**() (bool) (override [**Board**]()<**T**>::**Init**())
	+  **Run**() (bool) (override [**Board**]()<**T**>::**Run**())
	+  **Release**() (bool) (override [**Board**]()<**T**>::**Release**())
	+  **Shutdown**() (void)**:** for shutting down engine
 
## Macros ##
+  **ING_CREATE_ENGINE**()**:** create engine
+  **ING_INIT_ENGINE**()**:** init engine
+  **ING_RUN_ENGINE**()**:** run engine
+  **ING_ENGINE_CONFIG_PROP**(T, name, value)**:** try add new configuration property
+  **ING_ENGINE_SET_CONFIG_PROP**(T, name, value)**:** set configuration property value by name
+  **ING_ENGINE_GET_CONFIG_PROP**(T, name, value)**:** get configuration property value by name