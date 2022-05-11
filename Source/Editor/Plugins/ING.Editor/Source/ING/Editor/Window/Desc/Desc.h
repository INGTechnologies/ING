#pragma once

/**
 *	Include Editor Entry Point
 */
#include <ING/Editor/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include IOStream
 */
#include <iostream>



namespace ING {

	class IWindow;

	namespace UI {

		class Canvas;

	}



	namespace Editor {

		class Layout;



		struct WindowDesc {

			String			name   = "DefaultWindow";

			unsigned int	width  = 800;
			unsigned int	height = 600;

			Layout*			layout = 0;

		};

	}

}