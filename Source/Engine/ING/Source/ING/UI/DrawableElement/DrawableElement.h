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
 *	Include Map
 */
#include <map>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



namespace ING {

	namespace UI {

		class Node;



		class ING_API DrawableElement : public IElement
		{

			ING_REFLECT_CLASS(DrawableElement, IElement)



			/**
			 *	Constructor
			 */
		public:
			void Constructor (const String& name);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;

		};

	}

}