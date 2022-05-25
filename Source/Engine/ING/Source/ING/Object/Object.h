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
 *	Include Id
 */
#include <ING/Object/Id.h>



namespace ING {

	class ObjectManager;



	class ING_API IObject {
		
	public:
		friend class ObjectManager;



		/**
		 *	Constructor And Destructors
		 */
	public:
		IObject	();

		IObject	(ObjectId id);

		~IObject();



		/**
		 *	Properties
		 */
	private:
		ObjectId id;

	public:
		ObjectId GetId() { return id; }



		/**
		 *	Methods
		 */
	public:
		virtual void Release();

	};

}