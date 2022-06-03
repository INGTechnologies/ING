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

	class C_ActorComponent;



	class ING_API C_Actor : public Reflection::C_Object
	{

		ING_REFLECT_CLASS(C_Actor, Reflection::C_Object)



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

		std::unordered_map<String, unsigned int> name2ComponentIndexMap;

		std::vector<C_ActorComponent*> componentVector;

	public:
		const String&	GetName () { return name; }

		void			SetName (const String& name) { this->name = name; }

		const std::vector<C_ActorComponent*>& GetComponentVector () { return componentVector; }

		unsigned int	GetComponentIndex (const String& componentName) { return name2ComponentIndexMap[componentName]; }

		bool			IsHasComponent	(const String& componentName) { return name2ComponentIndexMap[componentName]; }

		C_ActorComponent*GetComponent	(unsigned int index) { return componentVector[index]; }

		C_ActorComponent*GetComponentByName(const String& componentName) { if (!IsHasComponent(componentName)) return 0; return GetComponent(GetComponentIndex(componentName)); }



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;



		/**
		 *	Methods
		 */
	public:
		void	AddComponent	(C_ActorComponent* component);
		void	AddComponentByIndex	(C_ActorComponent* component, unsigned int index);
		void	RemoveComponentByIndex(unsigned int index);
		void	RemoveComponentByName(const String& componentName);
		void	RemoveComponent  (C_ActorComponent* component);

	};

}