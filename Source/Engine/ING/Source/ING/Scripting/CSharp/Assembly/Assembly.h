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

			class IAssemblyComponent;



			class ING_API Assembly
			{

			public:
				friend class Context;



				/**
				 *	Constructors And Destructor
				 */
			protected:
				Assembly(Context* context, const std::string& name, const std::vector<std::string>& componentNameVector);
				~Assembly();



				/**
				 *	Release Method
				 */
			public:
				virtual void Release();



				/**
				 *	Properties
				 */
			private:
				Context*			context;

				MonoAssembly*		monoAssembly;

				MonoImage*			monoImage;

				std::string			filePath;

				std::string			name;

				std::vector<IAssemblyComponent*> componentVector;

				std::unordered_map<std::string, unsigned int> componentName2ComponentIndexMap;

				bool				isOpening;

			public:
				Context*			GetContext		() { return context; }
				IContext*			IGetContext		() { return (IContext*)context; }

				MonoAssembly*		GetMonoAssembly	() { return monoAssembly; }

				MonoImage*			GetMonoImage	() { return monoImage; }

				const std::string&	GetFilePath		() { return filePath; }

				const std::string&	GetName			() { return name; }

				bool				IsOpening		() { return isOpening; }



				/**
				 *	Methods
				 */
			public:
				void OnOpen		();
				void OnClose	();

			};

		}

	}

}