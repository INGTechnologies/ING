
# ING Lowlevel Overview #

  

## Board and Square ("Low Level Modules") ##

+ **Board** is a class, singleton and has its own squares, virtual methods:
	- **Init**() (bool)
	- **Run**() (bool)
	- **Release**() (bool)

+ **Square** is a class and has virtual methods:
	- **Init**() (bool)
	- **Run**() (bool)
	- **Release**() (bool)

+ [**ING::Engine**](CPP/Engine/Engine.md) is a class that inherited **Board** class, including these squares:

	- System

	- Time

	- Profiler

	- ResourceManager

	- Rendering Engine

	- ...

+ When [**ING::Engine**](CPP/Engine/Engine.md)::**Init** is called, it will call Init method of each square (the same as Run and Release methods)

  

## How it works ##

+ [**ING::Engine**](CPP/Engine/Engine.md) class manages all systems and managers ([**ING::Engine**](CPP/Engine/Engine.md) is not application).

+ [**ING::IApplication**](CPP/Application/IApplication.md) is a class whose instance is the application, managed by [**ING::ApplicationManager**](CPP/Application/Manager/ApplicationManager.md) (1 Square of [**ING::Engine**](CPP/Engine/Engine.md)). ING Engine allows multiple applications in 1 program. When we use editor, ING creates 2 application (editor application and game application).

+ We built a dynamic linking library (ING.dll). It will be imported by runtime (runtime is an ".exe file"). When we start game or editor, the runtime will create [**ING::Engine**](CPP/Engine/Engine.md), init [**ING::Engine**](CPP/Engine/Engine.md), create applications and run [**ING::Engine**](CPP/Engine/Engine.md).

## Projects ##

+ Engine has 3 main projects:

	- ING (create ING.dll)

	- ING.Runtime (create standalone game runtime)

	- ING.Scripting.CSharp (create c# engine library)

+ Editor is an application created with ING Engine. It has 2 main projects:

	- EngineBuilderCaller (call ING.Tools.EngineBuilder to build engine directory)

	- ING.Editor.Runtime (create editor runtime, support play in editor,...)