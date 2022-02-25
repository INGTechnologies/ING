#pragma once

/**
 *	Include Header
 */
#include "Ptr.h"



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Component/System/System.h>



/**
 *	Include ECS Repository
 */
#include <ING/ECS/Repository/Repository.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Operators
		 */
		template<typename T, class TComponentSystem>
		T&	ComponentPtr<T, TComponentSystem>::operator * () {

			return GetComponentSystem()->GetComponentFromPtr(*this);

		}

		template<typename T, class TComponentSystem>
		T* ComponentPtr<T, TComponentSystem>::operator -> () {

			return GetComponentSystem()->GetComponentDataPtrFromPtr(*this);

		}

	}

}