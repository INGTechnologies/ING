#pragma once

/**
 *	Include ECS Entry Point
 */
#include <ING/ECS/EntryPoint/EntryPoint.h>



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

		public:
			std::map<std::string, IComponentSystem*>& GetComponentSystemTypeId2ComponentSystemMap() { return componentSystemTypeId2ComponentSystemMap; }
			std::map<std::string, IComponentSystem*>& GetComponentTypeId2ComponentSystemMap() { return componentTypeId2ComponentSystemMap; }

			bool IsActive() { return isActive; }



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

			void				SetActive(bool isActive);

		};

	}

}