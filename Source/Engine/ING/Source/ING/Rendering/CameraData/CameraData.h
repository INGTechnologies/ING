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
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class C_Camera;



	namespace Rendering {

		class ING_API C_CameraData : public C_Object {

			ING_REFLECT_CLASS(C_CameraData, C_Object)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor(C_Camera* camera);



			/**
			 *	Release Method
			 */
		public:
			virtual void	Release();



			/**
			 *	Properties
			 */
		private:
			C_Camera*		camera;

		public:
			C_Camera*		GetCamera () { return camera; }

		};

	}

}