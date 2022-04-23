
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

			for (auto item : drawableArray) {

				RemoveDrawable(item);

			}

			drawableArray.Clear();

			idGenerator.ClearIds();

			delete this;

		}



		/**
		 *	Methods
		 */
		void IDrawableFilter::AddDrawable		(IDrawable* drawable) {

			if (drawable->IsHaveFilter(name)) return;

			DrawableId id = idGenerator.GenUInt64();

			drawable->id = id;

			drawableArray.Add(drawable, id);

		}

		void IDrawableFilter::RemoveDrawable	(IDrawable* drawable) {

			if (!drawable->IsHaveFilter(name)) return;

			drawableArray.Erase(drawable->id);

			drawable->filterName2FilterMap.erase(name);

			drawable->filterNameVector;

			unsigned int filterCount = drawable->filterNameVector.size();

			for (unsigned int i = 0; i < filterCount; ++i) {

				if (drawable->filterNameVector[i] == name) {

					for (unsigned int j = i; j < filterCount - 1; ++i) {

						drawable->filterNameVector[j] = drawable->filterNameVector[j + 1];

					}

					break;
				}

			}

			idGenerator.RemoveUInt64Id(drawable->id);

		}

	}

}