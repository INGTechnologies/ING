#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Mutex, Map
 */
#include <mutex>
#include <map>



/**
 *	Include ObjectId
 */
#include <ING/Object/Id.h>



namespace ING {

	class Object;



	class ING_API ObjectManager :
		public Singleton<ObjectManager>,
		public Square
	{

	public:
		friend class Object;



		/**
		 *	Constructors And Destructor
		 */
	public:
		ObjectManager();
		~ObjectManager();



		/**
		 *	Init, Run, Release Methods
		 */
	public:
		virtual bool Init()		override;
		virtual bool Run()		override;
		virtual bool Release()	override;



		/**
		 *	Properties
		 */
	private:
		IdGenerator idGenerator;

		std::unordered_map<ObjectId, Object*> id2ObjectMap;

		std::mutex mutex;



		/**
		 *	Methods
		 */
	public:
		void	RegisterObject	(Object* object);
		void	RemoveObject	(Object* object);
		Object* GetObjectById	(ObjectId id);

	};


}