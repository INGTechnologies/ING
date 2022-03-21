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



		namespace StandardRP {

			struct ING_API Data {

				/**
				 *	Constructors And Destructor
				 */
			public:
				Data(Camera* camera);
				~Data();



				/**
				 *	Properties
				 */
			private:
				IRenderTargetView* mainRTV;

			public:
				IRenderTargetView* GetMainRTV () { return mainRTV; }

			};

		}

	}

}