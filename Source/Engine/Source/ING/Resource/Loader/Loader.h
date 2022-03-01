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
	class ING_API IResourceLoader {

		/**
		 *	Constructors And Destructor
		 */
	public:
		IResourceLoader();
		~IResourceLoader();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Loade Method
		 */
	public:
		virtual IResource* Load(std::wstring path, CoderOption& coderOption);

	};



	/**
	 *	Main Class
	 */
	template<class T>
	class ResourceLoader : public IResourceLoader {

		/**
		 *	Constructors And Destructor
		 */
	public:
		ResourceLoader() {



		}

		~ResourceLoader() {



		}



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;

	};



	template<class T>
	void ResourceLoader<T>::Release() {



		IResourceLoader::Release();

	}


}