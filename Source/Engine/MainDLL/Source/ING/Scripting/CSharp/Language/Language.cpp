
/**
 *	Include Header
 */
#include "Language.h"



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



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

				mono_set_dirs(".", ".");

				rootDomain = mono_jit_init((GetName() + String("RootDomain")).c_str());

				APPLICATION_CONFIG_PROP(std::vector<IAssemblyComponentCreator*>, "ING::Scripting::CSharp::Language::assemblyComponentCreators", {



				});

				for (auto item : Application::GetInstance()->GetConfiguration()->Get<std::vector<IAssemblyComponentCreator*>>("ING::Scripting::CSharp::Language::assemblyComponentCreators")) {

					name2AssemblyComponentCreatorMap[item->GetName()] = item;

				}

				AddAssemblyComponentCreator(new AssemblyComponentCreator<EngineAssemblyComponent>("Engine"));

				UpdateCreation();		

				/* Open Engine, Context Assemblies */
				OpenAssemblies("Engine:/Scripting/CSharp/assemblies.ini", "Engine");
				OpenAssemblies("Content:/Scripting/CSharp/assemblies.ini", "Content");

			}

			Language::~Language()
			{



			}



			/**
			 *	Release Method
			 */
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

			std::string Language::GetName() { return "CSharp"; }

			IContext*	Language::CreateContext(const std::string& name, bool isMainContext) {

				if (mainContext != 0 && isMainContext == true) {

					Debug::Warning(GetName() + String(" Main Context Created"));

					return mainContext;

				}

				return new CSharp::Context(name, this, isMainContext);

			}

			std::vector<std::string> GetAssemblyComponentNames(const std::string& str) {

				std::string str2 = str;

				size_t characterCount = str2.size();

				unsigned int componentCount = 1;

				for (size_t i = 0; i < characterCount; ++i) {

					if (str[i] == ',') {

						str2[i] = ' ';

						++componentCount;

					}

				}

				std::vector<std::string> result(componentCount);

				std::stringstream ss(str2);
				std::string word;
				unsigned int index = 0;
				while (ss >> word) {

					result[index] = word;

					++index;

				}

				return result;

			}

			void		Language::OpenAssemblies(const std::string& iniFilePath, const std::string& tag) {

				std::string engineAssembliesPath = Path::GetAbsolutePath(iniFilePath);

				if (std::filesystem::exists(engineAssembliesPath)) {

					mINI::INIFile configFile(engineAssembliesPath);

					mINI::INIStructure compiledData;

					configFile.read(compiledData);

					size_t assemblyCount = compiledData.size();

					if (((Context*)mainContext)->assembly != 0) {

						for (auto item = compiledData.begin(); item != compiledData.end(); ++item) {

							std::string name = tag + String(".") + item->first;

							if (!item->second.has("path")) return;

							std::string path = item->second.get("path");

							path = path.substr(1, path.size() - 2);

							std::string componentsStr = item->second.get("components");

							componentsStr = componentsStr.substr(1, componentsStr.size() - 2);

							std::vector<std::string> componentNames = GetAssemblyComponentNames(componentsStr);

							std::string contextName = name;

							Context* context = (Context*)CreateContext(contextName, false);

							if (context->IsMainContext()) {

								Debug::Error(String("Cant Load Assembly ") + name);

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

							std::string name = tag + String(".") + compiledData.begin()->first;

							if (!compiledData.begin()->second.has("path")) return;

							std::string path = compiledData.begin()->second.get("path");

							path = path.substr(1, path.size() - 2);

							std::string componentsStr = compiledData.begin()->second.get("components");

							componentsStr = componentsStr.substr(1, componentsStr.size() - 2);

							std::vector<std::string> componentNames = GetAssemblyComponentNames(componentsStr);

							if (((CSharp::Context*)mainContext)->LoadAssembly(

								path,

								name,

								componentNames

							) == 0) return;

						}

						for (auto item = compiledData.begin() + 1; item != compiledData.end(); ++item) {

							std::string name = tag + String(".") + item->first;

							if (!item->second.has("path")) return;

							std::string path = item->second.get("path");

							path = path.substr(1, path.size() - 2);

							std::string componentsStr = item->second.get("components");

							componentsStr = componentsStr.substr(1, componentsStr.size() - 2);

							std::vector<std::string> componentNames = GetAssemblyComponentNames(componentsStr);

							std::string contextName = name;

							Context* context = (Context*)CreateContext(contextName, false);

							if (context->IsMainContext()) {

								Debug::Error(String("Cant Load Assembly ") + name);

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