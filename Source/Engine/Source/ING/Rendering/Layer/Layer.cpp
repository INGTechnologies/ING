
/**
 *	Include Header
 */
#include "Layer.h"



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
		Layer::Layer(std::string name)
		{

			this->name = name;

		}

		Layer::~Layer()
		{



		}



		/**
		 *	Release Methods
		 */
		void Layer::Release()
		{

			for (auto& item : name2DrawableCategoryMap) {

				item.second->Release();

			}

			name2DrawableCategoryMap.clear();

			delete this;

		}



		/**
		 *	Properties
		 */
		IDrawableCategory*	Layer::GetCategory(const std::string& name) {

			return name2DrawableCategoryMap[name]; 
		}

		void				Layer::AddCategory(const std::string& name) {

			name2DrawableCategoryMap[name] = new IDrawableCategory(name);

		}

		void				Layer::RemoveCategory(const std::string& name) {

			GetCategory(name)->Release();

			name2DrawableCategoryMap.erase(name);

		}

	}

}