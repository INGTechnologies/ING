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



/**
 *	Include Actor Id
 */
#include <ING/Actor/Id.h>



/**
 *	Include Object
 */
#include <ING/Object/Object.h>



/**
 *	Include Reflection
 */
#include <ING/Reflection/Type/Type.h>
#include <ING/Reflection/Namespace/Namespace.h>
#include <ING/Reflection/Object/Object.h>
#include <ING/Reflection/Object/Function/Function.h>
#include <ING/Reflection/Context/Context.h>
#include <ING/Reflection/Class/Class.h>



namespace ING {

	class ING_API IActor : public Reflection::IObject
	{

		ING_REFLECT_CLASS(IActor, Reflection::IObject)



		/**
		 *	Constructor
		 */
	protected:
		void Constructor();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release() override;

	};

}