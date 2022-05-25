
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Object
 */
#include <ING/Object/Object.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	ObjectManager::ObjectManager() {

		Debug::Log("Start Creating ObjectManager");

		Debug::Log("ObjectManager Created");

	}

	ObjectManager::~ObjectManager() {



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool ObjectManager::Init() {

		Debug::Log("Start Initializing ObjectManager");

		idGenerator.RegisterUInt64Id(0);

		Debug::Log("ObjectManager Initialized");

		return Square::Init();
	}

	bool ObjectManager::Run() {

		Debug::Log("Start Running ObjectManager");

		return Square::Run();
	}

	bool ObjectManager::Release() {

		Debug::Log("Start Releasing ObjectManager");

		idGenerator.ClearIds();

		id2ObjectMap.clear();

		Debug::Log("Finished Releasing ObjectManager");

		return Square::Release();
	}



	/**
	 *	Methods
	 */
	void ObjectManager::RegisterObject(IObject* object) {

		mutex.lock();

		if (object->id == 0) {

			object->id = idGenerator.GenUInt64();

		}

		id2ObjectMap[object->id] = object;

		idGenerator.RegisterUInt64Id(object->id);

		mutex.unlock();

	}

	void ObjectManager::RemoveObject(IObject* object) {

		mutex.lock();

		id2ObjectMap.erase(object->id);

		idGenerator.RemoveUInt64Id(object->id);

		mutex.unlock();

	}

	IObject* ObjectManager::GetObjectById(ObjectId id) {

		if (id2ObjectMap.find(id) == id2ObjectMap.end()) {

#ifdef _DEBUG

			Debug::Error(ToString("Cant Find Object With Id ") + ToString(id));

#endif

			return 0;
		}

		return id2ObjectMap[id];

	}

}