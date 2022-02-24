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

		class Entity;



		/**
		 *	Main Class
		 */
		class Repository
		{

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
			virtual void Release() {



			}



			/**
			 *	Properties
			 */
		private:
			std::map<std::string, IComponentSystem*> componentSystemTypeId2ComponentSystemMap;
			std::map<std::string, IComponentSystem*> componentTypeId2ComponentSystemMap;

			bool isActive;

			List<Repository*>::Node* node;

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



			/**
			 *	Event Methods
			 */
		public:
			virtual void Update();

		};

	}

}