
/**
 * Include Header
 */
#include "Category.h"



/**
 *	Include Drawable
 */
#include <ING/Rendering/Drawable/Drawable.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IDrawableCategory::IDrawableCategory	(const std::string& name) {

			this->name = name;

		}

		IDrawableCategory::~IDrawableCategory	() {



		}



		/**
		 *	Release Methods
		 */
		void IDrawableCategory::Release() {

			for (auto& item : drawableList) {

				item->RemoveNode(name);

			}

			drawableList.Clear();

			delete this;

		}



		/**
		 *	Methods
		 */
		void IDrawableCategory::AddDrawable		(IDrawable* drawable) {

			drawable->AddNode(name, drawableList.Add(drawable));

		}

		void IDrawableCategory::RemoveDrawable	(IDrawable* drawable) {

			if (!drawable->IsHaveNode(name)) return;

			drawableList.Remove(drawable->GetNode(name));

			drawable->RemoveNode(name);

		}

	}

}