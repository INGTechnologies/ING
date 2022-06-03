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



/**
 *	Include Reflection
 */
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class Camera;



	namespace Rendering {

		class C_Renderer;

		class IDevice;

		class IDeviceContext;

		class C_Pass;

		class IDrawableFilter;

		class Layer;

		class LayerSystem;



		using DrawableId = size_t;



		class ING_API C_Drawable : public Reflection::C_Object
		{

		public:
			friend class IDrawableFilter;



			ING_REFLECT_CLASS(C_Drawable, Reflection::C_Object)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor(LayerSystem* system);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			DrawableId						idInFilter;

			Layer*							layer;

			std::vector<String>				filterNameVector;

			std::unordered_map<String, IDrawableFilter*>filterName2FilterMap;

			bool							isActive;

			LayerSystem*					system;

		public:
			DrawableId						GetIdInFilter			() { return idInFilter; }

			void							SetLayer				(unsigned int index);
			Layer*							GetLayer				();

			const std::vector<String>&		GetFilterNameVector		() { return filterNameVector; }
			void							SetFilterNameVector		(const std::vector<String>& filterNameVector);
			void							SetFilters				(const std::vector<String>& filterNameVector);
			bool							IsHaveFilter			(const String& filterName) { return filterName2FilterMap.find(filterName) != filterName2FilterMap.end(); }

			bool							IsActive				() { return isActive; }
			void							SetActive				(bool isActive) { this->isActive = isActive; }

			LayerSystem*					GetSystem				() { return system; }



			/**
			 *	Methods
			 */
		public:
			virtual void Draw(Camera* camera, const String& passName);

		};

	}

}