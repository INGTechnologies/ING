#pragma once



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Id
 */
#include <ING/ECS/Component/Id/Id.h>



/**
 *	Include Unordered Map
 */
#include <unordered_map>



/**
 *	Define And Declares Classes, Structs,... 
 */
namespace ING {

	namespace ECS {

		class Entity;

		class Repository;

		template<typename T, class TComponentSystem>
		class ComponentSystem;



		/**
		 *	Interface Class
		 */
		class IComponentPtr {



		};



		/**
		 *	Main Class
		 */
		template<typename T, class TComponentSystem>
		class ComponentPtr : public IComponentPtr
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			ComponentPtr() {



			}

			~ComponentPtr() {



			}



			/**
			 *	Properties
			 */
		private:
			ComponentId id;
			Repository* repository;

		public:
			ComponentId	GetId() { return id; }
			Repository* GetRepository() { return repository; }

			void		SetId(ComponentId id) {

				this->id = id;
			}

			void		SetRepository(Repository* repository) {

				this->repository = repository;
			}



			/**
			 *	Methods
			 */
		public:
			T& operator * ();

		};

	}

}



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Include ECS Repository
 */
#include <ING/ECS/Repository/Repository.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		template<typename T, class TComponentSystem>
		T&	ComponentPtr<T, TComponentSystem>::operator * () {

			TComponentSystem* componentSystem = repository->GetComponentSystem<TComponentSystem>();

			return componentSystem->GetComponentFromId(id);

		}

	}

}