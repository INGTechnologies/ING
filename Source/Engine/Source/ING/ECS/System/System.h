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



/**
 *	Include Component System
 */
#include <ING/ECS/Component/System/System.h>



namespace ING {

	namespace ECS {

		class Component;



		class ING_API System
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			System();
			~System();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Component Management
			 */
		public:
			template<typename TComponentSystem>
			TComponentSystem* RegisterComponentSystem() {

				TComponentSystem* result = new TComponentSystem();

				return result;

			}

			template<typename TComponentSystem>
			void DeregisterComponentSystem() {



			}

		};

	}

}