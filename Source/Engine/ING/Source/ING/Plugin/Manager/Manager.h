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



namespace ING {

	class IPlugin;



	class ING_API PluginManager :
		public Singleton<PluginManager>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		PluginManager();
		~PluginManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();



		/**
		 *	Properties
		 */
	private:
		std::unordered_map<String, void*> name2Pointer;

	public:
		void		SetPointer		(const String& name, void* pointer);
		bool		IsHasPointer	(const String& name);
		void*		GetPointer		(const String& name);
		void		RemovePointer	(const String& name);

	};

}