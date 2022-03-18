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

		class IDevice;

		class IDeviceContext;

		class IPass;



		class ING_API IDrawable
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDrawable	();
			~IDrawable	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}