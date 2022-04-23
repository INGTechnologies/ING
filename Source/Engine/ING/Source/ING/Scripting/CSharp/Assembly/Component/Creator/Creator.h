#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Mono
 */
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>



namespace ING {

	namespace Scripting {

		class IContext;



		namespace CSharp {

			class Context;

			class Assembly;

			class IAssemblyComponent;



			class ING_API IAssemblyComponentCreator
			{

				/**
				 *	Constructors And Destructor
				 */
			protected:
				IAssemblyComponentCreator	(const std::string& name);
				~IAssemblyComponentCreator	();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release();



				/**
				 *	Properties
				 */
			private:
				std::string			name;

			public:
				const std::string&	GetName			() { return name; }



				/**
				 *	Methods
				 */
			public:
				virtual IAssemblyComponent* Create	(Assembly* assembly);

			};



			template<class T>
			class AssemblyComponentCreator : public IAssemblyComponentCreator {

				/**
				 *	Constructors And Destructor
				 */
			public:
				AssemblyComponentCreator(const std::string& name) :
					IAssemblyComponentCreator(name)
				{



				}

				~AssemblyComponentCreator() {



				}



				/**
				 *	Methods
				 */
			public:
				virtual IAssemblyComponent* Create(Assembly* assembly) override;

			};

			template<class T>
			IAssemblyComponent* AssemblyComponentCreator<T>::Create(Assembly* assembly) {

				return new T(assembly, GetName());

			}

		}

	}

}