
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

			/**
			 *	Properties
			 */
		protected:
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

				id = iPtr.GetId();
				repository = iPtr.GetRepository();

			}

			~ComponentPtr() {



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