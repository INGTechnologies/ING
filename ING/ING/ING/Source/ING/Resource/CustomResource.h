#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Resource
 */
#include <ING/Resource/Resource.h>



/**
 *	Include Loader
 */
#include <ING/Resource/Loader/Loader.h>



/**
 *	Include Saver
 */
#include <ING/Resource/Saver/Saver.h>



namespace ING {

	template<class T, class TLoader, class TSaver>
	class CustomResource : public Resource {

		/**
		 *	Constructors And Destructor
		 */
	public:
		CustomResource() {



		}

		~CustomResource() {



		}



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;



		/**
		 *	Loader
		 */
	private:
		static TLoader* loader;

	public:
		static TLoader* GetLoader() { return loader; }



		/**
		 *	Saver
		 */
	private:
		static TSaver* saver;

	public:
		static TSaver* GetSaver() { return saver; }

	};



	template<class T, class TLoader, class TSaver>
	void CustomResource<T, TLoader, TSaver>::Release() {



		Resource::Release();

	}



	template<class T, class TLoader, class TSaver>
	TLoader*	CustomResource<T, TLoader, TSaver>::loader	= new TLoader();



	template<class T, class TLoader, class TSaver>
	TSaver*		CustomResource<T, TLoader, TSaver>::saver	= new TSaver();


}