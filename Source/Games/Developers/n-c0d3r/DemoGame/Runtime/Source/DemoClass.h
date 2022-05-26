
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
#include <ING/Reflection/Type/Type.h>
#include <ING/Reflection/Namespace/Namespace.h>
#include <ING/Reflection/Object/Object.h>
#include <ING/Reflection/Object/Function/Function.h>
#include <ING/Reflection/Context/Context.h>
#include <ING/Reflection/Class/Class.h>



#include <ING/Rendering/Shader/Shader.h>
#include <ING/Rendering/Shader/DrawableShader/DrawableShader.h>
#include <ING/Rendering/Material/Material.h>
#include <ING/Rendering/Material/DrawableMaterial/DrawableMaterial.h>
#include <ING/Rendering/Material/Event/UpdateFilterNameVectorEvent/UpdateFilterNameVectorEvent.h>
#include <ING/Rendering/Drawable/Drawable.h>
#include <ING/Rendering/Drawable/MeshDrawable/MeshDrawable.h>
#include <ING/Rendering/Layer/System/System.h>




using namespace ING::Rendering;
using namespace ING;
using namespace ING::Reflection;
using namespace ING::UI;



namespace Demo {

	class DemoClassA : public Reflection::IObject {

		ING_REFLECT_CLASS(DemoClassA, IObject)

	protected:
		void Constructor(int b);

	public:
		unsigned int b;

		void		 Test();

	};

	class DemoClass : public DemoClassA {

		ING_REFLECT_CLASS(DemoClass, DemoClassA)

	protected:
		void Constructor(int a);

	public:
		unsigned int a;

		void		 Test();

	};

}