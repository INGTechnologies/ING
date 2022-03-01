#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class Device;

		class DeviceContext;

		class IPass;



		class ING_API IPipeline
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IPipeline	(std::string name);
			~IPipeline	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		protected:
			std::string	name;

			IRenderer*	defaultRenderer;

			IRenderer*	renderer;

			IRenderer*	targetRenderer;

		public:
			std::string	GetName() { return name; }

			IRenderer*	GetDefaultRenderer() { return defaultRenderer; }

			IRenderer*	GetRenderer() { return renderer; }

			IRenderer*	GetTargetRenderer() { return targetRenderer; }

			void		SetRenderer(IRenderer* renderer);



			/**
			 *	Methods
			 */
		public:
			virtual void Setup	(DeviceContext* context, Camera* camera);
			virtual void Render	(DeviceContext* context);

		};

	}

}