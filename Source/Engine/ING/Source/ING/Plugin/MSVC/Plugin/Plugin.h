#pragma once

#ifdef USE_MSVC

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Plugin
 */
#include <ING/Plugin/Plugin.h>



#include <Windows.h>



namespace ING {

	class Engine;



	namespace MSVC {

		class ING_API Plugin : public IPlugin {

			/**
			 *	Constructors And Destructor
			 */
		public:
			Plugin(const WString& path);
			~Plugin();



			/**
			 *	Release Method
			 */
		public:
			virtual void Release() override;



			/**
			 *	Properties
			 */
		private:
			HMODULE						moduleHandle;



			/**
			 *	Methods
			 */
		public:
			virtual bool Load		()	override;
			virtual bool Unload		()	override;

			virtual void LateCreate	()	override;

			virtual void PreInit	()	override;
			virtual void LateInit	()	override;

			virtual void PreRun		()	override;

			virtual void PreRelease	()	override;

		};

	}

}

#endif