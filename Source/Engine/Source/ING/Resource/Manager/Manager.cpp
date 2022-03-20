
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include FStream
 */
#include <fstream>



/**
 *	Include File System
 */
#include <filesystem>



/**
 *	Include Coder
 */
#include <ING/Coder/Coder.h>




namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ResourceManager::ResourceManager() {



	}

	ResourceManager::~ResourceManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ResourceManager::Init() {



		return Square::Init();
	}

	bool ResourceManager::Run() {



		return Square::Run();
	}

	bool ResourceManager::Release() {



		return Square::Release();
	}



	/**
	 *	Resource Management
	 */
	std::wstring	ResourceManager::ReadFile(const std::wstring& path, CoderOption& coderOption) {



		std::wstring parsedPath = path;



		std::wstring result;

		std::wfstream fileStream;

		std::streampos fileSize = 0;



		/* Open File */
		fileStream.open(path.c_str());



		/* Get File Size */
		fileStream.seekg(0, std::ios::end);

		fileSize = fileStream.tellg();

		fileStream.seekg(0, std::ios::beg);



		/* Read File */
		result.resize(fileSize);

		fileStream.read((wchar_t*)result.c_str(), fileSize);



		/* Close File */
		fileStream.close();



		if (coderOption.coder != nullptr) {

			result = coderOption.coder->Decode(result, coderOption.key);

		}



		return result;

	}

	void			ResourceManager::WriteFile(const std::wstring& path, const std::wstring& content, CoderOption& coderOption) {



		std::wstring parsedPath = path;



		std::wstring parsedContent;



		if (coderOption.coder != nullptr) {

			parsedContent = coderOption.coder->Encode(content, coderOption.key);

		}
		else {

			parsedContent = content;

		}

		std::wfstream fileStream;

		unsigned long fileSize = parsedContent.length();



		/* Resize File */
		std::filesystem::resize_file(path, fileSize);



		/* Open File */
		fileStream.open(path.c_str());



		fileStream << parsedContent;



		/* Close File */
		fileStream.close();

	}

}