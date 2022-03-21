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
 *	Include Rendering Material
 */
#include <ING/Rendering/Material/Material.h>



namespace ING {

	namespace Rendering {

		class IDrawableCategory;

		class IDrawble;

		class IShader;

		class IState;



		class ING_API DrawableMaterial : public IMaterial
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			DrawableMaterial	(const std::string& name, IShader* shader);
			~DrawableMaterial	();



			/**
			 *	Methods
			 */
		public:
			virtual void Apply	(const std::string& passName) override;

		};

	}

}