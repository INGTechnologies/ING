
/**
 * Include Header
 */
#include "Drawable.h"



/**
 *	Include Camera
 */
#include <ING/Camera/Camera.h>



/**
 *	Include Renderer
 */
#include <ING/Rendering/Renderer/Renderer.h>



/**
 *	Include Rendering API
 */
#include <ING/Rendering/API/API.h>



/**
 *	Include Rendering Device Context
 */
#include <ING/Rendering/API/Device/Context/Context.h>



/**
 *	Include Rendering Device
 */
#include <ING/Rendering/API/Device/Device.h>



/**
 *	Include Rendering Pass
 */
#include <ING/Rendering/Pass/Pass.h>



/**
 *	Include Rendering Drawable Category
 */
#include <ING/Rendering/Drawable/Category/Category.h>



/**
 *	Include Rendering Layer
 */
#include <ING/Rendering/Layer/Layer.h>



/**
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>




namespace ING {

	namespace Rendering {

		/**
		 *	Constructors And Destructor
		 */
		IDrawable::IDrawable() : layer(0) {

			categoryNameVector.resize(0);

			SetLayer(0);

		}

		IDrawable::~IDrawable() {



		}



		/**
		 *	Release Methods
		 */
		void	IDrawable::Release() {

			delete this;

		}



		/**
		 *	Properties
		 */
		void	IDrawable::SetLayer(unsigned int index) {

			if (LayerManager::GetInstance()->GetLayerVector()[index] == 0) {

				return;

			}

			unsigned int categoryCount = categoryNameVector.size();

			for (unsigned int i = 0; i < categoryCount; ++i) {

				IDrawableCategory* category = layer->GetCategory(categoryNameVector[i]);

				category->RemoveDrawable(this);

			}

			layer = LayerManager::GetInstance()->GetLayer(index);

			SetCategoryNameVector(categoryNameVector);

		}

		Layer*	IDrawable::GetLayer	() {
			
			return layer;
		}

		void	IDrawable::SetCategoryNameVector(const std::vector<std::string>& categoryNameVector) {

			unsigned int categoryCount = categoryNameVector.size();

			this->categoryNameVector = categoryNameVector;

			for (unsigned int i = 0; i < categoryCount; ++i) {

				IDrawableCategory* category = layer->GetCategory(categoryNameVector[i]);

				category->AddDrawable(this);

			}
		
		}

		void	IDrawable::SetCategories(const std::vector<std::string>& categoryNameVector) {

			SetCategoryNameVector(categoryNameVector);

		}

		List<IDrawable*>::Node* IDrawable::GetNode(const std::string& categoryName) {

			return categoryName2NodeMap[categoryName];

		}

		void	IDrawable::AddNode(const std::string& categoryName, List<IDrawable*>::Node* node) {

			categoryName2NodeMap[categoryName] = node;

		}

		void	IDrawable::RemoveNode(const std::string& categoryName) {

			categoryName2NodeMap.erase(categoryName);

		}

		bool	IDrawable::IsHaveNode(const std::string& categoryName) {

			return !(categoryName2NodeMap.find(categoryName) == categoryName2NodeMap.end());

		}



		/**
		 *	Methods
		 */
		void	IDrawable::Draw (Camera* camera, const std::string& passName) {

			

		}

	}

}