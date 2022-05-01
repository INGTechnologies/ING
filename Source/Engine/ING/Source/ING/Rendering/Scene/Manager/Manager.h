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

	namespace Rendering {

		class Scene;



		class ING_API SceneManager :
			public Singleton<SceneManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			SceneManager();
			~SceneManager();



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
			std::unordered_map<String, Scene*>		sceneMap;

		public:
			std::unordered_map<String, Scene*>&	GetSceneMap () { return sceneMap; }



			/**
			 *	Methods
			 */
		public:
			void	AddScene	(Scene* scene);
			void	RemoveScene	(Scene* scene);

		};

	}

}