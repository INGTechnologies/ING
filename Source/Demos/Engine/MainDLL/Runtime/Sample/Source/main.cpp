
/**
 *	Include IOStream
 */
#include <iostream>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Thread And Thread Manager
 */
#include <ING/Thread/Thread.h>

#include <ING/Thread/Manager/Manager.h>



/**
 *	Include Event And Event Manager
 */
#include <ING/Event/Event.h>

#include <ING/Event/Manager/Manager.h>



/**
 *	Include Rendering
 */
#include <ING/Rendering/Rendering.h>

using namespace ING::Rendering;



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h> 



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h> 



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h> 



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h> 



/**
 *	Include Rendering Shader
 */
#include <ING/Rendering/Shader/Shader.h> 

 

/**
 *	Include StandardRP Surface Shader
 */
#include <ING/Rendering/StandardRP/Shader/SurfaceShader/SurfaceShader.h> 
 


/**
 *	Include Window
 */
#include <ING/Window/Window.h> 



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h> 



/**
 *	Include Convertor
 */
#include <ING/Rendering/API/Convertor/Convertor.h> 



/**
 *	Include DX11 Convertor
 */
#include <ING/Rendering/API/DirectX11/Convertor/Convertor.h> 



/**
 *	Include Time
 */
#include <ING/Time/Time.h> 



/**
 *	Include Math
 */
#include <ING/Math/Math.h> 

using namespace ING::Math;



/**
 *	Include Color
 */
#include <ING/Color/Color.h> 



/**
 *	Include ECS
 */
#include <ING/ECS/ECS.h> 



/**
 *	Include Profiler
 */
#include <ING/Profiler/Profiler.h> 



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h> 



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h> 



/**
 *	Include Rendering Scene
 */
#include <ING/Rendering/Scene/Scene.h> 



/**
 *	Include Rendering Drawable Filter
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



/**
 *	Include Rendering Shader
 */
#include <ING/Rendering/Shader/Shader.h>



/**
 *	Include Rendering Shader Pass
 */
#include <ING/Rendering/Shader/Pass/Pass.h>



/**
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



/**
 *	Include Rendering Drawable Material
 */
#include <ING/Rendering/Material/DrawableMaterial/DrawableMaterial.h>



/**
 *	Include Rendering Vertex Shader
 */
#include <ING/Rendering/API/Shader/VertexShader/VertexShader.h>



/**
 *	Include Rendering Pixel Shader
 */
#include <ING/Rendering/API/Shader/PixelShader/PixelShader.h>



/**
 *	Include Rendering Input Layout
 */
#include <ING/Rendering/API/InputLayout/InputLayout.h>



/**
 *	Include Rendering Mesh
 */
#include <ING/Rendering/Mesh/Mesh.h>



using namespace ING;

#include <ING/Profiler/Session/Session.h>

#include <ING/Rendering/Pass/Pass.h>
#include <ING/Rendering/Pipeline/Pipeline.h>

#include <ING/Rendering/StandardRP/Pipeline/Pipeline.h>
#include <ING/Rendering/StandardRP/Pass/First/First.h>
#include <ING/Rendering/StandardRP/Pass/Final/Final.h>
#include <ING/Rendering/Drawable/MeshDrawable/MeshDrawable.h>

#include <ING/Rendering/SubRP/Pipeline/Pipeline.h>
#include <ING/Rendering/SubRP/Pass/Pass.h>

#include <ING/Rendering/System/System.h>

#include <ING/Rendering/Renderer/Renderer.h>

#include <ING/Rendering/API/State/RasterizerState/RasterizerState.h>

#include <ING/Rendering/API/BindFlag/BindFlag.h>


#include <ING/Scene/Scene.h>



#include <ING/Scripting/CSharp/Language/Language.h>
#include <ING/Scripting/CSharp/Context/Context.h>
#include <ING/Scripting/CSharp/Assembly/Assembly.h>
#include <ING/Scripting/CSharp/Assembly/Component/Creator/Creator.h>
#include <ING/Scripting/Manager/Manager.h>

#include <ING/Scripting/CSharp/Assembly/Component/EngineComponent/EngineComponent.h>

#include <ING/Scripting/CSharp/Method/OuternalMethod/OuternalMethod.h>
#include <ING/Scripting/CSharp/Class/Class.h>

#include <ING/Rendering/API/APIFlag.h>

#include <ING/Object/Object.h>
#include <ING/Object/Manager/Manager.h>



/* Custom Rendering Pass Class */
class DemoPass : public Rendering::SubRP::Pass {

public:
	DemoPass(const std::string& name);
	~DemoPass();

public:
	virtual bool CustomRender(Rendering::IDeviceContext* context, Camera* camera, const Rendering::SubRP::PassInput& input, Rendering::SubRP::PassOutput& output) override;

};


DemoPass::DemoPass(const std::string& name) : Pass(name) {



}

bool DemoPass::CustomRender(
	Rendering::IDeviceContext* context, 
	Camera* camera, 
	const Rendering::SubRP::PassInput& input, 
	Rendering::SubRP::PassOutput& output
) {

	Rendering::SubRP::PassOutput passOutput;

	IRenderer* renderer = Rendering::System::GetInstance()->GetPipeline()->GetRenderer();



	renderer->RenderDrawables(camera, "Opaque", "Demo Pass");



	output += passOutput;

	return true;
}



static ECS::Repository* repository;
static ECS::TransformSystem* transformSystem;



#include <filesystem>



int main() {

	/* Create Application */ 
	ING::Application::CreateInstance();


	APPLICATION_CONFIG_PROP(std::vector<ING::Scripting::CSharp::IAssemblyComponentCreator*>, "ING::Scripting::CSharp::Language::assemblyComponentCreators", {

		new ING::Scripting::CSharp::AssemblyComponentCreator<ING::Scripting::CSharp::EngineAssemblyComponent>("Content")

	});


	/* Init Application */
	if (!ING::Application::GetInstance()->Init()) return 1;



	/* On "RUN" */
	ING::Application::GetInstance()->GetEvent("RUN")->AddListener([](Event* event) {


		
		Scripting::CSharp::Language* language = (Scripting::CSharp::Language*)Scripting::Manager::GetInstance()->GetLanguage("CSharp");

		Scripting::CSharp::Context* context = (Scripting::CSharp::Context*)language->GetContext("Content.CSharpAssembly");

		Scripting::CSharp::Assembly* assembly = context->GetAssembly();

		Scripting::CSharp::Class* class1;

		Scripting::CSharp::OuternalMethod* outernalMethod1;

		class1 = context->GetClass(assembly, "Class1", "CSharpAssembly");

		outernalMethod1 = (Scripting::CSharp::OuternalMethod*)(
			context->GetOuternalMethod(class1, ".Class1::Main()")
		);

		outernalMethod1->Execute(0,0);



		/* Focus On Main Window */
		WindowManager::GetInstance()->GetMainWindow()->Focus();



		/* Create ECS Repository */
		repository = new ECS::Repository();
		repository->SetActive(true);



		/* Create ECS Component Systems */
		transformSystem = repository->CreateComponentSystem<ECS::TransformSystem>();
		ECS::CameraSystem* cameraSystem = repository->CreateComponentSystem<ECS::CameraSystem>();
		ECS::MeshDrawableSystem* meshDrawableSystem = repository->CreateComponentSystem<ECS::MeshDrawableSystem>();



		/**
		 *	Create Custom Rendering Pass 
		 */
		Rendering::IPass* demoPass = new DemoPass("Demo Pass");

		Rendering::System* renderingSystem = Rendering::System::GetInstance();

		Rendering::StandardRP::Pipeline* mainPipeline = (Rendering::StandardRP::Pipeline*)renderingSystem->GetTargetPipeline();

		Rendering::SubRP::Pipeline* subPipeline = mainPipeline->GetSubPipeline("After First Pipeline");

		subPipeline->AddPass(demoPass);

		mainPipeline->SetMode(Rendering::StandardRP::MODE_FORWARD);



		/* Create Camera Entity */
		ECS::Entity* camEntity = repository->CreateEntity({

			transformSystem,

			cameraSystem

		});

		ECS::CameraPtr camera = cameraSystem->GetComponent(camEntity);

		camera->SetActive(true);
		camera->SetScreen(ScreenManager::GetInstance()->GetMainScreen());
		camera->SetFOV(3.14f / 180.0f * 60.0f);
		camera->SetFarPlane(1000.0f);
		camera->SetNearPlane(0.1f);



		/* Create Rendering Scene */
		Rendering::Scene* renderingScene = new Rendering::Scene("Sample Rendering Scene");

		renderingScene->ContainLayers({
		
			0
			
		});

		camera->SetRenderingScene(renderingScene);



		/* Create Shader */
		IShader* shader = new Rendering::StandardRP::SurfaceShader("DemoShader");

		shader->AddPass("Demo Pass");
		shader->GetPass("Demo Pass")->AddState(
			IRasterizerState::Create("RSState", {
		
				FILL_WIREFRAME,
				CULL_NONE
			
			})
		);
		shader->GetPass("Demo Pass")->AddShader("VertexShader",
			IVertexShader::CreateFromHLSL(L"Content:/Assets/Shaders/DemoVS.hlsl")
		);
		shader->GetPass("Demo Pass")->AddShader("PixelShader",
			IPixelShader::CreateFromHLSL(L"Content:/Assets/Shaders/DemoPS.hlsl")
		);
		shader->GetPass("Demo Pass")->SetInputLayout(
			IInputLayout::Create(
				{

					{ "POSITION", 0, FORMAT_R32G32B32_FLOAT, 0, 0, INPUT_PER_VERTEX_DATA, 0 }

				},
				shader->GetPass("Demo Pass")->GetShader("VertexShader")
			)
		);
		shader->SetPropertyVector({
			ShaderProperty("color", sizeof(RFloat4)),
			ShaderProperty("color2", sizeof(RFloat4))
		});
		shader->SetViewVector({



		});
		shader->SetCBufferVector({



		});

		/* Create Material */
		IMaterial* material = new Rendering::DrawableMaterial("DemoMat", shader);

		material->SetProperty<RFloat4>("color", { 1,1,0,1 });
		material->SetProperty<RFloat4>("color2", { 0,1,0,1 });

		/* Create Mesh */
		IMesh* mesh = new Mesh<RFloat3>(
			{
				{0,0,0.0f},
				{0,1,0.0f},
				{1,0,0.0f}
			},
			{ 0, 1, 2 }
		);
		mesh->BuildBuffers();

		ECS::Entity* entity = repository->CreateEntity({		
			transformSystem,
			meshDrawableSystem			
		});

		ECS::TransformPtr transform = transformSystem->GetComponent(entity);
		transform->localPosition = RVector3(0,0,8.0f);

		ECS::MeshDrawablePtr meshDrawable = meshDrawableSystem->GetComponent(entity);
		meshDrawable->SetMesh(mesh);
		meshDrawable->SetMaterial(material);
		meshDrawable->SetActive(true);
		meshDrawable->SetFilters({

			"Opaque"

		});
		meshDrawable->SetLayer(0);







		ECS::Entity* entity2 = repository->CreateEntity({
		
			transformSystem
			
		});



		ECS::Entity* entity3 = repository->CreateEntity({

			transformSystem

		});

		ECS::Entity* entity4 = repository->CreateEntity({

			transformSystem

		});

		
		transformSystem->AppendChild(entity4, entity2);
		transformSystem->AppendChild(entity4, entity3);



		for (ECS::Transform& transform : *transformSystem) {

			int a = 5;

		}



		for (ECS::Transform& transform : *transformSystem) {

			int a = 5;

		}

		transformSystem->RemoveChild(entity4, entity2);



		for (ECS::Transform& transform : *transformSystem) {

			int a = 5;

		}

		repository->ReleaseEntity(entity2);



		for (ECS::Transform& transform : *transformSystem) {

			int a = 5;

		}



		ING::Scene* scene = new ING::Scene(

			{



			},

			{

				new ECS::SceneComponent()

			}

		);


		
	});



	ING::Application::GetInstance()->GetEvent("END_FRAME_UPDATE")->AddListener([](Event* e) {

		ECS::Entity* entity = repository->CreateEntity({

			transformSystem

		});

		repository->ReleaseEntity(entity);



		/**
		 *	Show FPS In Window Title
		 */
		static float t = 0;

		t += Time::GetDeltaTime();

		if (t >= 1.0f) {

			t = 0;

			WindowManager::GetInstance()->GetMainWindow()->SetTitle(
				WString(L"FPS: ") + WString(Time::GetFPS()) + 
				WString(L"     ") +
				WString(L"Frametime: ") + WString(Time::GetDeltaTime() * 1000.0f) + WString(L"ms")
			);

		}

	});


	/* Run Application */
	if (!ING::Application::GetInstance()->Run()) return 1;

	return 0;
}