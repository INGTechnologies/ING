
# ING Lowlevel Overview #

  

## **ING**::**Board**<**T**> and **ING**::**Square** ("Low Level Modules") ##

+ [**ING**::**Board**](./CPP/ING/Utils/Board.md)<**T**> is a class, singleton and has its own squares (a square is an object of type [**ING**::**Square**](./CPP/ING/Utils/Square.md)), virtual methods:
	- virtual bool **Init**()
	- virtual bool **Run**()
	- virtual bool **Release**()

+ [**ING**::**Square**](./CPP/ING/Utils/Square.md) is a class and has virtual methods:
	- virtual bool **Init**()
	- virtual bool **Run**()
	- virtual bool **Release**()

+ When [**ING::Board**](./CPP/ING/Engine.md)<**T**>::**Init** is called, it will call Init method of each square (the same as **Run** and **Release** methods)

## **ING**::**Engine** ##
+ [**ING::Engine**](./CPP/ING/Engine.md) is a class that inherited [**ING**::**Board**](./CPP/ING/Utils/Board.md)<**ING**::**Engine**> class, including these squares:

	- **System**

	- **Time**

	- **Profiler**

	- **ResourceManager**

	- **Rendering Engine**

	- ...

  

## How it works ##

+ [**ING::Engine**](./CPP/ING/Engine.md) class manages all systems and managers ([**ING::Engine**](./CPP/ING/Engine.md) is not application).

+ [**ING::IApplication**](./CPP/ING/IApplication.md) is a class whose instance is the application, managed by [**ING::ApplicationManager**](./CPP/ING/ApplicationManager.md) (1 Square of [**ING::Engine**](./CPP/ING/Engine.md)). **ING Engine** allows multiple applications in 1 program. When we use editor, **ING** creates 2 application (editor application and game application).

+ We built a dynamic linking library (**ING**.**dll**). It will be imported by runtime (runtime is an **".exe file"**). When we start game or editor, the runtime will create [**ING::Engine**](./CPP/ING/Engine.md), init [**ING::Engine**](./CPP/ING/Engine.md), create applications and run [**ING::Engine**](./CPP/ING/Engine.md).

## Projects ##

+ **Engine** has 3 main projects:

	- **ING** (create **ING**.**dll**)

	- **ING**.**Runtime** (create standalone game runtime)

	- **ING**.**Scripting**.**CSharp** (create c# engine library)

+ **Editor** is an application created with **ING Engine**. It has 2 main projects:

	- **EngineBuilderCaller** (call **ING**.**Tools**.**EngineBuilder** to build engine directory)

	- **ING**.**Editor**.**Runtime** (create editor runtime, support play in editor,...)