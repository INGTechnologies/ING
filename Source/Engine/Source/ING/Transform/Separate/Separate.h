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
 *	Include Math
 */
#include <ING/Math/Math.h>

using namespace ING::Math;



namespace ING {

	struct ING_API TransformS
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		TransformS();
		~TransformS();



		/**
		 *	Properties
		 */
	public:
		RVector3	localPosition;
		RVector3	localScale;

	};

}