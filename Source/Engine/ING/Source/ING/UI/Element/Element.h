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



namespace ING {

	namespace UI {

		class Node;



		class ING_API Element
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Element	();
			~Element();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			Node* node;

		public:
			Node* GetNode() { return node; }

		};

	}

}