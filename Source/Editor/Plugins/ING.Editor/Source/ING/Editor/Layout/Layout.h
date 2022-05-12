#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING\Editor\EntryPoint\EntryPoint.h>



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
 *	Include Math
 */
#include <ING/Math/Math.h>



/**
 *	Include UI Element
 */
#include <ING/UI/Element/Element.h>



/**
 *	Include LayoutNode
 */
#include <ING/Editor/Layout/Node/Node.h>



namespace ING {

	namespace UI {

		class Canvas;

	}

	namespace Editor {

		class LayoutNode;



		class PLUGIN_API(ING_EDITOR) Layout
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			Layout(const String& name, const LayoutNode& rootNode);
			~Layout();



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release();



			/**
			 *	Properties
			 */
		private:
			String			name;

			LayoutNode		rootNode;

		public:
			const String&	GetName() { return name; }

			LayoutNode&		GetRootNode() { return rootNode; }



			/**
			 *	Methods
			 */
		public:
			virtual void	SetupFor(ING::UI::Canvas * canvas);

		};

	}

}