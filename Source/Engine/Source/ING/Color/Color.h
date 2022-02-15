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
 *	Include Math
 */
#include <ING/Math/Math.h>

using namespace ING::Math;



namespace ING {

	struct ING_API Color : public Vector4 {
	
		/**
		 *	Constructors And Destructor
		 */
	public:
		Color();

		Color(float x, float y, float z, float w);

		~Color();



		/**
		 *	Methods
		 */
	public:
		static Color RGBToHSL(Color rgb);

	};

}