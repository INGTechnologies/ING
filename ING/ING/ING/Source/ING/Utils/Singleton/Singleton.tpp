#pragma once

#include "Singleton.h"

namespace ING {

	namespace Utils {

		template<class T>
		T* Singleton<T>::mInstance;

		template<class T>
		T* Singleton<T>::GetInstance() {
			return mInstance;
		}

	}

}