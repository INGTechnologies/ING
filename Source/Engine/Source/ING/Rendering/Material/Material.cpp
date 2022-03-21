
/**
 *	Include Header
 */
#include "Material.h"



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
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>





namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IMaterial::IMaterial(const std::string& name, IShader* shader)
		{

			this->name = name;

			this->shader = shader;

		}

		IMaterial::~IMaterial()
		{



		}



		/**
		 *	Release Methods
		 */
		void IMaterial::Release()
		{

			delete this;

		}



		/**
		 *	Methods
		 */
		void IMaterial::Apply(const std::string& passName) {



		}

	}

}