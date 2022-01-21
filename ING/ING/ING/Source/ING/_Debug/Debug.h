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


	class Debug
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Debug();
		~Debug();



		/**
		 *	Loggers
		 */
	public:
		static void Log() {

			std::cout << std::endl;

		}

		static void Log(std::string content) {

			std::cout << content << std::endl;

		}

		static void Log(int content) {

			std::cout << content << std::endl;

		}

		static void Log(long content) {

			std::cout << content << std::endl;

		}

		static void Log(ui8 content) {

			std::cout << content << std::endl;

		}

		static void Log(ui16 content) {

			std::cout << content << std::endl;

		}

		static void Log(ui32 content) {

			std::cout << content << std::endl;

		}

		static void Log(ui64 content) {

			std::cout << content << std::endl;

		}

		static void Log(bool content) {

			std::cout << content << std::endl;

		}

		static void Log(const char* content) {

			std::cout << content << std::endl;

		}

		static void Log(const wchar_t* content) {

			std::wcout << content << std::endl;

		}

		static void Log(std::wstring content) {

			std::wcout << content << std::endl;

		}



		/**
		 *	Error Loggers
		 */
	public:
		static void Error() {

			std::cout << std::endl;

		}

		static void Error(std::string content) {

			std::cout << content << std::endl;

		}

		static void Error(int content) {

			std::cout << content << std::endl;

		}

		static void Error(long content) {

			std::cout << content << std::endl;

		}

		static void Error(ui8 content) {

			std::cout << content << std::endl;

		}

		static void Error(ui16 content) {

			std::cout << content << std::endl;

		}

		static void Error(ui32 content) {

			std::cout << content << std::endl;

		}

		static void Error(ui64 content) {

			std::cout << content << std::endl;

		}

		static void Error(bool content) {

			std::cout << content << std::endl;

		}

		static void Error(const char* content) {

			std::cout << content << std::endl;

		}

		static void Error(const wchar_t* content) {

			std::wcout << content << std::endl;

		}

		static void Error(std::wstring content) {

			std::wcout << content << std::endl;

		}

	};


}