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
 *	Include Math
 */
#include <ING/Math/Math.h>



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

		static void Log(float content) {

			std::cout << content << std::endl;

		}

		static void Log(double content) {

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

		static void Log(char content) {

			std::cout << content << std::endl;

		}

		static void Log(wchar_t content) {

			std::wcout << content << std::endl;

		}

		static void Log(std::wstring content) {

			std::wcout << content << std::endl;

		}

		/**
		 *	Math
		 */
		/* Vector */
		static void Log(Math::Vector2 content) {

			std::wcout << "(" << content.x << ", " << content.y << ")" << std::endl;

		}

		static void Log(Math::Vector3 content) {

			std::wcout << "(" << content.x << ", " << content.y << ", " << content.z << ")" << std::endl;

		}

		static void Log(Math::Vector4 content) {

			std::wcout << "(" << content.x << ", " << content.y << ", " << content.z << ", " << content.w << ")" << std::endl;

		}

		/* Complex */
		static void Log(Math::Complex4 content) {

			std::wcout << "" << content.factors[0] << " + " << content.factors[1] << " * i + " << content.factors[2] << " * j + " << content.factors[3] << " * k" << std::endl;

		}

		/* Quaternion */
		static void Log(Math::Quaternion content) {

			std::wcout << "(" << content.x << ", " << content.y << ", " << content.z << ", " << content.w << ")" << std::endl;

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

		static void Error(float content) {

			std::cout << content << std::endl;

		}

		static void Error(double content) {

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

		/**
		 *	Math
		 */
		 /* Vector */
		static void Error(Math::Vector2 content) {

			std::wcout << "(" << content.x << ", " << content.y << ")" << std::endl;

		}

		static void Error(Math::Vector3 content) {

			std::wcout << "(" << content.x << ", " << content.y << ", " << content.z << ")" << std::endl;

		}

		static void Error(Math::Vector4 content) {

			std::wcout << "(" << content.x << ", " << content.y << ", " << content.z << ", " << content.w << ")" << std::endl;

		}

		/* Complex */
		static void Error(Math::Complex4 content) {

			std::wcout << "" << content.factors[0] << " + " << content.factors[1] << " * i + " << content.factors[2] << " * j + " << content.factors[3] << " * k" << std::endl;

		}

		/* Quaternion */
		static void Error(Math::Quaternion content) {

			std::wcout << "(" << content.x << ", " << content.y << ", " << content.z << ", " << content.w << ")" << std::endl;

		}

	};


}