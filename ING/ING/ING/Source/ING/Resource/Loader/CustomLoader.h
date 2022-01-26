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



namespace ING {

	template<class T>
	class CustomResourceLoader : public ResourceLoader {

		/**
		 *	Constructors And Destructor
		 */
	public:
		CustomResourceLoader() {



		}

		~CustomResourceLoader() {



		}



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;

	};



	template<class T>
	void CustomResourceLoader<T>::Release() {



		ResourceLoader::Release();

	}


}