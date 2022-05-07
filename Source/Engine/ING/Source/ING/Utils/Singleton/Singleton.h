#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include String
 */
#include <ING\Utils\String\String.h>



extern ING_API void LoadSingletonInstance	(void** wherePtrAre, const ING::Utils::String& name);
extern ING_API void SetupSingletonInstance	(void* instance, const ING::Utils::String& name);

extern ING_API ING::Utils::String GetEngineClassName		();
extern ING_API ING::Utils::String GetPluginManagerClassName	();



namespace ING {

	class Engine;

	class PluginManager;



	namespace Utils {

		template<class T>
		class Singleton {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Singleton() {

				mInstance = (T*)this;

				SetupSingletonInstance(mInstance, typeid(T).name());

			}



			/**
			 *	Instance
			 */
		private:
			static T* mInstance;

		public:
			static T* GetInstance();



			/**
			 *	CreateInstance Method
			 */
		public:
			static T* CreateInstance() {

				return new T();

			}



			/**
			 *	LoadInstance Method
			 */
		public:
			static void LoadInstance(T* instance) {

#ifdef IS_PLUGIN
				if (ToString(typeid(T).name()) == GetEngineClassName()) {

					mInstance = instance;

				}
				else if (ToString(typeid(T).name()) == GetPluginManagerClassName()) {

					mInstance = instance;

				}
				else {

					LoadSingletonInstance((void**)(& mInstance), typeid(T).name());

				}
#endif

			}

		};



		/**
		 *	Define Members
		 */
		template<class T>
		T* Singleton<T>::mInstance= nullptr;

		template<class T>
		T* Singleton<T>::GetInstance() {

#ifdef IS_PLUGIN
			if (mInstance == 0) {

				Singleton<T>::LoadInstance(0);
			}
#endif

			return mInstance;
		}



		/**
		 *	Include Macros
		 */
		#define IMPLEMENT_SINGLETON(T) T* TInstance = new T();

	}

}

