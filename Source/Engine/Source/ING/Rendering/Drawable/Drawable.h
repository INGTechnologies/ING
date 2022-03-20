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



namespace ING {

	class Camera;



	namespace Rendering {

		class IRenderer;

		class IDevice;

		class IDeviceContext;

		class IPass;

		class IDrawableCategory;

		class Layer;



		class ING_API IDrawable
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IDrawable	();
			~IDrawable	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Layer*							layer;

			std::vector<std::string>		categoryNameVector;

			std::unordered_map<std::string, List<IDrawable*>::Node*>	categoryName2NodeMap;

			bool							isActive;

		public:
			void							SetLayer				(unsigned int index);
			Layer*							GetLayer				();

			const std::vector<std::string>& GetCategoryNameVector	() { return categoryNameVector; }
			void							SetCategoryNameVector	(const std::vector<std::string>& categoryNameVector);
			void							SetCategories			(const std::vector<std::string>& categoryNameVector);

			List<IDrawable*>::Node*			GetNode					(const std::string& categoryName);
			void							AddNode					(const std::string& categoryName, List<IDrawable*>::Node* node);
			void							RemoveNode				(const std::string& categoryName);
			bool							IsHaveNode				(const std::string& categoryName);

			bool							IsActive				() { return isActive; }
			void							SetActive				(bool isActive) { this->isActive = isActive; }



			/**
			 *	Methods
			 */
		public:
			virtual void Draw();

		};

	}

}