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



namespace ING {

	class ILoader;

	class ISaver;

	class Coder;



	/**
	 *	Interface Class
	 */
	class ING_API IResource {

		/**
		 *	Constructors And Destructor
		 */
	public:
		IResource();
		~IResource();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();

	};



	/**
	 *	Main Class
	 */
	template<class T, class TLoader, class TSaver>
	class Resource : public IResource {

		/**
		 *	Constructors And Destructor
		 */
	public:
		Resource() {



		}

		~Resource() {



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

}



namespace ING {

	template<class T, class TLoader, class TSaver>
	void		Resource<T, TLoader, TSaver>::Release() {



		IResource::Release();

	}



	template<class T, class TLoader, class TSaver>
	TLoader*	Resource<T, TLoader, TSaver>::loader = new TLoader();



	template<class T, class TLoader, class TSaver>
	TSaver*		Resource<T, TLoader, TSaver>::saver = new TSaver();

}