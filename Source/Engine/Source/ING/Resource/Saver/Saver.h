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
 *	Include Coder Option
 */
#include <ING/Coder/Option/Option.h>



namespace ING {

	class IResource;

	class Coder;



	/**
	 *	Interface Class
	 */
	class ING_API IResourceSaver {

		/**
		 *	Constructors And Destructor
		 */
	public:
		IResourceSaver();

		~IResourceSaver();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Save Method
		 */
	public:
		virtual void Save(IResource* resource, CoderOption& coderOption);

	};



	/**
	 *	Main Class
	 */
	template<class T>
	class ResourceSaver : public IResourceSaver {

		/**
		 *	Constructors And Destructor
		 */
	public:
		ResourceSaver() {



		}

		~ResourceSaver() {



		}



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;

	};



	template<class T>
	void ResourceSaver<T>::Release() {



		IResourceSaver::Release();

	}

}