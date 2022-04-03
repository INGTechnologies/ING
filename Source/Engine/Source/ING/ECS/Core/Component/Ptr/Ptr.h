#pragma once

/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Id
 */
#include <ING/ECS/Core/Component/Id/Id.h>



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
			 *	Constructors And Destructor
			 */
		public:
			IComponentPtr() :
				icomponentSystem(0),
				id(0)
			{



			}

			IComponentPtr(ComponentId id, IComponentSystem* system) :
				icomponentSystem(system),
				id(id)
			{



			}

			~IComponentPtr() {



			}



			/**
			 *	Properties
			 */
		protected:
			ComponentId			id;
			IComponentSystem*	icomponentSystem;

		public:
			ComponentId			GetId				() const { return id; }
			IComponentSystem*	GetIComponentSystem	() const { return icomponentSystem; }

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
			ComponentPtr() :
				IComponentPtr()
			{



			}

			ComponentPtr(const IComponentPtr& iPtr) {

				id					= iPtr.GetId();
				icomponentSystem	= iPtr.GetIComponentSystem();

			}

			~ComponentPtr() {



			}



			/**
			 *	Methods
			 */
		public:
			TComponentSystem* GetComponentSystem() const {

				return (TComponentSystem*)icomponentSystem;

			}

			T& GetComponent() const { return *this; }

			bool IsNull() const { return (id == 0) && (icomponentSystem == 0); }



			/**
			 *	Operators
			 */
		public:
			T& operator * ();
			T* operator -> ();

		};

	}

}