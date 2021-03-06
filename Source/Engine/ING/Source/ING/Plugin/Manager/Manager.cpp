
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



/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



/**
 *	Include MSVC Plugin
 */
#include <ING/Plugin/MSVC/Plugin/Plugin.h>



#include <filesystem>



/**
 *	Include ResourceManager
 */
#include <ING/Resource/Manager/Manager.h>



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

		name2PointerMap.clear();

		delete this;

		Debug::Log("Finished Releasing PluginManager");

		return true;
	}



	/**
	 *	Properties
	 */
	void PluginManager::SetPointer(const String& name, void* pointer) {

		if (IsHasPointer(name)) return;

		name2PointerMap[name] = pointer;

	}

	bool PluginManager::IsHasPointer(const String& name) {

		return name2PointerMap.find(name) != name2PointerMap.end();

	}

	void* PluginManager::GetPointer(const String& name) {

		if (!IsHasPointer(name)) return 0;

		return name2PointerMap[name];

	}

	void PluginManager::RemovePointer(const String& name) {

		if (!IsHasPointer(name)) return;

		name2PointerMap.erase(name);

	}



	/**
	 *	Methods
	 */
	bool PluginManager::LoadPlugins(const WString& path) {

		WString absolutePath = Path::GetAbsolutePath(path);

		if (!std::filesystem::exists(absolutePath)) return true;



		WString absoluteJSONFilePath = Path::Normalize(absolutePath + ToWString(L"/Plugins.json"));

		if (!std::filesystem::exists(absoluteJSONFilePath)) return true;



		JSON pluginsJSON = ParseJSON(ResourceManager::GetInstance()->ReadFile(absoluteJSONFilePath));

		std::vector<String> pluginNameVector = pluginsJSON;



		for (const auto& pluginName : pluginNameVector) {

			WString pluginDLLPath = Path::Normalize(absolutePath + ToWString(L'/') + ToWString(pluginName) + ToWString(L'/') + ToWString(pluginName) + ToWString(L".dll"));

			if (std::filesystem::exists(pluginDLLPath)) {

				IPlugin* plugin = IPlugin::Create(pluginDLLPath);

				if (!plugin->Load()) return false;

			}

		}

		return true;
	}

	List<IPlugin*>::Node* PluginManager::AddPlugin(IPlugin* plugin) {

		if (IsHasPlugin(plugin->GetName())) return 0;

		name2PluginMap[plugin->GetName()] = plugin;

		return pluginList.Add(plugin);

	}

	void PluginManager::RemovePlugin(IPlugin* plugin) {

		if (!IsHasPlugin(plugin->GetName())) return;

		name2PluginMap.erase(plugin->GetName());

		pluginList.Remove(plugin->GetNode());

	}

	bool PluginManager::LateCreate() {

		for (auto plugin : pluginList) {

			if (!plugin->LateCreate())return false;

		}

		return true;
	}

	bool PluginManager::PreInit() {

		for (auto plugin : pluginList) {

			if (!plugin->PreInit())return false;

		}

		return true;
	}

	bool PluginManager::LateInit() {

		for (auto plugin : pluginList) {

			if (!plugin->LateInit())return false;

		}

		return true;
	}

	bool PluginManager::PreRun() {

		for (auto plugin : pluginList) {

			if (!plugin->PreRun())return false;

		}

		return true;
	}

	bool PluginManager::PreRelease() {

		for (auto item = pluginList.GetTailNode(); ; item = item->prev) {

			if (!(*((IPlugin**)item->pValue))->Release()) return false;

			if (item == pluginList.GetHeadNode()) {

				break;

			}

		}

		return true;
	}

}