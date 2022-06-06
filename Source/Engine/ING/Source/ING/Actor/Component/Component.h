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
#include <ING/Reflection/Reflection.h>

using namespace ING::Reflection;



namespace ING {

	class C_Actor;



	class ING_API C_ActorComponent : public Reflection::C_Object
	{

		ING_REFLECT_CLASS(C_ActorComponent, Reflection::C_Object)



		/**
		 *	Friend Classes
		 */
	public:
		friend class C_Actor;



		/**
		 *	Constructor
		 */
	protected:
		void			Constructor(const String& name);



		/**
		 *	Properties
		 */
	private:
		String			name;

		C_Actor*		actor;

	public:
		const String&	GetName () { return name; }

		void			SetName (const String& name) { this->name = name; }

		C_Actor*		GetActor() { return actor; }

		unsigned int    GetIndex();



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;

	};

}