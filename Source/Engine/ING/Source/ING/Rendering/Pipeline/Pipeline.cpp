
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



/**
 *	Include Rendering CameraData
 */
#include <ING/Rendering/CameraData/CameraData.h>



/**
 *	Include Rendering SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>




namespace ING {

	namespace Rendering {

		ING_BEGIN_REFLECTED_CLASS
			(C_Pipeline, Reflection::C_Object)

			ING_CLASS_CONSTRUCTOR
				(C_Pipeline, const String&)
				.ACCESS	(CLASS_MEMBER_ACCESS_PROTECTED)
				.TAG	(CLASS_MEMBER_TAG_VISIBLE_EVERYWHERE);

		ING_END_REFLECTED_CLASS
			()



		/**
		 *	Constructor
		 */
		void C_Pipeline::Constructor(const String& name) {

			this->name = name;

			this->renderer = 0;

			isRendering = false;

			cameraDataClass = C_CameraData::GetType(GetClass()->GetContext());

		}



		/**
		 *	Release Methods
		 */
		void C_Pipeline::Release() {

			for (unsigned int i = 0; i < passVector.size();) {

				passVector[i]->Release();

			}

			passVector.clear();

			for (C_Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetRenderingPipeline() == this) {

					ClearCameraData(camera);

					camera->SetRenderingPipeline(0);

				}

			}

			Reflection::C_Object::Release();

		}



		/**
		 *	Methods
		 */
		void C_Pipeline::AddPass(C_Pass* pass) {

			AddPass(pass, passVector.size());

		}

		void C_Pipeline::AddPass(C_Pass* pass, unsigned int index) {

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

		void C_Pipeline::RemovePass(unsigned int index) {

			String passName = GetPass(index)->GetName();

			GetPass(index)->SetPipeline(0);

			passVector.erase(passVector.begin() + index);

			unsigned int passCount = passVector.size();

			for (unsigned int i = index; i < passCount; ++i) {

				name2PassIndex[passVector[i]->GetName()]--;

			}

			name2PassIndex.erase(passName);
			
		}

		void C_Pipeline::RemovePass(const String& name) {

			RemovePass(name2PassIndex[name]);

		}

		void C_Pipeline::RemovePass(C_Pass* pass) {

			RemovePass(pass->GetName());

		}

		void C_Pipeline::SetupCamera	(IDeviceContext* context, C_Camera* camera) {

			C_CameraData* cameraData = (C_CameraData*)cameraDataClass->RCreateInstance(camera);

			camera->SetRenderingData(cameraData);

		}

		void C_Pipeline::ResizeCamera(IDeviceContext* context, C_Camera* camera) {



		}
		
		void C_Pipeline::ClearCameraData(C_Camera* camera) {

			camera->GetRenderingData()->Release();

			camera->SetRenderingData(0);

		}

		bool C_Pipeline::Render	(IDeviceContext* context) {

			BeginRender(context);

			EndRender(context);

			return true;
		}

		void C_Pipeline::BeginRender(IDeviceContext* context) {

			isRendering = true;

			for (C_Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetRenderingPipeline() == this && camera->GetRenderingData() == 0) {

					SetupCamera(context, camera);

				}

			}
		}

		void C_Pipeline::EndRender(IDeviceContext* context) {

			isRendering = false;

			for (C_Camera* camera : CameraManager::GetInstance()->GetCameraList()) {

				if (camera->GetTargetMode() == CAMERA_TARGET_SCREEN) {

					camera->GetScreen()->GetSwapChain()->Present();

				}

			}
			
		}

	}

}