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



/**
 *	Include Mutex
 */
#include <mutex>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;



		class ING_API IPipeline
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IPipeline	(String name);
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
			String	name;

			IRenderer*	defaultRenderer;

			IRenderer*	renderer;

			IRenderer*	targetRenderer;

			bool		isRendering;

		public:
			String	GetName				() { return name; }

			IRenderer*	GetDefaultRenderer	() { return defaultRenderer; }

			IRenderer*	GetRenderer			() { return renderer; }

			IRenderer*	GetTargetRenderer	() { return targetRenderer; }

			void		SetRenderer			(IRenderer* renderer);

			bool		IsRendering			() { return isRendering; }



			/**
			 *	Methods
			 */
		public:
			virtual void SetupCamera		(IDeviceContext* context, Camera* camera);
			virtual void ClearRenderingData (Camera* camera);
			virtual bool Render				(IDeviceContext* context);

			void		 BeginRender		(IDeviceContext* context);
			void		 EndRender			(IDeviceContext* context);

		};

	}

}