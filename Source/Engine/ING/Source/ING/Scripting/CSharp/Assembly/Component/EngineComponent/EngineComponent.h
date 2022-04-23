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



/**
 *	Include CSharp Assembly Component
 */
#include <ING/Scripting/CSharp/Assembly/Component/Component.h>



namespace ING {

	namespace Scripting {

		class IContext;



		namespace CSharp {

			class Context;

			class Assembly;



			class ING_API EngineAssemblyComponent : public IAssemblyComponent
			{

			public:
				friend class Assembly;



				/**
				 *	Constructors And Destructor
				 */
			public:
				EngineAssemblyComponent		(Assembly* assembly, const std::string& name);
				~EngineAssemblyComponent	();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual void OnOpen		() override;
				virtual void OnClose	() override;

			};

		}

	}

}