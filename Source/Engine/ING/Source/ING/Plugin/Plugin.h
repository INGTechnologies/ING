#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class ING_API IPlugin {

		/**
		 *	Constructors And Destructor
		 */
	public:
		IPlugin(const String& name, const WString& path);
		~IPlugin();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		String  name;
		WString path;

	public:
		const String& GetName() { return name; }
		const WString& GetPath() { return path; }



		/**
		 *	Methods
		 */
	public:
		static IPlugin* Create(const String& name, const WString& path);

		virtual bool Load	();
		virtual bool Unload	();

		virtual void LateCreate();

		virtual void PreInit();
		virtual void LateInit();

		virtual void PreRun();

	};

}