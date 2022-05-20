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
 *	Include Event
 */
#include <ING/Event/Event.h>



namespace ING {

	namespace Rendering {

		class IMaterial;



		class ING_API IMaterialEvent : public Event {

			/**
			 *	Friend Classes
			 */
		public:
			friend class IMaterial;



			/**
			 *	Constructors And Destructor
			 */
		public:
			IMaterialEvent	(IMaterial* material) : material(material) {



			}

			~IMaterialEvent	() {



			}



			/**
			 *	Material
			 */
		private:
			IMaterial* material;

		public:
			IMaterial* GetMaterial() { return material; }

		};

	}

}