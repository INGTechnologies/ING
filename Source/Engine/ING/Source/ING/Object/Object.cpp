
/**
 *	Include Header
 */
#include "Object.h"



/**
 *	Include Object Manager
 */
#include <ING/Object/Manager/Manager.h>



namespace ING {

	/**
	 *	Constructor And Destructors
	 */
	IObject::IObject() :
		id(0)
	{

		ObjectManager::GetInstance()->RegisterObject(this);

	}

	IObject::IObject(ObjectId id) :
		id(id)
	{

		ObjectManager::GetInstance()->RegisterObject(this);

	}

	IObject::~IObject() {



	}



	/**
	 *	Methods
	 */
	void IObject::Release() {

		ObjectManager::GetInstance()->RemoveObject(this);

		delete this;

	}

}