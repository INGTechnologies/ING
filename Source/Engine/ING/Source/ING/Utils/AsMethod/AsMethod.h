#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



namespace ING {

	namespace Utils {

		class AsMethod {
		public:
			AsMethod() {



			}

			~AsMethod() {



			}

		public:
			template<typename T>
			T* As() {

				return (T*)this;

			}

		};

	}

}