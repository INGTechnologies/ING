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
 *	Include Rendering CameraData
 */
#include <ING/Rendering/CameraData/CameraData.h>



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderTargetView;



		namespace StandardRP {

			struct ING_API CameraData : public ICameraData {

				/**
				 *	Constructors And Destructor
				 */
			public:
				CameraData(Camera* camera);
				~CameraData();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



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