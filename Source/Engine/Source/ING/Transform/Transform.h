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

	struct ING_API Transform
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Transform();
		~Transform();



		/**
		 *	Release Methods
		 */
	public:
		/* We're Not Usually Use This Method */
		virtual void Release();



		/**
		 *	Properties
		 */
	public:
		Vector3		localPosition;
		Vector3		localScale;
		Quaternion	localRotation;

	};

}