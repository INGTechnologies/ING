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

			std::vector<String>		filterNameVector;

			std::unordered_map<String, IDrawableFilter*>	filterName2FilterMap;

			bool							isActive;

		public:
			DrawableId						GetId					() { return id; }

			void							SetLayer				(unsigned int index);
			Layer*							GetLayer				();

			const std::vector<String>& GetFilterNameVector		() { return filterNameVector; }
			void							SetFilterNameVector		(const std::vector<String>& filterNameVector);
			void							SetFilters				(const std::vector<String>& filterNameVector);

			//List<IDrawable*>::Node*			GetNode					(const String& filterName);
			//void							AddNode					(const String& filterName, List<IDrawable*>::Node* node);
			//void							RemoveNode				(const String& filterName);
			bool							IsHaveFilter			(const String& filterName) { return filterName2FilterMap.find(filterName) != filterName2FilterMap.end(); }

			bool							IsActive				() { return isActive; }
			void							SetActive				(bool isActive) { this->isActive = isActive; }



			/**
			 *	Methods
			 */
		public:
			virtual void Draw(Camera* camera, const String& passName);

		};

	}

}