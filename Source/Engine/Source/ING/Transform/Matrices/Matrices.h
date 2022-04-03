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

	struct ING_API TransformM
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		TransformM	();
		~TransformM	();



		/**
		 *	Properties
		 */
	public:
		RMatrix4x4	translationMatrix;
		RMatrix4x4	scaleMatrix;
		RMatrix4x4	rotationMatrix;
		RMatrix4x4	localMatrix;
		RMatrix4x4	worldMatrix;

	};

}