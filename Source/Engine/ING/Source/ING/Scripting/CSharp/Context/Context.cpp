
/**
 *	Include Header
 */
#include "Context.h"



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
			Context::Context(const String& name, ILanguage* language, bool isMainContext) :
				IContext(name, language, isMainContext),

				domain(0),
				assembly(0)
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

				((Language*)language)->AddContext(this);

			}

			Context::~Context()
			{



			}



			/**
			 *	Release Method
			 */
			void Context::Release() {

				if(assembly != 0)
					assembly->Release();

				UnloadDomain();

				((Language*)GetLanguage())->RemoveContext(this);

				IContext::Release();

			}



			/**
			 *	Methods
			 */
			bool				Context::CreateDomain() {

				if (IsMainContext()) return false;

				domain = mono_domain_create_appdomain((char*)GetName().c_str(), NULL);

				if (domain == 0) {

					Debug::Error("Cant Create CSharp Scripting Context");

					return false;

				}

			}

			bool				Context::UnloadDomain() {

				if (IsMainContext()) return false;

				if (domain == 0) return false;

				if(assembly != 0)
					assembly->OnClose();

				mono_domain_unload(domain);

				domain = 0;

				return true;

			}

			Assembly*			Context::LoadAssembly(const String& path, const String& name) {

				return LoadAssembly(path, name, {});
			}

			Assembly*			Context::LoadAssembly(const String& path, const String& name, const std::vector<String>& componentNameVector) {

				if (assembly != 0) {

					Debug::Warning("CSharp Assembly Loaded, Auto Reload Context Before Load New Assembly");

					RemoveAssembly();

					Reload();

				}

				String parsedPath = Path::GetAbsolutePath(path);

				assembly = new Assembly(this, name, componentNameVector);

				assembly->filePath = parsedPath;

				if (!OpenAssembly()) {

					assembly->Release();

					assembly = 0;

					return 0;
				}

				return assembly;
			}

			bool				Context::OpenAssembly() {

				if (assembly == 0) {

					Debug::Error("Cant Open Null Assembly");

					return 0;
				}

				assembly->monoAssembly = mono_domain_assembly_open(domain, assembly->GetFilePath().c_str());

				if (assembly->monoAssembly == 0) {

					Debug::Error("Cant Create CSharp Assembly");

					return false;

				}

				assembly->monoImage = mono_assembly_get_image(assembly->monoAssembly);

				assembly->OnOpen();

				return true;

			}

			void				Context::RemoveAssembly() {

				if (assembly != 0) {

					assembly->Release();

					assembly = 0;

				}

			}

			Class*				Context::GetClass(Assembly* assembly, const String& name, const String& _namespace) {

				Class* result = new Class(assembly, this);

				result->_namespace = _namespace;
				result->name = name;

				result->monoClass = mono_class_from_name(assembly->monoImage, _namespace.c_str(), name.c_str());

				if (result->monoClass == 0) {

					result->Release();

					Debug::Error(ToString("Cant Get ") + ToString('"') + _namespace + ToString('::') + name + ToString('"') + ToString(" CSharp Class"));

					return 0;

				}

				return result;

			}

			IOuternalMethod*	Context::GetOuternalMethod(IMethodContainer* container, const String& name) {

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

				OpenAssembly();

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

		}

	}

}