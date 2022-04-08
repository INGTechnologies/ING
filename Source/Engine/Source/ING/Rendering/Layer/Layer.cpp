
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
 *	Include Drawable Filter
 */
#include <ING/Rendering/Drawable/Filter/Filter.h>



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

			for (auto& item : name2DrawableFilterMap) {

				item.second->Release();

			}

			name2DrawableFilterMap.clear();

			delete this;

		}



		/**
		 *	Properties
		 */
		IDrawableFilter*	Layer::GetFilter(const std::string& name) {

			return name2DrawableFilterMap[name]; 
		}

		void				Layer::AddFilter(const std::string& name) {

			name2DrawableFilterMap[name] = new IDrawableFilter(name);

		}

		void				Layer::RemoveFilter(const std::string& name) {

			GetFilter(name)->Release();

			name2DrawableFilterMap.erase(name);

		}

	}

}