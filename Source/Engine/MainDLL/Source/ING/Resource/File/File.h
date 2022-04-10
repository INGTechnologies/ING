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
 *	Include Resource Loader
 */
#include <ING/Resource/Loader/Loader.h>



/**
 *	Include Resource Saver
 */
#include <ING/Resource/Saver/Saver.h>



namespace ING {

	/**
	 *	Loader Class
	 */
	class ING_API FileLoader : public ResourceLoader<FileLoader> {

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
		virtual IResource* Load(const std::wstring& path, CoderOption& coderOption) override;

	};





	/**
	 *	Saver Class
	 */
	class ING_API FileSaver : public ResourceSaver<FileSaver> {

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
		virtual void Save(IResource* resource, CoderOption& coderOption) override;

	};





	/**
	 *	Resource Class
	 */
	class ING_API FileResource : public Resource<FileResource, FileLoader, FileSaver> {

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
		FileResource(const std::wstring& path);
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