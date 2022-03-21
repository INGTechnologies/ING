
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include ECS
 */
#include <ING/ECS/ECS.h>



/**
 *	Include Debug
 */
#include <ING/_Debug/Debug.h>



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		RepositoryManager::RepositoryManager() {

			Debug::Log("Start Creating RepositoryManager");

			Debug::Log("RepositoryManager Created");

		}

		RepositoryManager::~RepositoryManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool RepositoryManager::Init() {

			Debug::Log("Start Initializing RepositoryManager");

			Debug::Log("RepositoryManager Initialized");

			return true;
		}

		bool RepositoryManager::Run() {

			Debug::Log("Start Running RepositoryManager");

			return true;
		}

		bool RepositoryManager::Release() {

			Debug::Log("Start Releasing RepositoryManager");

			repositoryList.Clear();

			Debug::Log("Finished Releasing RepositoryManager");

			return Square::Release();
		}



		/**
		 *	Methods
		 */
		List<Repository*>::Node*	RepositoryManager::AddRepository		(Repository* repository) {

			return repositoryList.Add(repository);

		}

		void						RepositoryManager::RemoveRepository	(List<Repository*>::Node* node) {

			repositoryList.Remove(node);

		}



		/**
		 *	Event Methods
		 */
		void						RepositoryManager::Update() {

			repositoryList.Foreach([](Repository*& repository){

				if (!repository->IsActive()) return;

				repository->Update();

			});

		}

	}

}