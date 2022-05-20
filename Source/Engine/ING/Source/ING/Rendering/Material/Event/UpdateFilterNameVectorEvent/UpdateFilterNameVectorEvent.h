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
 *	Include MaterialEvent
 */
#include <ING/Rendering/Material/Event/Event.h>



namespace ING {

	namespace Rendering {

		class IMaterial;



		class ING_API MaterialUpdateFilterNameVectorEvent : public IMaterialEvent {

			/**
			 *	Constructors And Destructor
			 */
		public:
			MaterialUpdateFilterNameVectorEvent		(IMaterial* material);

			~MaterialUpdateFilterNameVectorEvent	();



			/**
			 *	Name
			 */
		public:
			virtual String GetName() override;



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