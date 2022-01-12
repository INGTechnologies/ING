#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



 /**
  *	Include Unordered Map
  */
#include <unordered_map>



/**
 *	Include MultiTypeArray
 */
#include <ING\Utils\MultiTypeArray\MultiTypeArray.h>



namespace ING {

	namespace Utils {

		/**
		 *	NoDuplicatesList<T> Class
		 */
		template<typename T>
		class NoDuplicatesList {

			/**
			 *	 Nested Classes, Structs
			 */
		public:
			/**
			 *	Node Struct
			 */
			struct Node {
				void* pValue;
				Node* next;
				Node* prev;

			public:
				template<typename T>
				T& As() {
					return *((T*)pValue);
				}

			};



			/**
			 *	Constructors And Destructor
			 */
		public:
			NoDuplicatesList() {

				size = 0;

			}
			~NoDuplicatesList() {

				Clear();

			}




			/**
			 *	Properties
			 */
		private:
			std::unordered_map<T, Node*> nodeMap;
			Node* headNode;
			Node* tailNode;
			unsigned int size;



			/**
			 *	Methods
			 */
		public:
			void AddAt(T& obj, T& obj2) {

				if (nodeMap.find(obj2) == nodeMap.end()) {
					return;
				}

				Node* node = new Node();

				node->pValue = malloc(sizeof(T));

				memcpy(node->pValue, &obj, sizeof(T));

				if (nodeMap[obj2]->prev != nullptr) {
					nodeMap[obj2]->prev->next = node;
				}
				else {
					headNode = node;
				}

				nodeMap[obj2]->prev = node;

				node->next = nodeMap[obj2];

				nodeMap[obj] = node;

				size++;

			}
			void AddAfter(T& obj, T& obj2) {

				if (nodeMap.find(obj2) == nodeMap.end()) {
					return;
				}

				Node* node = new Node();

				node->pValue = malloc(sizeof(T));

				memcpy(node->pValue, &obj, sizeof(T));

				if (nodeMap[obj2]->next != nullptr) {
					nodeMap[obj2]->next->prev = node;
				}
				else {
					tailNode = node;
				}

				nodeMap[obj2]->next = node;

				node->prev = nodeMap[obj2];

				nodeMap[obj] = node;

				size++;

			}

			void Add(T& obj) {

				if (tailNode != nullptr) {

					T obj2 = *((T*)tailNode->pValue);
					AddAfter(obj, obj2);

				}
				else {
					Node* node = new Node();

					node->pValue = malloc(sizeof(T));

					memcpy(node->pValue, &obj, sizeof(T));

					tailNode = node;
					headNode = node;

					nodeMap[obj] = node;
				}

				size++;

			}

			void Add(T obj) {

				if (tailNode != nullptr) {

					T obj2 = *((T*)tailNode->pValue);
					AddAfter(obj, obj2);

				}
				else {
					Node* node = new Node();

					node->pValue = malloc(sizeof(T));

					memcpy(node->pValue, &obj, sizeof(T));

					tailNode = node;
					headNode = node;

					nodeMap[obj] = node;

					size++;
				}

			}

			void Remove(T& obj) {

				Node* node = nodeMap[obj];

				free(node->pValue);

				if (node->next == nullptr) {
					tailNode = node->prev;
				}
				else {
					node->next->prev = node->prev;
				}

				if (node->prev == nullptr) {
					headNode = node->next;
				}
				else {
					node->prev->next = node->next;
				}

				delete node;

				size--;

			}

			void Remove(T obj) {

				Node* node = nodeMap[obj];

				free(node->pValue);

				if (node->next == nullptr) {
					tailNode = node->prev;
				}
				else {
					node->next->prev = node->prev;
				}

				if (node->prev == nullptr) {
					headNode = node->next;
				}
				else {
					node->prev->next = node->next;
				}

				delete node;

				size--;

			}

			void Clear() {

				Node* node = headNode;

				while (node != nullptr) {
					Node* nextNode = node->next;

					free(node->pValue);

					delete node;

					node = nextNode;
				}

				nodeMap.clear();

				headNode = nullptr;
				tailNode = nullptr;

				size = 0;

			}

			T GetHead() {
				return *((T*)headNode->pValue);
			}

			unsigned int GetSize() {
				return size;
			}

			void Foreach(void (*callback)(T& item)) {

				Node* node = headNode;

				while (node != nullptr) {
					Node* nextNode = node->next;

					callback(*((T*)(node->pValue)));

					node = nextNode;
				}

			}

			void Foreach(void (*callback)(T& item, const int& index)) {

				Node* node = headNode;

				int index = 0;

				while (node != nullptr) {
					Node* nextNode = node->next;

					callback(*((T*)(node->pValue)), index);

					node = nextNode;

					++index;

				}

			}

			void Foreach(void (*callback)(T& item, MultiTypeArray& captureVariables), MultiTypeArray& captureVariables) {

				Node* node = headNode;

				while (node != nullptr) {
					Node* nextNode = node->next;

					callback(*((T*)(node->pValue)), captureVariables);

					node = nextNode;
				}

			}

			void Foreach(void (*callback)(T& item, const int& index, MultiTypeArray& captureVariables), MultiTypeArray& captureVariables) {

				Node* node = headNode;

				int index = 0;

				while (node != nullptr) {
					Node* nextNode = node->next;

					callback(*((T*)(node->pValue)), index, captureVariables);

					node = nextNode;
				
					++index;
				
				}

			}

		};

	}

}