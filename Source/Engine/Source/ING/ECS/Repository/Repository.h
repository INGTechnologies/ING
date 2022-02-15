#pragma once



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Map
 */
#include <map>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		class Component;

		class IComponentSystem;



		/**
		 *	Main Class
		 */
		class Repository
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Repository() {



			}

			~Repository() {

				componentSystemTypeId2ComponentSystemMap.clear();
				componentTypeId2ComponentSystemMap.clear();

			}



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() {



			}



			/**
			 *	Properties
			 */
		private:
			std::map<std::string, IComponentSystem*> componentSystemTypeId2ComponentSystemMap;
			std::map<std::string, IComponentSystem*> componentTypeId2ComponentSystemMap;

		public:
			std::map<std::string, IComponentSystem*>& GetComponentSystemTypeId2ComponentSystemMap	() { return componentSystemTypeId2ComponentSystemMap; }
			std::map<std::string, IComponentSystem*>& GetComponentTypeId2ComponentSystemMap			() { return componentTypeId2ComponentSystemMap; }



			/**
			 *	Methods
			 */
		public:
			template<class TComponentSystem>
			TComponentSystem* CreateComponentSystem();

			template<class TComponentSystem>
			TComponentSystem* GetComponentSystem();

			template<class T>
			IComponentSystem* GetComponentSystemFromComponentType();

			template<typename TComponentSystem>
			void				ReleaseComponentSystem();

		};

	}

}



/**
 *	Include Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Methods
		 */
		template<class TComponentSystem>
		TComponentSystem*	Repository::CreateComponentSystem() {

			TComponentSystem* componentSystem = new TComponentSystem(this);

			componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()] = componentSystem;
			componentTypeId2ComponentSystemMap[componentSystem->GetComponentTypeId()] = componentSystem;

			return componentSystem;

		}

		template<class TComponentSystem>
		TComponentSystem*	Repository::GetComponentSystem() {

			TComponentSystem* componentSystem = (TComponentSystem*)componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()];

			return componentSystem;

		}

		template<class T>
		IComponentSystem*	Repository::GetComponentSystemFromComponentType() {

			IComponentSystem* componentSystem = componentSystemTypeId2ComponentSystemMap[typeid(T).name()];

			return componentSystem;

		}

		template<typename TComponentSystem>
		void				Repository::ReleaseComponentSystem() {

			TComponentSystem* componentSystem = (TComponentSystem*)componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()];

			componentTypeId2ComponentSystemMap.erase(componentSystem->GetComponentTypeId());

			componentSystem->Release();

			componentSystemTypeId2ComponentSystemMap.erase(typeid(TComponentSystem).name());

		}

	}

}