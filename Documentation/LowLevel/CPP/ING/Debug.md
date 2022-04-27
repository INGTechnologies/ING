# ING::Debug class #  


## Basic Info ##
-  `Description`: a class that has some debugging method
-  `Parent Class`: None
-  `Project`: **Engine**/**ING**  (c++, dll)

## Members ##
-  `Constructor`:
	+  **Debug**()
-  `Destructor`:
	+  **~Debug**()
-  `Methods`:
	+  static void **SetConsoleColor**(int color) **:** set console text color
	+  static void **Log**(...) **:** log something to console window
		* static void **Log**(void* content) **:** log pointer
		* static void **Log**(float content) **:** log float variable
		* static void **Log**(double content) **:** log double variable
		* static void **Log**(long content) **:** log long variable
		* static void **Log**(ui8 content) **:** log ui8 variable
		* static void **Log**(ui16 content) **:** log ui16 variable
		* static void **Log**(ui32 content) **:** log ui32 variable
		* static void **Log**(ui64 content) **:** log ui64 variable
		* static void **Log**(bool content) **:** log bool variable
		* static void **Log**(const char* content) **:** log char array
		* static void **Log**(const wchar_t* content) **:** log wchar array
		* static void **Log**(char content) **:** log char variable
		* static void **Log**(wchar_t content) **:** log wchar_t variable
		* static void **Log**(std::string content) **:** log ascii string
		* static void **Log**(std::wstring content) **:** log wide string
	+  static void **Warning**(...) **:** warning something to console window
		* static void **Warning**(void* content) **:** warning pointer
		* static void **Warning**(float content) **:** warning float variable
		* static void **Warning**(double content) **:** warning double variable
		* static void **Warning**(long content) **:** warning long variable
		* static void **Warning**(ui8 content) **:** warning ui8 variable
		* static void **Warning**(ui16 content) **:** warning ui16 variable
		* static void **Warning**(ui32 content) **:** warning ui32 variable
		* static void **Warning**(ui64 content) **:** warning ui64 variable
		* static void **Warning**(bool content) **:** warning bool variable
		* static void **Warning**(const char* content) **:** warning char array
		* static void **Warning**(const wchar_t* content) **:** warning wchar array
		* static void **Warning**(char content) **:** warning char variable
		* static void **Warning**(wchar_t content) **:** warning wchar_t variable
		* static void **Warning**(std::string content) **:** warning ascii string
		* static void **Warning**(std::wstring content) **:** warning wide string
	+  static void **Error**(...) **:** error something to console window
		* static void **Error**(void* content) **:** error pointer
		* static void **Error**(float content) **:** error float variable
		* static void **Error**(double content) **:** error double variable
		* static void **Error**(long content) **:** error long variable
		* static void **Error**(ui8 content) **:** error ui8 variable
		* static void **Error**(ui16 content) **:** error ui16 variable
		* static void **Error**(ui32 content) **:** error ui32 variable
		* static void **Error**(ui64 content) **:** error ui64 variable
		* static void **Error**(bool content) **:** error bool variable
		* static void **Error**(const char* content) **:** error char array
		* static void **Error**(const wchar_t* content) **:** error wchar array
		* static void **Error**(char content) **:** error char variable
		* static void **Error**(wchar_t content) **:** error wchar_t variable
		* static void **Error**(std::string content) **:** error ascii string
		* static void **Error**(std::wstring content) **:** error wide string