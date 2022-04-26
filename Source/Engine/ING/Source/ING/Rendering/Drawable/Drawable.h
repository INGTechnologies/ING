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

		class IDrawableFilter;

		class Layer;



		using DrawableId = size_t;



		class ING_API IDrawable
		{

		public:
			friend class IDrawableFilter;



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
			DrawableId						id;

			Layer*							layer;

			std::vector<std::string>		filterNameVector;

			std::unordered_map<std::string, IDrawableFilter*>	filterName2FilterMap;

			bool							isActive;

		public:
			DrawableId						GetId					() { return id; }

			void							SetLayer				(unsigned int index);
			Layer*							GetLayer				();

			const std::vector<std::string>& GetFilterNameVector		() { return filterNameVector; }
			void							SetFilterNameVector		(const std::vector<std::string>& filterNameVector);
			void							SetFilters				(const std::vector<std::string>& filterNameVector);

			//List<IDrawable*>::Node*			GetNode					(const std::string& filterName);
			//void							AddNode					(const std::string& filterName, List<IDrawable*>::Node* node);
			//void							RemoveNode				(const std::string& filterName);
			bool							IsHaveFilter			(const std::string& filterName) { return filterName2FilterMap.find(filterName) != filterName2FilterMap.end(); }

			bool							IsActive				() { return isActive; }
			void							SetActive				(bool isActive) { this->isActive = isActive; }



			/**
			 *	Methods
			 */
		public:
			virtual void Draw(Camera* camera, const std::string& passName);

		};

	}

}