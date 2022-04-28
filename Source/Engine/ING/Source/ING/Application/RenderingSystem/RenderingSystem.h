#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



namespace ING {

	class IApplication;

	namespace Rendering {

		class Renderer;

		class IRenderer;

		class IPipeline;

		class IDevice;

	}

	class ING_API ApplicationRenderingSystem : public IApplicationComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationRenderingSystem(IApplication* application);
		~ApplicationRenderingSystem();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		Rendering::IPipeline* defaultPipeline;

		Rendering::IPipeline* pipeline;

		Rendering::IPipeline* targetPipeline;

		Rendering::IDevice* defaultDevice;

		Rendering::IDevice* device;

		Rendering::IDevice* targetDevice;

	public:
		Rendering::IPipeline* GetDefaultPipeline() { return defaultPipeline; }

		Rendering::IPipeline* GetPipeline() { return pipeline; }

		Rendering::IPipeline* GetTargetPipeline() { return targetPipeline; }

		void		SetPipeline(Rendering::IPipeline* pipeline);

		Rendering::IDevice* GetDefaultDevice() { return defaultDevice; }

		Rendering::IDevice* GetDevice() { return device; }

		Rendering::IDevice* GetTargetDevice() { return targetDevice; }

		void		SetDevice(Rendering::IDevice* device);



		/**
		 *	Methods
		 */
	public:
		virtual void	Start() override;

		virtual void	PreUpdate() override;
		virtual void	Update() override;
		virtual void	LateUpdate() override;

		virtual void	PreRender() override;
		virtual void	Render() override;
		virtual void	LateRender() override;

	};

}