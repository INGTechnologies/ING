
/**
 *	Include Header
 */
#include "Window.h"



/**
 *	Include ING Window
 */
#include <ING/Window/Window.h>



/**
 *	Include ING Window Event
 */
#include <ING/Window/Event/Event.h>



/**
 *	Include Editor Application
 */
#include <ING/Editor/Application/Application.h>



/**
 *	Include Editor Application Window System
 */
#include <ING/Editor/Application/WindowSystem/WindowSystem.h>



/**
 *	Include Application UI System
 */
#include <ING/Application/UISystem/UISystem.h>



/**
 *	Include UI Canvas
 */
#include <ING/UI/Canvas/Canvas.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



/**
 *	Include Layout
 */
#include <ING/Editor/Layout/Layout.h>



/**
 *	Include Editor Layout System
 */
#include <ING/Editor/Application/LayoutSystem/LayoutSystem.h>



/**
 *	Include Window System
 */
#include <ING/Application/WindowSystem/WindowSystem.h>



/**
 *	Include ApplicationComponent
 */
#include <ING/Application/Component/Component.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



/**
 *	Include Editor Application
 */
#include <ING/Editor/Application/Application.h>



/**
 *	Include EditorReflectionSystem
 */
#include <ING/Editor/Application/ReflectionSystem/ReflectionSystem.h>



/**
 *	Include ApplicationReflectionSystem
 */
#include <ING/Application/ReflectionSystem/ReflectionSystem.h>



namespace ING {

	namespace Editor {

		#define WINDOW_CANVAS_NAME(window) (window->name + ".Canvas")



		/**
		 *	Constructors And Destructor
		 */
		Window::Window(const WindowDesc& desc) :
			ingWindow(0),
			name(desc.name),
			canvas(0),
			layout(desc.layout)
		{
			Application* application = Application::GetInstance();



			if (layout == 0) {

				ApplicationLayoutSystem* layoutSystem = (ApplicationLayoutSystem*)application->GetComponent("EditorLayoutSystem");

				layout = layoutSystem->GetLayout("ING.Editor.DefaultLayout");

			}



			/**
			 *	Create ING Window
			 */
			ING::WindowDesc ingWdesc;
			ingWdesc.clientWidth = desc.width;
			ingWdesc.clientHeight = desc.height;
			ingWdesc.name = name;
			ingWdesc.title = L"ING.Editor";

			ingWindow = ING::IWindow::Create(ingWdesc);



			/**
			 *	Add to Window System
			 */
			ApplicationWindowSystem* windowSystem = (ApplicationWindowSystem*)(application->GetWindowSystem()->GetOverride("EditorWindowSystem"));

			windowSystem->AddWindow(this);



			/**
			 *	Create Canvas
			 */
			canvas = UI::C_Canvas::CreateInstance(ING_EDITOR_REFLECTION_CTX, name + ".Canvas");

			ApplicationUISystem* uiSystem = (ApplicationUISystem*)(application->GetComponent("UISystem"));

			uiSystem->AddCanvas(canvas);

			layout->SetupFor(canvas);



			/**
			 *	Setup events
			 */
			ingWindow->GetEvent("RESIZE")->AddListener(
				[](Event* e) {

					Window* window = (Window*)(e->GetCurrentOwner());

					window->GetCanvas()->Resize();

				}, this
			);

		}

		Window::~Window() {



		}



		/**
		 *	Release Methods
		 */
		void Window::Release() {

			Application* application = Application::GetInstance();

			if (canvas != 0 && application->IsHasComponent("UISystem")) {

				ApplicationUISystem* uiSystem = (ApplicationUISystem*)application->GetComponent("UISystem");

				if (uiSystem->IsHasCanvas(WINDOW_CANVAS_NAME(this))) {

					uiSystem->RemoveCanvas(canvas);

					canvas->Release();

				}

			}

			ApplicationWindowSystem* windowSystem = (ApplicationWindowSystem*)application->GetWindowSystem()->GetOverride("EditorWindowSystem");

			windowSystem->RemoveWindow(this);

			if (ingWindow != 0) {

				ingWindow->Release();

			}

			delete this;
		}



		/**
		 *	Properties
		 */
		void Window::SetLayout(Layout* layout) {

			this->layout = layout;

			

		}

		void Window::SetLayout(const String& layoutName) {



		}

	}

}