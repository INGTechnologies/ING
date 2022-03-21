
/**
 *	Include Header
 */
#include "DrawableMaterial.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include SwapChain
 */
#include <ING/Rendering/API/SwapChain/SwapChain.h>



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>



/**
 *	Include Drawable Category
 */
#include <ING/Rendering/Drawable/Category/Category.h>



/**
 *	Include Shader
 */
#include <ING/Rendering/Shader/Shader.h>





namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		DrawableMaterial::DrawableMaterial(const std::string& name, IShader* shader) :
			IMaterial(name, shader)
		{



		}

		DrawableMaterial::~DrawableMaterial()
		{



		}



		/**
		 *	Methods
		 */
		void DrawableMaterial::Apply(const std::string& passName) {

			GetShader()->Apply(passName);

		}

	}

}