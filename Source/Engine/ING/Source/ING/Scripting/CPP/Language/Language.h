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
 *	Include Language
 */
#include <ING/Scripting/Language/Language.h>



namespace ING {

	namespace Scripting {

		namespace CPP {

			class Context;



			class ING_API Language : public ILanguage
			{

				/** 
				 *	Constructors And Destructor
				 */
			public:
				Language();
				~Language();



				/**
				 *	Init, Release Method
				 */
			public:
				virtual void Init	() override;
				virtual void Release() override;



				/**
				 *	Methods
				 */
			public:
				virtual String GetName()		override;

				virtual IContext*	CreateContext(const String& name, bool isMainContext) override;

			};

		}

	}

}