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
	+  **SetConsoleColor**(int color) (void) (static)**:** set console text color
	+  **Log**(...) (void) (static)**:** log something to console window
		* **Log**(void* content) (void) (static): log pointer
		* **Log**(float content) (void) (static): log float variable
		* **Log**(double content) (void) (static): log double variable
		* **Log**(long content) (void) (static): log long variable
		* **Log**(ui8 content) (void) (static): log ui8 variable
		* **Log**(ui16 content) (void) (static): log ui16 variable
		* **Log**(ui32 content) (void) (static): log ui32 variable
		* **Log**(ui64 content) (void) (static): log ui64 variable
		* **Log**(bool content) (void) (static): log bool variable
		* **Log**(const char* content) (void) (static): log char array
		* **Log**(const wchar_t* content) (void) (static): log wchar array
		* **Log**(char content) (void) (static): log char variable
		* **Log**(wchar_t content) (void) (static): log wchar_t variable
		* **Log**(std::string content) (void) (static): log ascii string
		* **Log**(std::wstring content) (void) (static): log wide string
	+  **Warning**(...) (void) (static)**:** warning something to console window
		* **Warning**(void* content) (void) (static): warning pointer
		* **Warning**(float content) (void) (static): warning float variable
		* **Warning**(double content) (void) (static): warning double variable
		* **Warning**(long content) (void) (static): warning long variable
		* **Warning**(ui8 content) (void) (static): warning ui8 variable
		* **Warning**(ui16 content) (void) (static): warning ui16 variable
		* **Warning**(ui32 content) (void) (static): warning ui32 variable
		* **Warning**(ui64 content) (void) (static): warning ui64 variable
		* **Warning**(bool content) (void) (static): warning bool variable
		* **Warning**(const char* content) (void) (static): warning char array
		* **Warning**(const wchar_t* content) (void) (static): warning wchar array
		* **Warning**(char content) (void) (static): warning char variable
		* **Warning**(wchar_t content) (void) (static): warning wchar_t variable
		* **Warning**(std::string content) (void) (static): warning ascii string
		* **Warning**(std::wstring content) (void) (static): warning wide string
	+  **Error**(...) (void) (static)**:** error something to console window
		* **Error**(void* content) (void) (static): error pointer
		* **Error**(float content) (void) (static): error float variable
		* **Error**(double content) (void) (static): error double variable
		* **Error**(long content) (void) (static): error long variable
		* **Error**(ui8 content) (void) (static): error ui8 variable
		* **Error**(ui16 content) (void) (static): error ui16 variable
		* **Error**(ui32 content) (void) (static): error ui32 variable
		* **Error**(ui64 content) (void) (static): error ui64 variable
		* **Error**(bool content) (void) (static): error bool variable
		* **Error**(const char* content) (void) (static): error char array
		* **Error**(const wchar_t* content) (void) (static): error wchar array
		* **Error**(char content) (void) (static): error char variable
		* **Error**(wchar_t content) (void) (static): error wchar_t variable
		* **Error**(std::string content) (void) (static): error ascii string
		* **Error**(std::wstring content) (void) (static): error wide string