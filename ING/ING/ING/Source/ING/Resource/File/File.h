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
 *	Include Custom Resource
 */
#include <ING/Resource/CustomResource.h>



/**
 *	Include Custom Resource
 */
#include <ING/Resource/CustomResource.h>



/**
 *	Include Custom Resource Loader
 */
#include <ING/Resource/Loader/CustomLoader.h>



/**
 *	Include Custom Resource Saver
 */
#include <ING/Resource/Saver/CustomSaver.h>



namespace ING {

	/**
	 *	Loader Class
	 */
	class ING_API FileLoader : public CustomResourceLoader<FileLoader> {

		/**
		 *	Constructors And Destructor
		 */
	public:
		FileLoader();
		~FileLoader();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;



		/**
		 *	Load Method
		 */
	public:
		virtual Resource* Load(std::wstring path, CoderOption& coderOption) override;

	};





	/**
	 *	Saver Class
	 */
	class ING_API FileSaver : public CustomResourceSaver<FileSaver> {

		/**
		 *	Constructors And Destructor
		 */
	public:
		FileSaver();
		~FileSaver();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;



		/**
		 *	Save Method
		 */
	public:
		virtual void Save(Resource* resource, CoderOption& coderOption) override;

	};





	/**
	 *	Resource Class
	 */
	class ING_API FileResource : public CustomResource<FileResource, FileLoader, FileSaver> {

		/**
		 *	Friend Classes
		 */
	public:
		friend class FileLoader;
		friend class FileSaver;



		/**
		 *	Constructors And Destructor
		 */
	public:
		FileResource();
		FileResource(std::wstring path);
		FileResource(const wchar_t* path);
		~FileResource();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release() override;



		/**
		 *	Properties
		 */
	private:
		std::wstring path;

	public:
		std::wstring content;

		const std::wstring& GetPath		() { return path; }

	};


}