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
 *	Include ScreenDesc
 */
#include <ING/Screen/Desc/Desc.h>



/**
 *	Include ScreenManager
 */
#include <ING/Screen/Manager/Manager.h>



namespace ING {

	class ING_API Screen
	{

		/**
		 *	Friend Classes
		 */
	public:
		friend class ScreenManager;



		/**
		 *	Constructors And Destructor
		 */
	public:
		Screen();
		Screen(ScreenDesc desc);
		~Screen();



		/**
		 *	InitWithDesc, Release Methods
		 */
	private:
		virtual void InitWithDesc(ScreenDesc desc);

	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		bool	isMain;
		ScreenDesc desc;

	public:
		bool		IsMain() { return isMain; }

		ScreenDesc	GetDesc() { return desc; }

	};

}