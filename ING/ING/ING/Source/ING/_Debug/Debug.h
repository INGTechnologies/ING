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

	};


}