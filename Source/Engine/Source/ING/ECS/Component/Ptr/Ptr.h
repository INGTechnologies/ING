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

		class IComponentSystem;

		template<typename T, class TComponentSystem>
		class ComponentSystem;



		/**
		 *	Interface Class
		 */
		class IComponentPtr {

			/**
			 *	Properties
			 */
		protected:
			ComponentId			id;
			IComponentSystem*	icomponentSystem;

		public:
			ComponentId			GetId				() { return id; }
			IComponentSystem*	GetIComponentSystem	() { return icomponentSystem; }

			void				SetId(ComponentId id) {

				this->id = id;
			}

			void				SetIComponentSystem(IComponentSystem* icomponentSystem) {

				this->icomponentSystem = icomponentSystem;
			}

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

			ComponentPtr(IComponentPtr iPtr) {

				id					= iPtr.GetId();
				icomponentSystem	= iPtr.GetIComponentSystem();

			}

			~ComponentPtr() {



			}



			/**
			 *	Methods
			 */
		public:
			TComponentSystem* GetComponentSystem() {

				return (TComponentSystem*)icomponentSystem;

			}



			/**
			 *	Operators
			 */
		public:
			T& operator * ();
			T* operator -> ();

		};

	}

}