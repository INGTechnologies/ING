#pragma once

/**
 *	Include Header
 */
#include "Ptr.h"



/**
 *	Include ECS Component System
 */
#include <ING/ECS/Core/Component/System/System.h>



/**
 *	Include ECS Repository
 */
#include <ING/ECS/Core/Repository/Repository.h>



/**
 *	Define Class Members,...
 */
namespace ING {

	namespace ECS {

		/**
		 *	Operators
		 */
		template<typename T, class TComponentSystem>
		T&	ComponentPtr<T, TComponentSystem>::operator * () const {

			return GetComponentSystem()->GetComponentFromPtr(*this);

		}

		template<typename T, class TComponentSystem>
		T* ComponentPtr<T, TComponentSystem>::operator -> () const {

			return GetComponentSystem()->GetComponentDataPtrFromPtr(*this);

		}

	}

}