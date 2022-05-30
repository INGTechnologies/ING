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

using namespace ING::Reflection;



namespace ING {

	class IActorComponent;



	class ING_API IActor : public Reflection::IObject
	{

		ING_REFLECT_CLASS(IActor, Reflection::IObject)



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

		std::vector<IActorComponent*> componentVector;

	public:
		const String&	GetName () { return name; }

		void			SetName (const String& name) { this->name = name; }

		const std::vector<IActorComponent*>& GetComponentVector () { return componentVector; }

		unsigned int	GetComponentIndex (const String& componentName) { return name2ComponentIndexMap[componentName]; }

		bool			IsHasComponent	(const String& componentName) { return name2ComponentIndexMap[componentName]; }

		IActorComponent*GetComponent	(unsigned int index) { return componentVector[index]; }

		IActorComponent*GetComponentByName(const String& componentName) { if (!IsHasComponent(componentName)) return 0; return GetComponent(GetComponentIndex(componentName)); }



		/**
		 *	Release Methods
		 */
	public:
		virtual void	Release() override;



		/**
		 *	Methods
		 */
	public:
		void	AddComponent	(IActorComponent* component);
		void	AddComponentByIndex	(IActorComponent* component, unsigned int index);
		void	RemoveComponentByIndex(unsigned int index);
		void	RemoveComponentByName(const String& componentName);
		void	RemoveComponent  (IActorComponent* component);

	};

}