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

	class IApplication;

	class IApplicationComponent;



	class ING_API IApplicationComponentOverride
	{

		/**
		 *	Friend Class
		 */
	public:
		friend class IApplicationComponent;



		/**
		 *	Constructors And Destructor
		 */
	public:
		IApplicationComponentOverride	(IApplicationComponent* component, const String& name);
		~IApplicationComponentOverride	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init	();
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		String			name;

		IApplicationComponent* component;

	public:
		const String&	GetName			() { return name; }

		IApplication*	GetApplication	();

		IApplicationComponent* GetComponent () { return component; }

		void			SetComponent	(IApplicationComponent* component) { this->component = component; }



		/**
		 *	Methods
		 */
	public:
		virtual void	Start();

		virtual void	PreUpdate();
		virtual void	Update();
		virtual void	LateUpdate();

		virtual void	PreRender();
		virtual void	Render();
		virtual void	LateRender();

	};



	template<class TComponent>
	class ApplicationComponentOverride : public IApplicationComponentOverride
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ApplicationComponentOverride	(IApplicationComponent* component, const String& name) :
			IApplicationComponentOverride(component, name)
		{



		}

		~ApplicationComponentOverride	() {



		}



		/**
		 *	Properties
		 */
	public:
		TComponent* GetComponent() { return (TComponent*)IApplicationComponentOverride::GetComponent(); }

	};

}