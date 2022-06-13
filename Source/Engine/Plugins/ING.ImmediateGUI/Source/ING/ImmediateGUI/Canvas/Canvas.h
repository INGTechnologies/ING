#pragma once

/**
 *	Include Plugin
 */
#include <ING/ImmediateGUI/Plugin/Plugin.h>



/**
 *	Include UI Canvas
 */
#include <ING/UI/Canvas/Canvas.h>



namespace ING {

	namespace ImmediateGUI {

		class PLUGIN_API(ING_IMMEDIATEGUI) C_Canvas : public UI::C_Canvas {

			ING_REFLECT_CLASS(C_Canvas, UI::C_Canvas)



			/**
			 *	Constructor
			 */
		protected:
			void Constructor (const String & name);



			/**
			 *	Release Methods
			 */
		public:
			virtual void Release() override;

		};

	}

}