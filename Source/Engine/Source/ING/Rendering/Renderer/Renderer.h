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

		class Device;

		class DeviceContext;



		class ING_API IRenderer
		{
			/**
			 *	Constructors And Destructor
			 */
		public:
			IRenderer	();
			~IRenderer	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Methods
			 */
		public:
			virtual void Render(Camera* camera, DeviceContext* context);

		};

	}

}