
/**
 * Include Header
 */
#include "Filter.h"



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IDrawableFilter::IDrawableFilter	(const std::string& name) {

			this->name = name;

		}

		IDrawableFilter::~IDrawableFilter	() {



		}



		/**
		 *	Release Methods
		 */
		void IDrawableFilter::Release() {

			for (auto& item : drawableList) {

				item->RemoveNode(name);

			}

			drawableList.Clear();

			delete this;

		}



		/**
		 *	Methods
		 */
		void IDrawableFilter::AddDrawable		(IDrawable* drawable) {

			drawable->AddNode(name, drawableList.Add(drawable));

		}

		void IDrawableFilter::RemoveDrawable	(IDrawable* drawable) {

			if (!drawable->IsHaveNode(name)) return;

			drawableList.Remove(drawable->GetNode(name));

			drawable->RemoveNode(name);

		}

	}

}