
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
	Object::Object() :
		id(0)
	{

		ObjectManager::GetInstance()->RegisterObject(this);

	}

	Object::Object(ObjectId id) :
		id(id)
	{

		ObjectManager::GetInstance()->RegisterObject(this);

	}

	Object::~Object() {



	}



	/**
	 *	Methods
	 */
	void Object::Release() {

		ObjectManager::GetInstance()->RemoveObject(this);

		delete this;

	}

}