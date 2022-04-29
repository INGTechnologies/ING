
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



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>




namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ResourceManager::ResourceManager() {

		Debug::Log("Start Creating ResourceManager");

		Debug::Log("ResourceManager Created");

	}

	ResourceManager::~ResourceManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ResourceManager::Init() {

		Debug::Log("Start Initializing ResourceManager");

		Debug::Log("ResourceManager Initialized");

		return Square::Init();
	}

	bool ResourceManager::Run() {

		Debug::Log("Start Running ResourceManager");

		return Square::Run();
	}

	bool ResourceManager::Release() {

		Debug::Log("Start Releasing ResourceManager");

		Debug::Log("Finished Releasing ResourceManager");

		return Square::Release();
	}



	/**
	 *	Resource Management
	 */
	bool			ResourceManager::IsFileExist	(const std::wstring& path) {

		return std::filesystem::exists(path);

	}

	std::wstring	ResourceManager::ReadFile(const std::wstring& path, CoderOption& coderOption) {

		if (!IsFileExist(path)) {

			Debug::Error(ToString("Cant Read File ") + ToString('"') + ToString(path) + ToString('"'));

			Engine::GetInstance()->Shutdown();

			return L"";
		}



		std::wstring result;

		std::wfstream fileStream;

		std::streampos fileSize = 0;



		/* Open File */
		fileStream.open(path.c_str());



		/* Get File Size */
		fileStream.seekg(0, std::wios::end);

		fileSize = fileStream.tellg();

		fileStream.seekg(0, std::wios::beg);



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

		if (!IsFileExist(path)) {

			Debug::Error(String("Cant Write File ") + ToString('"') + ToString(path) + ToString('"'));

			Engine::GetInstance()->Shutdown();

			return;
		}



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