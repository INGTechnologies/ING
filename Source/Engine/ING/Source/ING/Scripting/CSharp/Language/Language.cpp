
/**
 *	Include Header
 */
#include "Language.h"



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
 *	Include CSharp Context
 */
#include <ING/Scripting/CSharp/Context/Context.h>



/**
 *	Include Scripting Manager
 */
#include <ING/Scripting/Manager/Manager.h>



#define MINI_CASE_SENSITIVE

/**
 *	Include mIni
 */
#include <ING/Configuration/mINI/src/mini/ini.h>

#undef MINI_CASE_SENSITIVE



#include <filesystem>



/**
 *	Include CSharp Assembly Component Creator
 */
#include <ING/Scripting/CSharp/Assembly/Component/Creator/Creator.h>



/**
 *	Include CSharp Engine Assembly Component
 */
#include <ING/Scripting/CSharp/Assembly/Component/EngineComponent/EngineComponent.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Language::Language() :
				ILanguage()
			{

				AddAssemblyComponentCreator(new AssemblyComponentCreator<EngineAssemblyComponent>("Engine"));

			}

			Language::~Language()
			{



			}



			/**
			 *	Init, Release Method
			 */
			void Language::Init() {

				mono_set_dirs(".", ".");

				rootDomain = mono_jit_init((GetName() + String("RootDomain")).c_str());

				ILanguage::Init();

				/* Open Engine, Game Assemblies */
				OpenAssemblies(L"Engine:/Scripting/CSharp/Assemblies.ini", "Engine");

			}

			void Language::Release() {

				MonoDomain* rootDomain = this->rootDomain;

				for (auto item = name2ContextMap.begin(); item != name2ContextMap.end();) {

					if (!item->second->IsMainContext())
						(item++)->second->Release();
					else
						item++;

				}

				for (auto item = name2AssemblyComponentCreatorMap.begin(); item != name2AssemblyComponentCreatorMap.end();) {

					(item++)->second->Release();

				}

				ILanguage::Release();

				mono_jit_cleanup(rootDomain);

			}



			/**
			 *	Methods
			 */
			void		Language::AddContext	(Context* context) {

				name2ContextMap[context->GetName()] = context;

			}

			void		Language::RemoveContext	(Context* context) {

				name2ContextMap.erase(context->GetName());

			}

			String Language::GetName() { return "CSharp"; }

			IContext*	Language::CreateContext(const String& name, bool isMainContext) {

				if (mainContext != 0 && isMainContext == true) {

					Debug::Warning(GetName() + String(" Main Context Created"));

					return mainContext;

				}

				return new CSharp::Context(name, this, isMainContext);

			}

			std::vector<String> GetAssemblyComponentNames(const String& str) {

				String str2 = str;

				size_t characterCount = str2.size();

				unsigned int componentCount = 1;

				for (size_t i = 0; i < characterCount; ++i) {

					if (str[i] == ',') {

						str2[i] = ' ';

						++componentCount;

					}

				}

				std::vector<String> result(componentCount);

				std::stringstream ss(str2);
				String word;
				unsigned int index = 0;
				while (ss >> word) {

					result[index] = word;

					++index;

				}

				if (result.size() == 1) {

					if (result[0] == "") {

						result.resize(0);

					}

				}

				return result;

			}

			void		Language::OpenAssemblies(const WString& iniFilePath, const String& tag) {

				WString engineAssembliesPath = Path::GetAbsolutePath(iniFilePath);

				if (std::filesystem::exists(engineAssembliesPath)) {

					mINI::INIFile configFile(ToString(engineAssembliesPath));

					mINI::INIStructure compiledData;

					configFile.read(compiledData);

					size_t assemblyCount = compiledData.size();

					if (assemblyCount == 0) return;

					if (((Context*)mainContext)->assembly != 0) {

						for (auto item = compiledData.begin(); item != compiledData.end(); ++item) {

							String name = tag + String(".") + item->first;

							if (!item->second.has("path")) return;

							WString path = ToWString(item->second.get("path"));

							path = path.substr(1, path.size() - 2);

							String componentsStr = item->second.get("components");

							componentsStr = componentsStr.substr(1, componentsStr.size() - 2);

							std::vector<String> componentNames = GetAssemblyComponentNames(componentsStr);

							String contextName = name;

							Context* context = (Context*)CreateContext(contextName, false);

							if (context->IsMainContext()) {

								Debug::Error(String("Assembly Name Is Repeated (") + name + String(")"));

								continue;

							}

							if (context->LoadAssembly(

								path,

								name,

								componentNames

							) == 0) {

								Debug::Error(String("Cant Load Assembly ") + name);

							}

						}

					}
					else {

						if (assemblyCount >= 1) {

							String name = tag + String(".") + compiledData.begin()->first;

							if (!compiledData.begin()->second.has("path")) return;

							WString path = ToWString(compiledData.begin()->second.get("path"));

							path = path.substr(1, path.size() - 2);

							String componentsStr = compiledData.begin()->second.get("components");

							componentsStr = componentsStr.substr(1, componentsStr.size() - 2);

							std::vector<String> componentNames = GetAssemblyComponentNames(componentsStr);

							if (((CSharp::Context*)mainContext)->LoadAssembly(

								path,

								name,

								componentNames

							) == 0) return;

						}

						for (auto item = compiledData.begin() + 1; item != compiledData.end(); ++item) {

							String name = tag + String(".") + item->first;

							if (!item->second.has("path")) return;

							WString path = ToWString(item->second.get("path"));

							path = path.substr(1, path.size() - 2);

							String componentsStr = item->second.get("components");

							componentsStr = componentsStr.substr(1, componentsStr.size() - 2);

							std::vector<String> componentNames = GetAssemblyComponentNames(componentsStr);

							String contextName = name;

							Context* context = (Context*)CreateContext(contextName, false);

							if (context->IsMainContext()) {

								Debug::Error(String("Assembly Name Is Repeated (") + name + String(")"));

								continue;

							}

							if (context->LoadAssembly(

								path,

								name,

								componentNames

							) == 0) {

								Debug::Error(String("Cant Load Assembly ") + name);

								context->Release();

							}

						}

					}

				}

			}

			void Language::AddAssemblyComponentCreator(IAssemblyComponentCreator* creator) {

				if (name2AssemblyComponentCreatorMap.find(creator->GetName()) == name2AssemblyComponentCreatorMap.end()) {

					name2AssemblyComponentCreatorMap[creator->GetName()] = creator;

				}

			}

		}

	}

}