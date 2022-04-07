#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



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

		class Entity;

		class Repository;



		/**
		 *	Main Class
		 */
		class ING_API Repository
		{

		public:
			friend class RepositoryManager;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Repository();

			~Repository();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			std::map<std::string, IComponentSystem*>	componentSystemTypeId2ComponentSystemMap;
			std::map<std::string, IComponentSystem*>	componentTypeId2ComponentSystemMap;

			std::vector<IComponentSystem*>				componentSystemVector;

			bool										isActive;

			List<Repository*>::Node*					node;

		public:
			std::map<std::string, IComponentSystem*>&	GetComponentSystemTypeId2ComponentSystemMap() { return componentSystemTypeId2ComponentSystemMap; }
			std::map<std::string, IComponentSystem*>&	GetComponentTypeId2ComponentSystemMap() { return componentTypeId2ComponentSystemMap; }

			bool										IsActive() { return isActive; }

			void										SetActive(bool isActive);

			List<Repository*>::Node*					GetNode(){ return node; }



			/**
			 *	Methods
			 */
		public:
			template<class TComponentSystem>
			TComponentSystem*	CreateComponentSystem();

			template<class TComponentSystem>
			TComponentSystem*	GetComponentSystem();

			template<class T>
			IComponentSystem*	GetComponentSystemFromComponentType();

			template<typename TComponentSystem>
			void				ReleaseComponentSystem();

			Entity*				CreateEntity();
			Entity*				CreateEntity(const std::vector<IComponentSystem*> systemVector);

			void				ReleaseEntity(Entity* entity);



			/**
			 *	Event Methods
			 */
		public:
			virtual void PreUpdate();
			virtual void Update();
			virtual void LateUpdate();

			virtual void PreRender();
			virtual void Render();
			virtual void LateRender();

		};

	}

}



namespace ING {

	namespace ECS {

		/**
		 *	Methods
		 */
		template<class TComponentSystem>
		TComponentSystem* Repository::CreateComponentSystem() {

			TComponentSystem* componentSystem = new TComponentSystem(this);

			componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()] = componentSystem;
			componentTypeId2ComponentSystemMap[componentSystem->GetComponentTypeId()] = componentSystem;

			componentSystemVector.push_back(componentSystem);

			componentSystem->index = componentSystemVector.size() - 1;

			componentSystem->Init();

			return componentSystem;

		}

		template<class TComponentSystem>
		TComponentSystem* Repository::GetComponentSystem() {

			TComponentSystem* componentSystem = (TComponentSystem*)componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()];

			return componentSystem;

		}

		template<class T>
		IComponentSystem* Repository::GetComponentSystemFromComponentType() {

			IComponentSystem* componentSystem = componentSystemTypeId2ComponentSystemMap[typeid(T).name()];

			return componentSystem;

		}

		template<typename TComponentSystem>
		void				Repository::ReleaseComponentSystem() {

			TComponentSystem* componentSystem = (TComponentSystem*)componentSystemTypeId2ComponentSystemMap[typeid(TComponentSystem).name()];

			componentSystemVector.erase(componentSystemVector.begin() + componentSystem->GetIndex());

			componentTypeId2ComponentSystemMap.erase(componentSystem->GetComponentTypeId());

			componentSystem->Release();

			componentSystemTypeId2ComponentSystemMap.erase(typeid(TComponentSystem).name());

		}

	}

}