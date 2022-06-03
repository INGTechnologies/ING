
/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include ApplicationWindowSystem
 */
#include <ING/Application/WindowSystem/WindowSystem.h>



/**
 *	Include ApplicationRenderingSystem
 */
#include <ING/Application/RenderingSystem/RenderingSystem.h>



/**
 *	Include Window
 */
#include <ING/Window/Window.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Math
 */
#include <ING/Math/Math.h>



/**
 *	Include Rendering Pipeline
 */
#include <ING/Rendering/Pipeline/Pipeline.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include UI Style
 */
#include <ING/UI/Style/Style.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



/**
 *	Include UI Canvas
 */
#include <ING/UI/Canvas/Canvas.h>



/**
 *	Include Node
 */
#include <ING/UI/Node/Node.h>



/**
 *	Include UISystem
 */
#include <ING/Application/UISystem/UISystem.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



/**
 *	Include Type
 */
#include <ING/Reflection/Type/Type.h>



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>



#include <ING/Rendering/Shader/Shader.h>
#include <ING/Rendering/Shader/DrawableShader/DrawableShader.h>
#include <ING/Rendering/Material/Material.h>
#include <ING/Rendering/Material/DrawableMaterial/DrawableMaterial.h>
#include <ING/Rendering/Material/Event/UpdateFilterNameVectorEvent/UpdateFilterNameVectorEvent.h>
#include <ING/Rendering/Drawable/Drawable.h>
#include <ING/Rendering/Drawable/MeshDrawable/MeshDrawable.h>
#include <ING/Rendering/Layer/System/System.h>

#include <ING/Actor/Actor.h>
#include <ING/Pawn/Pawn.h>
#include <ING/Character/Character.h>
#include <ING/Actor/Component/Component.h>
#include <ING/Object/Manager/Manager.h>




using namespace ING::Rendering;
using namespace ING;
using namespace ING::Reflection;
using namespace ING::UI;



static IApplication* application = 0;
static IWindow* mainWindow = 0;



#include "DemoClass.h"
#include "DemoActor.h"



#include <functional>




int DemoFunc() {


	return 5;
}



struct S_DemoStruct {

	ING_REFLECT_STRUCT(S_DemoStruct, S_Base);

	int a;
	int b;
	int c;
	bool d;

};



ING_BEGIN_REFLECTED_STRUCT
	(S_DemoStruct, S_Base)



ING_END_REFLECTED_STRUCT
	()


#ifdef USE_MSVC
int wmain(int argc, wchar_t* argv_cstr[], wchar_t* envp[])
{

	std::vector<WString> argv(argc);

	for (unsigned int i = 0; i < argc; ++i) {

		argv[i] = ToWString(argv_cstr[i]);

	}

	ING::Engine::CreateInstance(argv);

	if (!ING::Engine::GetInstance()->Init()) return 1;

	ING::Engine::GetInstance()->GetEvent("RUN")->AddListener([](Event* e) {

		Reflection::Context* ctx = new Reflection::Context();

		Demo::DemoClass::CreateType(ctx);

		C_Actor::CreateType(ctx);

		C_ActorComponent::CreateType(ctx);

		C_Pawn::CreateType(ctx);

		DemoActor::CreateType(ctx);

		S_DemoStruct::CreateType(ctx);



		S_DemoStruct ds = S_DemoStruct::CreateInstance(4,5,6,true);



		S_DemoStruct::ReleaseType(ctx);

		DemoActor::ReleaseType(ctx);

		C_Pawn::ReleaseType(ctx);

		C_ActorComponent::ReleaseType(ctx);

		C_Actor::ReleaseType(ctx);

		Demo::DemoClass::ReleaseType(ctx);

	});

	if (!ING::Engine::GetInstance()->Run()) return 1;

	return 0;
}
#endif