
/**
 *	Include Header
 */
#include "Pass.h"



/**
 *	Include Shader
 */
#include "../Shader.h"



/**
 *	Include Input Layout
 */
#include <ING/Rendering/API/InputLayout/InputLayout.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IShaderPass::IShaderPass(const std::string& name) {

			this->name = name;

		}

		IShaderPass::~IShaderPass() {

			childShaderNameToChildShader.clear();

		}



		/**
		 *	Release Methods
		 */
		void IShaderPass::Release() {

			delete this;

		}



		/**
		 *	Methods
		 */
		void IShaderPass::AddChild(const std::string& tag, IShader* shader) {

			childShaderNameToChildShader[tag] = shader;

		}

		void IShaderPass::RemoveChild(const std::string& tag, IShader* shader) {

			childShaderNameToChildShader.erase(tag);

		}

		void IShaderPass::Apply() {

			if (inputLayout != 0) {

				inputLayout->Apply();

			}

			for (auto item : childShaderNameToChildShader) {

				IShader* childShader = item.second;

				childShader->Apply(name);

			}

		}

	}

}