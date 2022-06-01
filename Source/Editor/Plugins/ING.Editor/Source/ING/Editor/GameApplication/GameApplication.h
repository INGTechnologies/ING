#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING/Editor/EntryPoint/EntryPoint.h>



/**
 *	Include GameApplication
 */
#include <ING/GameApplication/GameApplication.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include IOStream
 */
#include <iostream>



namespace ING {

	namespace Editor {

		class PLUGIN_API(ING_EDITOR) GameApplication :
			public IGameApplication
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			GameApplication (const WString & configPath);
			~GameApplication();



			/**
			 *	Init, Release Methods
			 */
		public:
			virtual bool Init() override;
			virtual void Release() override;



			/**
			 *	Methods
			 */
		public:
			virtual void Start();

			virtual void PreUpdate();
			virtual void Update();
			virtual void LateUpdate();

			virtual void PreRender();
			virtual void Render();
			virtual void LateRender();

		};

	}

}