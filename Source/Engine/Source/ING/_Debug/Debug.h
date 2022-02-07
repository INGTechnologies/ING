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



/**
 *	Include Windows
 */
#include <windows.h>



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
		 *	Color 
		 */
	public:
		static void SetConsoleColor(int color) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

		}



		/**
		 *	Loggers
		 */
	public:
		/* Category Macro */
#define LOG_CATEGORY() \
		SetConsoleColor(0x30);\
\
		std::wcout << " LOG ";\
			\
		SetConsoleColor(0x07);\
			\
		std::wcout << " ";


		
		static void Log() {

			LOG_CATEGORY()

			std::cout << std::endl;

		}

		static void Log(std::string content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(float content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(double content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(int content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(long content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(ui8 content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(ui16 content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(ui32 content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(ui64 content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(bool content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(const char* content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(const wchar_t* content) {

			LOG_CATEGORY()

			std::wcout << content << std::endl;

		}

		static void Log(char content) {

			LOG_CATEGORY()

			std::cout << content << std::endl;

		}

		static void Log(wchar_t content) {

			LOG_CATEGORY()

			std::wcout << content << std::endl;

		}

		static void Log(std::wstring content) {

			LOG_CATEGORY()

			std::wcout << content << std::endl;

		}

		/**
		 *	Math
		 */
		/* Vector */
		static void Log(Math::Vector2 content) {

			LOG_CATEGORY()

			SetConsoleColor(7);

			std::wcout << "Vector2( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		static void Log(Math::Vector3 content) {

			LOG_CATEGORY()

			SetConsoleColor(7);

			std::wcout << "Vector3( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(1);

			std::wcout << content.z;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		static void Log(Math::Vector4 content) {

			LOG_CATEGORY()

			SetConsoleColor(7);

			std::wcout << "Vector4( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(1);

			std::wcout << content.z;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(6);

			std::wcout << content.w;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		/* Float */
		static void Log(Math::F4IJK content) {

			LOG_CATEGORY()

			SetConsoleColor(7);

			std::wcout << "F4IJK( ";

			SetConsoleColor(4);

			std::wcout << content.factors[0];

			SetConsoleColor(8);

			std::wcout << " + ";

			SetConsoleColor(2);

			std::wcout << content.factors[1];

			SetConsoleColor(8);

			std::wcout << " * ";

			SetConsoleColor(7);

			std::wcout << "i";

			SetConsoleColor(8);

			std::wcout << " + ";

			SetConsoleColor(1);

			std::wcout << content.factors[2];

			SetConsoleColor(8);

			std::wcout << " * ";

			SetConsoleColor(7);

			std::wcout << "j";

			SetConsoleColor(8);

			std::wcout << " + ";

			SetConsoleColor(6);

			std::wcout << content.factors[3];

			SetConsoleColor(8);

			std::wcout << " * ";

			SetConsoleColor(7);

			std::wcout << "k";

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		/* Quaternion */
		static void Log(Math::Quaternion content) {

			LOG_CATEGORY()

			SetConsoleColor(7);

			std::wcout << "Quaternion( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(1);

			std::wcout << content.z;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(6);

			std::wcout << content.w;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}



		/**
		 *	Error Loggers
		 */
	public:
		/* Category Macro */
#define ERROR_CATEGORY() \
		SetConsoleColor(0x40);\
\
		std::wcout << " ERROR ";\
			\
		SetConsoleColor(0x07);\
			\
		std::wcout << " ";



		static void Error() {

			ERROR_CATEGORY();

			std::cout << std::endl;

		}

		static void Error(std::string content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(float content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(double content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(int content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(long content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(ui8 content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(ui16 content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(ui32 content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(ui64 content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(bool content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(const char* content) {

			ERROR_CATEGORY();

			std::cout << content << std::endl;

		}

		static void Error(const wchar_t* content) {

			ERROR_CATEGORY();

			std::wcout << content << std::endl;

		}

		static void Error(std::wstring content) {

			ERROR_CATEGORY();

			std::wcout << content << std::endl;

		}

		/**
		 *	Math
		 */
		 /* Vector */
		static void Error(Math::Vector2 content) {

			ERROR_CATEGORY();

			SetConsoleColor(7);

			std::wcout << "Error: Vector2( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		static void Error(Math::Vector3 content) {

			ERROR_CATEGORY();

			SetConsoleColor(7);

			std::wcout << "Vector3( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(1);

			std::wcout << content.z;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		static void Error(Math::Vector4 content) {

			ERROR_CATEGORY();

			SetConsoleColor(7);

			std::wcout << "Vector4( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(1);

			std::wcout << content.z;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(6);

			std::wcout << content.w;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		/* Float */
		static void Error(Math::F4IJK content) {

			ERROR_CATEGORY();

			SetConsoleColor(7);

			std::wcout << "F4IJK( ";

			SetConsoleColor(4);

			std::wcout << content.factors[0];

			SetConsoleColor(8);

			std::wcout << " + ";

			SetConsoleColor(2);

			std::wcout << content.factors[1];

			SetConsoleColor(8);

			std::wcout << " * ";

			SetConsoleColor(7);

			std::wcout << "i";

			SetConsoleColor(8);

			std::wcout << " + ";

			SetConsoleColor(1);

			std::wcout << content.factors[2];

			SetConsoleColor(8);

			std::wcout << " * ";

			SetConsoleColor(7);

			std::wcout << "j";

			SetConsoleColor(8);

			std::wcout << " + ";

			SetConsoleColor(6);

			std::wcout << content.factors[3];

			SetConsoleColor(8);

			std::wcout << " * ";

			SetConsoleColor(7);

			std::wcout << "k";

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

		/* Quaternion */
		static void Error(Math::Quaternion content) {

			ERROR_CATEGORY();

			SetConsoleColor(7);

			std::wcout << "Quaternion( ";

			SetConsoleColor(4);

			std::wcout << content.x;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(2);

			std::wcout << content.y;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(1);

			std::wcout << content.z;

			SetConsoleColor(8);

			std::wcout << ", ";

			SetConsoleColor(6);

			std::wcout << content.w;

			SetConsoleColor(7);

			std::wcout << " )" << std::endl;

		}

	};


}