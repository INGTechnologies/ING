
/**
 *	Include Header
 */
#include "Manager.h"



/**
 *	Include ECS
 */
#include <ING/ECS/ECS.h>



namespace ING {

	namespace ECS {

		/**
		 *	Constructors And Destructor
		 */
		RepositoryManager::RepositoryManager() {



		}

		RepositoryManager::~RepositoryManager() {



		}



		/**
		 *	Init, Run, Release Methods
		 */
		bool RepositoryManager::Init() {



			return true;
		}

		bool RepositoryManager::Run() {



			return true;
		}

		bool RepositoryManager::Release() {

			repositoryList.Clear();

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