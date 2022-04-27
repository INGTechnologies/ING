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

		class IRenderTargetView;


		struct ING_API ICameraData {

			/**
			 *	Constructors And Destructor
			 */
		public:
			ICameraData		(Camera* camera);
			~ICameraData	();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Camera*				camera;

		public:
			Camera*				GetCamera () { return camera; }

		};

	}

}