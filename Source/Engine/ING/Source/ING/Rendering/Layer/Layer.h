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
 *	Include Rendering Layer Manager
 */
#include <ING/Rendering/Layer/Manager/Manager.h>



namespace ING {

	namespace Rendering {

		class IDrawableFilter;

		class IDrawble;

		class LayerSystem;



		class ING_API Layer
		{

			/**
			 *	Friend Classes
			 */
		public:
			friend class LayerManager;
			friend class LayerSystem;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Layer	(String name, LayerSystem* system);
			~Layer	();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String				name;

			unsigned int		index;

			LayerSystem*		system;

			std::unordered_map<String, IDrawableFilter*> name2DrawableFilterMap;

		public:
			String				GetName			() { return name; }

			unsigned int		GetIndex		() { return index; }

			const std::unordered_map<String, IDrawableFilter*>& GetName2DrawableFilterMap () { return name2DrawableFilterMap; }

			IDrawableFilter*	GetFilter		(const String& name);
			void			    AddFilter		(const String& name);
			void			    RemoveFilter	(const String& name);

			LayerSystem*		GetSystem		() { return system; }

		};

	}

}