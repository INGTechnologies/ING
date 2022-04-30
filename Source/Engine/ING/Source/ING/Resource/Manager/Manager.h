#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include String
 */
#include <string>



/**
 *	Include Coder Option
 */
#include <ING/Coder/Option/Option.h>




namespace ING {

	class IResource;

	class IResourceLoader;

	class IResourceSaver;

	class Coder;



	class ING_API ResourceManager :
		public Singleton<ResourceManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ResourceManager();
		~ResourceManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Resource Management
		 */
	public:
		bool			IsFileExist		(const WString& path);

		WString	ReadFile		(const WString& path, CoderOption& coderOption);
		WString	ReadFile		(const WString& path) {

			CoderOption coderOption;

			return ReadFile(path, coderOption);

		}

		void			WriteFile		(const WString& path, const WString& content, CoderOption& coderOption);
		void			WriteFile		(const WString& path, const WString& content) {

			CoderOption coderOption;

			WriteFile(path,content, coderOption);

		}

		template<class T>
		T*				LoadResource	(const WString& path) {

			CoderOption coderOption;

			return LoadResource<T>(path, coderOption);

		}

		template<class T>
		T*				LoadResource	(const WString& path, CoderOption& coderOption) {

			if (typeid(T) == typeid(IResource)) {

				T* result = new T();

				return result;

			}
			else {

				IResourceLoader* loader = T::GetLoader();

				T* result = (T*)loader->Load(path, coderOption);

				return result;

			}

		}

		template<class T>
		void			SaveResource	(T* resource) {

			CoderOption coderOption;

			return SaveResource<T>(resource, coderOption);

		}

		template<class T>
		void			SaveResource	(T* resource, CoderOption& coderOption) {

			if (typeid(T) == typeid(IResource)) {

				

			}
			else {

				IResourceSaver* saver = T::GetSaver();

				saver->Save(resource, coderOption);

			}

		}

	};


}