#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Utils
  */
#include <ING\Utils/Utils.h>

using namespace ING::Utils;



namespace ING {

	class ING_API Memory :
		public Singleton<Memory>,
		public Square
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		Memory();
		~Memory();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Allocate, Deallocate Methods
		 */
	public:
		void* Allocate(ui64 size);
		void Deallocate(void* ptr);

	};



	/**
	 *	Define Macros
	 */
#define ALLOCATE(size)	ING::Memory::GetInstance()->Allocate(size)
#define DEALLOCATE(size)	ING::Memory::GetInstance()->Deallocate(size)


}