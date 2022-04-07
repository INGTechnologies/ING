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
		 *	Export To ING API
		 */
		ING_API void RepositoryConstructor(Repository* repository);
		ING_API void RepositoryDestructor(Repository* repository);
		ING_API void RepositoryRelease(Repository* repository);



		/**
		 *	Main Class
		 */
		class Repository
		{

		public:
			friend class RepositoryManager;
			friend void RepositoryConstructor(Repository* repository);
			friend void RepositoryDestructor(Repository* repository);
			friend void RepositoryRelease(Repository* repository);



			/**
			 *	Constructors And Destructor
			 */
		public:
			Repository();// {

			//	RepositoryConstructor(this);

			//}

			~Repository();// {

			//	RepositoryDestructor(this);

			//}



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();// {

			//	RepositoryRelease(this);

			//}



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