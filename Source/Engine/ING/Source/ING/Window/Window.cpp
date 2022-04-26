
/**
 *	Include Header
 */
#include "Window.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Screen
 */
#include <ING/Screen/Screen.h>



/**
 *	Include Event
 */
#include <ING/Event/Event.h>



/**
 *	Include Events
 */
/* Destroy */
#include <ING/Window/Event/Destroy/Destroy.h>

/* Key Events */
#include <ING/Window/Event/Key/Down/Down.h>
#include <ING/Window/Event/Key/Up/Up.h>

/* Mouse Events */
#include <ING/Window/Event/Mouse/Button/Down/Down.h>
#include <ING/Window/Event/Mouse/Button/Up/Up.h>
#include <ING/Window/Event/Mouse/Move/Move.h>

/* Resize Events */
#include <ING/Window/Event/Resize/Resize.h>



/* MSVC Window */
#include <ING/Window/MSVC/Window/Window.h>



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	IWindow::IWindow() :
		handle(NULL), screen(0)
	{

		InitEvents();

	}

	IWindow::IWindow(const WindowDesc& desc) :
		handle(NULL), screen(0)
	{

		InitEvents();

	}

	IWindow::~IWindow()
	{



	}



	/**
	 *	InitWithDesc, InitEvents, Release Methods
	 */
	void IWindow::InitWithDesc(const WindowDesc& desc) {

		CreateScreen();

		this->desc = desc;

	}

	void IWindow::InitEvents() {

		/**
		 *	Destroy Event
		 */
		AddEvent( new WindowDestroyEvent());



		/**
		 *	Key Events
		 */
		AddEvent( new WindowKeyDownEvent());

		AddEvent( new WindowKeyUpEvent());



		/**
		 *	Mouse Events
		 */
		AddEvent( new WindowMouseBtnDownEvent());

		AddEvent( new WindowMouseBtnUpEvent());

		AddEvent( new WindowMouseMoveEvent());



		/**
		 *	Mouse Events
		 */
		AddEvent( new WindowResizeEvent() );

	}

	IWindow* IWindow::Create() {

#ifdef USE_MSVC
		return new ING::MSVC::Window();
#endif

		return 0;

	}

	IWindow* IWindow::Create(const WindowDesc& desc) {

#ifdef USE_MSVC
		return new ING::MSVC::Window(desc);
#endif

		return 0;

	}

	void IWindow::Release() 
	{
		if(screen != nullptr)
			screen->Release();

		WindowManager::GetInstance()->RemoveClassId(classId);

		WindowManager::GetInstance()->RemoveWindow(this);

		RELEASE_EVENT_STORAGE();

		delete this;

	}



	/**
	 *	Methods
	 */
	void			IWindow::Show() {
		


	}

	void			IWindow::Hide() {



	}

	void			IWindow::Focus() {



	}

	void			IWindow::SetTitle(const std::wstring& title) {



	}

	std::wstring	IWindow::GetTitle() {

		return desc.title;

	}

	void			IWindow::CreateScreen() {

		ScreenDesc screenDesc;

		screenDesc.clientWidth = desc.clientWidth;
		screenDesc.clientHeight = desc.clientHeight;

		screen = new Screen(this, screenDesc);

	}



	/**
	 *	Event Management
	 */
	List<Event*>::Node*		IWindow::AddEvent(Event* event) {

		((WindowEvent*)event)->window = this;

		return EventStorage::AddEvent(event);

	}

}