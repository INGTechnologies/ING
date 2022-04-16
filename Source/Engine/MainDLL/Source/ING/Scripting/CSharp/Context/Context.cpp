
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



namespace ING {

	namespace Scripting {

		namespace CSharp {

			/**
			 *	Constructors And Destructor
			 */
			Context::Context(const std::string& name, ILanguage* language) :
				IContext(name, language),

				domain(0)
			{

				mono_set_dirs(".",".");

				domain = mono_jit_init(name.c_str());

				if (domain == 0) {

					Debug::Error("Cant Create CSharp Scripting Context");

					Release();

					return; 

				}

			}

			Context::~Context()
			{



			}



			/**
			 *	Release Method
			 */
			void Context::Release() {

				if (domain != 0) {

					mono_jit_cleanup(domain);

				}

				IContext::Release();

			}



			/**
			 *	Methods
			 */
			Assembly*			Context::LoadAssembly(const std::string& path) {

				Assembly* assembly = new Assembly(this);

				assembly->filePath = path;

				assembly->monoAssembly = mono_domain_assembly_open(domain, path.c_str());

				if (assembly->monoAssembly == 0) {

					assembly->Release();

					Debug::Error("Cant Create CSharp Assembly");

					return 0;

				}

				assembly->monoImage = mono_assembly_get_image(assembly->monoAssembly);

				return assembly;
			}

			Class*				Context::GetClass(Assembly* assembly, const std::string& name, const std::string& _namespace) {

				Class* result = new Class(this);

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

		}

	}

}