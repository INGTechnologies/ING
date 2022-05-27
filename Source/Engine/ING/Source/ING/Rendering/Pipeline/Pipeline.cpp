
/**
 * Include Header
 */
#include "Pipeline.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>




namespace ING {

	namespace Rendering {

		/**IIDeviceContext
		 *	Constructors And Destructor
		 */
		IPipeline::IPipeline	(const String& name) :
			renderer(0)
		{

			this->name = name;

			isRendering = false;

		}

		IPipeline::~IPipeline	() {



		}



		/**
		 *	Release Methods
		 */
		void IPipeline::Release() {

			for (unsigned int i = 0; i < passVector.size();) {

				passVector[i]->Release();

			}

			passVector.clear();

			for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetRenderingPipeline() == this) {

					ClearCameraData(camera);

					camera->SetRenderingPipeline(0);

				}

			}

			delete this;

		}



		/**
		 *	Methods
		 */
		void IPipeline::AddPass(IPass* pass) {

			AddPass(pass, passVector.size());

		}

		void IPipeline::AddPass(IPass* pass, unsigned int index) {

			if (passVector.size() == index) {

				passVector.push_back(pass);

			}
			else {

				passVector.insert(passVector.begin() + index, pass);

				unsigned int passCount = passVector.size();

				for (unsigned int i = index + 1; i < passCount; ++i) {

					name2PassIndex[passVector[i]->GetName()]++;

				}

			}

			name2PassIndex[pass->GetName()] = index;

			pass->parent = 0;

			pass->SetPipeline(this);

		}

		void IPipeline::RemovePass(unsigned int index) {

			String passName = GetPass(index)->GetName();

			GetPass(index)->SetPipeline(0);

			passVector.erase(passVector.begin() + index);

			unsigned int passCount = passVector.size();

			for (unsigned int i = index; i < passCount; ++i) {

				name2PassIndex[passVector[i]->GetName()]--;

			}

			name2PassIndex.erase(passName);
			
		}

		void IPipeline::RemovePass(const String& name) {

			RemovePass(name2PassIndex[name]);

		}

		void IPipeline::RemovePass(IPass* pass) {

			RemovePass(pass->GetName());

		}

		void IPipeline::SetupCamera	(IDeviceContext* context, Camera* camera) {



		}

		void IPipeline::ClearCameraData(Camera* camera) {

			camera->SetRenderingData(0);

		}

		bool IPipeline::Render	(IDeviceContext* context) {

			BeginRender(context);

			EndRender(context);

			return true;
		}

		void IPipeline::BeginRender(IDeviceContext* context) {

			isRendering = true;

			for (Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetRenderingPipeline() == this && camera->GetRenderingData() == 0) {

					SetupCamera(context, camera);

				}

			}
		}

		void IPipeline::EndRender(IDeviceContext* context) {

			isRendering = false;
		}

	}

}