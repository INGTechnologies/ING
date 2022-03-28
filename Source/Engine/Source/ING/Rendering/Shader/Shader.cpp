
/**
 *	Include Header
 */
#include "Shader.h"



/**
 *	Include Shader Pass
 */
#include "Pass/Pass.h"



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



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IShader::IShader(IDevice* device, const std::string& name) : device(0) {

			this->name = name;

			this->device = device;

		}

		IShader::IShader(const std::string& name) : IShader(IAPI::GetInstance()->GetDevice(), name)
		{}

		IShader::~IShader() {



		}



		/**
		 *	Release Methods
		 */
		void IShader::Release() {

			for (auto mat : materialList) {

				RemoveMaterial(mat);

			}

			propName2PropIndexMap.clear();
			propertyVector.clear();

			delete this;

		}


		/**
		 *	Properties
		 */
		IShaderPass* IShader::GetPass(const std::string& name) {

			return passName2PassMap[name];

		}



		/**
		 *	Methods
		 */
		IShaderPass*	IShader::AddPass		(const std::string& name) {

			IShaderPass* pass = new IShaderPass(name);

			passName2PassMap[pass->GetName()] = pass;

			return pass;

		}

		void			IShader::RemovePass	(const std::string& name) {

			delete (passName2PassMap[name]);

			passName2PassMap.erase(name);

		}

		List<IMaterial*>::Node* IShader::AddMaterial(IMaterial* material) {

			return materialList.Add(material);

		}

		void			IShader::RemoveMaterial(IMaterial* material) {

			materialList.Remove(material->GetNode());

			material->SetShader(0);

		}

		void			IShader::Apply(const std::string& name) {

			if (passName2PassMap.find(name) == passName2PassMap.end()) return;

			GetPass(name)->Apply();

		}

		void			IShader::SetPropertyVector(const std::vector<ShaderProperty>& _propertyVector) {

			propName2PropIndexMap.clear();

			unsigned int propertyTotalSize = 0;

			unsigned int propertyCount = _propertyVector.size();

			this->propertyVector = _propertyVector;

			for (unsigned int i = 0; i < propertyCount; ++i) {

				propertyVector[i].offset = propertyTotalSize;

				propertyTotalSize += propertyVector[i].size;

				propName2PropIndexMap[propertyVector[i].name] = i;

			}

			this->propertyTotalSize = propertyTotalSize;

			for (auto mat : materialList) {

				mat->ReleasePropertyBuffer();
				mat->CreatePropertyBuffer();

			}

		}

	}

}