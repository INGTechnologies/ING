
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



/**
 *	Include Rendering State
 */
#include <ING/Rendering/State/State.h>



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IShaderPass::IShaderPass(const String& name) {

			this->name = name;

		}

		IShaderPass::~IShaderPass() {

			shaderName2Shader.clear();

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
		void IShaderPass::AddShader(const String& tag, IShader* shader) {

			shaderName2Shader[tag] = shader;

		}

		void IShaderPass::RemoveShader(const String& tag) {

			shaderName2Shader.erase(tag);

		}

		void IShaderPass::AddState(IState* state) {

			stateName2StateMap[state->GetName()] = state;

		}

		void IShaderPass::RemoveState(const String& name) {

			stateName2StateMap.erase(name);

		}

		void IShaderPass::Apply() {

			if (inputLayout != 0) {

				inputLayout->Apply();

			}

			for (auto item : stateName2StateMap) {

				IState* state = item.second;

				state->Apply();

			}

			for (auto item : shaderName2Shader) {

				IShader* childShader = item.second;

				childShader->Apply(name);

			}

		}

	}

}