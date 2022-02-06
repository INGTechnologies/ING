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
 *	Include Rendering Scene Manager
 */
#include <ING/Rendering/Scene/Manager/Manager.h>



namespace ING {

	namespace Rendering {

		class ING_API Scene
		{

			/**
			 *	Friend Classes
			 */
		public:
			friend class SceneManager;



			/**
			 *	Constructors And Destructor
			 */
		public:
			Scene();
			~Scene();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();

		};

	}

}