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
		Matrix4x4	translationMatrix;
		Matrix4x4	scaleMatrix;
		Matrix4x4	rotationMatrix;

	};

}