#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Application
 */
#include <ING/Application/Application.h>



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

	class ING_API IGameApplication :
		public IApplication,
		public Singleton<IGameApplication>
	{

		/**
		 *	Friend Class
		 */
	public:
		friend class Singleton<IGameApplication>;



		/**
		 *	Constructors And Destructor
		 */
	private:
		IGameApplication	();

	public:
		IGameApplication	(const WString& configPath, const String& mode);
		~IGameApplication	();



		/**
		 *	Init, Release Methods
		 */
	public:
		virtual bool Init() override;
		virtual void Release() override;



		/**
		 *	Properties
		 */
	private:
		String mode;

	public:
		String& GetMode () { return mode; }



		/**
		 *	Methods
		 */
	public:
		virtual void Start() override;

		virtual void PreUpdate() override;
		virtual void Update() override;
		virtual void LateUpdate() override;

		virtual void PreRender() override;
		virtual void Render() override;
		virtual void LateRender() override;

	};

}