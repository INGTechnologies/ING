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
 *	Include MethodContainer
 */
#include <ING/Scripting/CSharp/Method/Container/Container.h>



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



			class ING_API Class : public MethodContainer
			{

			public:
				friend class Context;



				/**
				 *	Constructors And Destructor
				 */
			public:
				Class	(Assembly* assembly, IContext* context);
				~Class	();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Properties
				 */
			private:
				MonoClass*			monoClass;

				String			_namespace;
				String			name;

			public:
				MonoClass*			GetMonoClass	()	{ return monoClass; }

				const String&	GetNamespace	()	{ return _namespace; }
				const String&	GetName			()	{ return _namespace; }

			};

		}

	}

}