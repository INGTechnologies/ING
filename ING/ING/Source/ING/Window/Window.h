#pragma once




namespace ING {



	class Window		
	{

		/*
		 *	Constructors And Destructor
		 */
	public:
		Window();
		~Window();



		/*
		 *	Events
		 */
	public:
		virtual bool Init();
		virtual bool Run();
		virtual bool Release();

	};


}