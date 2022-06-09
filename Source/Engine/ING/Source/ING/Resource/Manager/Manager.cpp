
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
	bool			ResourceManager::IsFileExist	(const WString& path) {

		return std::filesystem::exists(path);

	}

	WString	ResourceManager::ReadFile(const WString& path, CoderOption& coderOption) {

		if (!IsFileExist(path)) {

			Debug::Error(ToString("Cant Read File ") + ToString('"') + ToString(path) + ToString('"'));

			Engine::GetInstance()->Shutdown();

			return L"";
		}



		std::wifstream fileStream(path);

		WString result = WString(
			std::istreambuf_iterator<wchar_t>(fileStream),
			std::istreambuf_iterator<wchar_t>()
		);

		fileStream.close();



		if (coderOption.coder != nullptr) {

			result = coderOption.coder->Decode(result, coderOption.key);

		}



		return result;

	}

	void			ResourceManager::WriteFile(const WString& path, const WString& content, CoderOption& coderOption) {

		if (!IsFileExist(path)) {

			Debug::Error(String("Cant Write File ") + ToString('"') + ToString(path) + ToString('"'));

			Engine::GetInstance()->Shutdown();

			return;
		}



		WString parsedContent;



		if (coderOption.coder != nullptr) {

			parsedContent = coderOption.coder->Encode(content, coderOption.key);

		}
		else {

			parsedContent = content;

		}

		std::wfstream fileStream;

		size_t fileSize = parsedContent.size();



		if (std::filesystem::exists(path)) {

			std::filesystem::remove(path);

		}

		std::filesystem::create_directories(std::filesystem::path(path).parent_path());

		std::ofstream ofs(path);
		ofs.close();



		/* Resize File */
		std::filesystem::resize_file(path, fileSize);



		/* Open File */
		fileStream.open(path.c_str());



		fileStream << parsedContent;



		/* Close File */
		fileStream.close();

	}

}