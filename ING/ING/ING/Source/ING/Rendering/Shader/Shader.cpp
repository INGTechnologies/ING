
/**
 *	Include Header
 */
#include "Shader.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		Shader::Shader() {



		}

		Shader::~Shader() {



		}



		/**
		 *	Child Shaders
		 */
		List<Shader*>::Node*	Shader::GetHeadShaderNode() {

			return childShaderList.GetHeadNode();

		}

		List<Shader*>::Node*	Shader::GetTailShaderNode() {

			return childShaderList.GetTailNode();

		}

		List<Shader*>::Node*	Shader::AddShader(Shader* shader) {

			return childShaderList.Add(shader);

		}

		void					Shader::RemoveShader(List<Shader*>::Node* shaderNode) {

			childShaderList.Remove(shaderNode);

		}


	}

}