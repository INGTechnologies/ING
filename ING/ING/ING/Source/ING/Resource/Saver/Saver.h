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



namespace ING {

	class Resource;

	class ING_API ResourceSaver {

		/**
		 *	Constructors And Destructor
		 */
	public:
		ResourceSaver();

		~ResourceSaver();



		/**
		 *	Release Method
		 */
	public:
		virtual void Release();



		/**
		 *	Save Method
		 */
	public:
		virtual void Save(Resource* resource);

	};


}