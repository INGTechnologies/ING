
/**
 *	Include Header
 */
#include "Shader.h"



/**
 *	Include Shader Pass
 */
#include "Pass/Pass.h"



namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IShader::IShader(const std::string& name) {

			this->name = name;

		}

		IShader::~IShader() {



		}



		/**
		 *	Release Methods
		 */
		void IShader::Release() {

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

		void			IShader::Apply(const std::string& name) {

			if (passName2PassMap.find(name) == passName2PassMap.end()) return;

			GetPass(name)->Apply();

		}

	}

}