
/**
 *	Include Header
 */
#include "DrawableShader.h"



/**
 *	Include Shader Pass
 */
#include "../Pass/Pass.h"



/**
 *	Include Material
 */
#include <ING/Rendering/Material/Material.h>



/**
 *	Include API Manager
 */
#include <ING/Rendering/API/Manager/Manager.h>



/**
 *	Include API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		DrawableShader::DrawableShader(IDevice* device, const String& name) :
			IShader(device, name)
		{}

		DrawableShader::DrawableShader(const String& name) : DrawableShader(IAPI::GetInstance()->GetDevice(), name)
		{}

		DrawableShader::~DrawableShader() 
		{}



		/**
		 *	Release Methods
		 */
		void DrawableShader::Release() {

			IShader::Release();

		}


		/**
		 *	Properties
		 */
		void DrawableShader::SetFilterNameVector(const std::vector<String>& filterNameVector) {

			this->filterNameVector = filterNameVector;

			for (auto mat : GetMaterialList()) {

				mat->UpdateFilterNameVector();

			}

		}

	}

}