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

	class IApplicationComponentOverride;

	class IApplicationComponent;



	class ING_API IApplicationComponent
	{

		/**
		 *	Friend Class
		 */
	public:
		friend class IApplicationComponentOverride;



		/**
		 *	Constructors And Destructor
		 */
	public:
		IApplicationComponent	(IApplication* application, const String& name);
		~IApplicationComponent	();



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

		IApplication*	application;

		std::unordered_map<String, unsigned int> name2OverrideIndex;

		std::vector<IApplicationComponentOverride*> overrideVector;

	public:
		const String&	GetName			() { return name; }

		IApplication*	GetApplication	() { return application; }

		unsigned int	GetOverrideIndex(const String& name) { return name2OverrideIndex[name]; }

		IApplicationComponentOverride* GetOverride(const String& name) { return overrideVector[GetOverrideIndex(name)]; }

		IApplicationComponentOverride* GetOverride(unsigned int index) { return overrideVector[index]; }



		/**
		 *	Methods
		 */
	public:
		void			AddOverride		(IApplicationComponentOverride* pass);
		void			AddOverride		(IApplicationComponentOverride* pass, unsigned int index);
		void			RemoveOverride	(unsigned int index);
		void			RemoveOverride	(const String& name);
		void			RemoveOverride	(IApplicationComponentOverride* pass);

		virtual void	Start();

		virtual void	PreUpdate();
		virtual void	Update();
		virtual void	LateUpdate();

		virtual void	PreRender();
		virtual void	Render();
		virtual void	LateRender();

	};

}