
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Engine
 */
#include <ING/Engine/Engine.h>



/**
 *	Include Configuration
 */
#include <ING/Configuration/Configuration.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	PluginManager::PluginManager()
	{

		Debug::Log("Start Creating PluginManager");

		Debug::Log("PluginManager Created");

	}

	PluginManager::~PluginManager()
	{



	}



	/**
	 *	Init, Run, Release Methods
	 */
	bool PluginManager::Init()
	{

		Debug::Log("Start Initializing PluginManager");

		Debug::Log("PluginManager Initialized");

		return true;
	}

	bool PluginManager::Run()
	{

		Debug::Log("Start Running PluginManager");

		return true;
	}

	bool PluginManager::Release()
	{

		Debug::Log("Start Releasing PluginManager");

		name2Pointer.clear();

		delete this;

		Debug::Log("Finished Releasing PluginManager");

		return true;
	}



	/**
	 *	Properties
	 */
	void PluginManager::SetPointer(const String& name, void* pointer) {

		if (IsHasPointer(name)) return;

		name2Pointer[name] = pointer;

	}

	bool PluginManager::IsHasPointer(const String& name) {

		return name2Pointer.find(name) != name2Pointer.end();

	}

	void* PluginManager::GetPointer(const String& name) {

		if (!IsHasPointer(name)) return 0;

		return name2Pointer[name];

	}

	void PluginManager::RemovePointer(const String& name) {

		if (!IsHasPointer(name)) return;

		name2Pointer.erase(name);

	}

}