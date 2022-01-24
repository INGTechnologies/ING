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
 *	Include Vector
 */
#include <vector>



namespace ING {

	namespace Rendering {

		class ING_API Shader {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Shader();
			~Shader();



			/**
			 *	Child Shaders
			 */
		protected:
			List<Shader*> childShaderList;

		public:
			List<Shader*>::Node*	GetHeadShaderNode	();
			List<Shader*>::Node*	GetTailShaderNode	();
			List<Shader*>::Node*	AddShader			(Shader* shader);
			void					RemoveShader		(List<Shader*>::Node* shaderNode);

		};

	}

}