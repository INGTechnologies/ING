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
  *	Include Saver
  */
#include <ING/Resource/Saver/Saver.h>



namespace ING {

	template<class T>
	class CustomResourceSaver : public ResourceSaver {

		/**
		 *	Constructors And Destructor
		 */
	public:
		CustomResourceSaver() {



		}

		~CustomResourceSaver() {



		}



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;

	};



	template<class T>
	void CustomResourceSaver<T>::Release() {



		ResourceSaver::Release();

	}


}