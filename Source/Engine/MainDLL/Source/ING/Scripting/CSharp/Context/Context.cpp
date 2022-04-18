
/**
 *	Include Header
 */
#include "Context.h"



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
 *	Include CSharp Assembly
 */
#include <ING/Scripting/CSharp/Assembly/Assembly.h>



/**
 *	Include CSharp Class
 */
#include <ING/Scripting/CSharp/Class/Class.h>



/**
 *	Include CSharp InternalMethod
 */
#include <ING/Scripting/CSharp/Method/OuternalMethod/OuternalMethod.h>



/**
 *	Include CSharp OuternalMethod
 */
#include <ING/Scripting/CSharp/Method/OuternalMethod/OuternalMethod.h>



/**
 *	Include CSharp Assembly Component Creator
 */
#include <ING/Scripting/CSharp/Assembly/Component/Creator/Creator.h>



/**
 *	Include CSharp Language
 */
#include <ING/Scripting/CSharp/Language/Language.h>



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Context::Context(const std::string& name, ILanguage* language, bool isMainContext) :
				IContext(name, language, isMainContext),

				domain(0)
			{

				if (isMainContext) {

					domain = ((CSharp::Language*)language)->GetRootDomain();

				}
				else {

					if (!CreateDomain()) {

						Release();

						return;

					}

				}

			}

			Context::~Context()
			{



			}



			/**
			 *	Release Method
			 */
			void Context::Release() {

				for (auto item = name2AssemblyMap.begin(); item != name2AssemblyMap.end();) {

					(item++)->second->Release();

				}

				UnloadDomain();

				for (auto item : name2AssemblyComponentCreatorMap) {

					item.second->Release();

				}

				IContext::Release();

			}



			/**
			 *	Methods
			 */
			bool				Context::CreateDomain() {

				if (IsMainContext()) return false;

				//domain = mono_jit_init(GetName().c_str());

				domain = mono_domain_create_appdomain((char*)GetName().c_str(), NULL);

				if (domain == 0) {

					Debug::Error("Cant Create CSharp Scripting Context");

					return false;

				}

			}

			bool				Context::UnloadDomain() {

				if (IsMainContext()) return false;

				if (domain == 0) return false;

				for (auto item : name2AssemblyMap) {

					item.second->OnClose();

				}

				mono_domain_unload(domain);

				domain = 0;

				return true;

			}

			Assembly*			Context::LoadAssembly(const std::string& path, const std::string& name) {

				return LoadAssembly(path, name, {});
			}

			Assembly*			Context::LoadAssembly(const std::string& path, const std::string& name, const std::vector<std::string>& componentNameVector) {

				std::string parsedPath = Path::GetAbsolutePath(path);

				Assembly* assembly = new Assembly(this, name, componentNameVector);

				assembly->filePath = parsedPath;

				name2AssemblyMap[name] = assembly;

				if (!OpenAssembly(name)) {

					assembly->Release();

					return 0;
				}

				return assembly;
			}

			bool				Context::OpenAssembly(const std::string& name) {

				Assembly* assembly = name2AssemblyMap[name];

				assembly->monoAssembly = mono_domain_assembly_open(domain, assembly->GetFilePath().c_str());

				if (assembly->monoAssembly == 0) {

					Debug::Error("Cant Create CSharp Assembly");

					return false;

				}

				assembly->monoImage = mono_assembly_get_image(assembly->monoAssembly);

				for (auto item : name2AssemblyMap) {

					item.second->OnOpen();

				}

				return true;

			}

			void				Context::RemoveAssembly(const std::string& name) {

				RemoveAssembly(name2AssemblyMap[name]);

			}

			void				Context::RemoveAssembly(Assembly* assembly) {

				std::string assemblyName = assembly->GetName();

				assembly->Release();

				name2AssemblyMap.erase(assemblyName);

			}

			Class*				Context::GetClass(Assembly* assembly, const std::string& name, const std::string& _namespace) {

				Class* result = new Class(assembly, this);

				result->_namespace = _namespace;
				result->name = name;

				result->monoClass = mono_class_from_name(assembly->monoImage, _namespace.c_str(), name.c_str());

				if (result->monoClass == 0) {

					result->Release();

					Debug::Error(String("Cant Get ") + String('"') + _namespace + String('::') + name + String('"') + String(" CSharp Class"));

					return 0;

				}

				return result;

			}

			IOuternalMethod*	Context::GetOuternalMethod(IMethodContainer* container, const std::string& name) {

				OuternalMethod* result = new OuternalMethod(this, container);

				result->assembly = ((Class*)container)->assembly;

				result->name = name;

				MonoMethodDesc* desc = mono_method_desc_new(name.c_str(), false);

				result->monoMethod = mono_method_desc_search_in_class(desc, ((Class*)container)->monoClass);

				mono_method_desc_free(desc);

				return result;
			}

			void Context::Load() {

				if (domain != 0) return;

				if (!CreateDomain()) {

					Debug::Error("Cant Load Main CSharp Context");

					return;
				}

				for (auto item : name2AssemblyMap) {

					OpenAssembly(item.first);

				}

			}

			void Context::Unload() {

				if (IsMainContext()) {

					Debug::Error("Cant Unload Main CSharp Context");

					return;

				}

				if (domain == 0) return;

				if (!UnloadDomain()) return;

			}

			void Context::Reload() {

				if (IsMainContext()) {

					Debug::Error("Cant Reload Main CSharp Context");

					return;

				}

				Unload();
				Load();

			}

			void Context::AddAssemblyComponentCreator(IAssemblyComponentCreator* creator) {

				name2AssemblyComponentCreatorMap[creator->GetName()] = creator;

			}

		}

	}

}