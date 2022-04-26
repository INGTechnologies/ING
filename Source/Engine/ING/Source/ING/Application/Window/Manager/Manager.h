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

	class IApplication;

	class IWindow;



	class ING_API ApplicationWindowManager
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationWindowManager	(IApplication* application);
		~ApplicationWindowManager	();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		IApplication*		application;

		std::unordered_map<std::string, IWindow*> name2WindowMap;

	public:
		IApplication*		GetApplication	() {return application; }

		IWindow*			GetWindow		(const std::string& name) { return name2WindowMap[name]; }



		/**
		 *	Methods
		 */
	public:
		void AddWindow		(IWindow* window);
		void RemoveWindow	(IWindow* window);

	};

}