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
 *	Include XMath
 */
#include <ING/XMath/XMath.h>

using namespace ING::XMath;



namespace ING {

	struct ING_API Color : public AVector4 {
	
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