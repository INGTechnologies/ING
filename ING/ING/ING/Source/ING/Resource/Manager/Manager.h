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



namespace ING {

	class Resource;

	class ResourceLoader;

	class ResourceSaver;



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
		std::wstring	ReadFile		(std::wstring path);
		void			WriteFile		(std::wstring path, std::wstring& content);

		template<class T>
		T*				LoadResource	(std::wstring path) {

			if (typeid(T) == typeid(Resource)) {

				T* result = new T();

				return result;

			}
			else {

				ResourceLoader* loader = T::GetLoader();

				T* result = (T*)loader->Load(path);

				return result;

			}

		}

		template<class T>
		void			SaveResource(T* resource) {

			if (typeid(T) == typeid(Resource)) {

				

			}
			else {

				ResourceSaver* saver = T::GetSaver();

				saver->Save(resource);

			}

		}

	};


}