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

		template<typename T>
		class List {

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
			List() {

				size = 0;

			}
			~List() {

				Clear();

			}




			/**
			 *	Properties
			 */
		private:
			Node* headNode;
			Node* tailNode;
			unsigned int size;



			/**
			 *	Methods
			 */
		public:
			Node* AddAt(T& obj, Node* node2) {

				Node* node = new Node();

				node->pValue = malloc(sizeof(T));

				memcpy(node->pValue, &obj, sizeof(T));

				if (node2->prev != nullptr) {
					node2->prev->next = node;
				}
				else {
					headNode = node;
				}

				node2->prev = node;

				node->next = node2;

				size++;

				return node;

			}
			Node* AddAfter(T& obj, Node* node2) {

				Node* node = new Node();

				node->pValue = malloc(sizeof(T));

				memcpy(node->pValue, &obj, sizeof(T));

				if (node2->next != nullptr) {
					node2->next->prev = node;
				}
				else {
					tailNode = node;
				}

				node2->next = node;

				node->prev = node2;

				size++;

				return node;

			}

			Node* Add(T& obj) {

				Node* node = nullptr;

				if (tailNode != nullptr) {

					node = AddAfter(obj, tailNode);

				}
				else {
					node = new Node();

					node->pValue = malloc(sizeof(T));

					memcpy(node->pValue, &obj, sizeof(T));

					tailNode = node;
					headNode = node;
				}

				size++;

				return node;

			}

			Node* Add(T obj) {

				Node* node = nullptr;

				if (tailNode != nullptr) {

					node = AddAfter(obj, tailNode);

				}
				else {
					node = new Node();

					node->pValue = malloc(sizeof(T));

					memcpy(node->pValue, &obj, sizeof(T));

					tailNode = node;
					headNode = node;
				}

				size++;

				return node;

			}

			void Remove(Node* node) {

				if(node->pValue != nullptr)
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

					if(node->pValue != nullptr)
						free(node->pValue);

					delete node;

					node = nextNode;
				}

				headNode = nullptr;
				tailNode = nullptr;

				size = 0;

			}

			T& GetHead() {
				return *((T*)headNode->pValue);
			}

			T& GetTail() {
				return *((T*)tailNode->pValue);
			}

			Node* GetHeadNode() {
				return headNode;
			}

			Node* GetTailNode() {
				return tailNode;
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