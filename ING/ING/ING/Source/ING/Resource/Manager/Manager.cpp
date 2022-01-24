
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include FStream
 */
#include <fstream>



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
	std::wstring	ResourceManager::ReadFile(std::wstring path) {

		std::wstring result;

		std::wfstream fileStream;

		unsigned long fileSize = 0;



		/* Open File */
		fileStream.open(path.c_str());



		/* Get File Size */
		fileStream.seekg(0, std::ios::end);

		fileSize = fileStream.tellg();

		fileStream.seekg(0, std::ios::beg);



		/* Read File */
		while (fileStream.tellg() < fileSize) {

			wchar_t wchr;

			fileStream.read(&wchr, 1);

			result += wchr;

		}



		/* Close File */
		fileStream.close();



		return result;

	}

	void			ResourceManager::WriteFile(std::wstring path, std::wstring& content) {

		std::wstring result;

		std::wfstream fileStream;

		unsigned long fileSize = content.length();



		/* Open File */
		fileStream.open(path.c_str());



		for (unsigned long i = 0; i < fileSize; ++i) {

			fileStream << content[i];

		}



		/* Close File */
		fileStream.close();

	}

}