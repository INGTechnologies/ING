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

	class SceneManager;

	class IResource;



	class ING_API ISceneComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		ISceneComponent(const std::string& typeId);
		~ISceneComponent();



		/**
		 *	Release Methods
		 */
	public:
		virtual void Release();



		/**
		 *	Properties
		 */
	private:
		std::string typeId;

	public:
		const std::string& GetTypeId() { return typeId; }

	};



	template<class T>
	class SceneComponent : public ISceneComponent
	{

		/**
		 *	Constructors And Destructor
		 */
	public:
		SceneComponent();
		~SceneComponent();


	};

}



namespace ING {

	/**
	 *	Constructors And Destructor
	 */
	template<class T>
	SceneComponent<T>::SceneComponent() :
		ISceneComponent(typeid(T).name())
	{



	}

	template<class T>
	SceneComponent<T>::~SceneComponent() {



	}

}