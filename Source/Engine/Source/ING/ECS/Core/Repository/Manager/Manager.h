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



namespace ING {

	namespace ECS {

		class Repository;



		class ING_API RepositoryManager :
			public Singleton<RepositoryManager>,
			public Square
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			RepositoryManager();
			~RepositoryManager();



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
			List<Repository*>	repositoryList;

		public:
			List<Repository*>&	GetRepositoryList() { return repositoryList; }



			/**
			 *	Methods
			 */
		public:
			List<Repository*>::Node*	AddRepository		(Repository* repository);
			void						RemoveRepository	(List<Repository*>::Node* node);



			/**
			 *	Event Methods
			 */
		public:
			void PreUpdate();
			void Update();
			void LateUpdate();

		};

	}

}