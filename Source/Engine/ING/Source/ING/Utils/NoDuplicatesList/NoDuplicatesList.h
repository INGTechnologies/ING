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
			public:
				Node() :
					pValue(0),
					next(0),
					prev(0)
				{}

				~Node() {



				}



			public:
				T* pValue;
				Node* next;
				Node* prev;

			};



			/**
			 *	Constructors And Destructor
			 */
		public:
			NoDuplicatesList() :
				headNode(0),
				tailNode(0)
			{

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
			size_t size;

		public:
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

			size_t GetSize() {
				return size;
			}



			/**
			 *	Methods
			 */
		public:
			Node* AddAt(const T& obj, const T& obj2) {

				if (nodeMap.find(obj2) == nodeMap.end()) {
					return nullptr;
				}

				Node* node = new Node();

				node->pValue = new T();

				*((T*)node->pValue) = obj;

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

				return node;

			}
			Node* AddAfter(const T& obj, const T& obj2) {

				if (nodeMap.find(obj2) == nodeMap.end()) {
					return nullptr;
				}

				Node* node = new Node();

				node->pValue = new T();

				*((T*)node->pValue) = obj;

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

				return node;

			}

			Node* Add(const T& obj) {

				Node* node = nullptr;

				if (tailNode != nullptr) {

					T obj2 = *((T*)tailNode->pValue);
					node = AddAfter(obj, obj2);

				}
				else {
					node = new Node();

					node->pValue = new T();

					*((T*)node->pValue) = obj;

					tailNode = node;
					headNode = node;

					nodeMap[obj] = node;
				}

				size++;

				return node;

			}

			void Remove(const T& obj) {

				Node* node = nodeMap[obj];

				if (node->pValue != nullptr) {

					delete ((T*)(node->pValue));

				}

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

					if (node->pValue != nullptr) {

						delete ((T*)(node->pValue));

					}

					delete node;

					node = nextNode;
				}

				nodeMap.clear();

				headNode = nullptr;
				tailNode = nullptr;

				size = 0;

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



			/**
			 *	Reference Class
			 */
		public:
			class Reference {

				/**
				 *	Constructors And Destructor
				 */
			public:
				Reference() {

					listPtr = nullptr;

				}

				Reference(NoDuplicatesList<T>* listPtr) {

					this->listPtr = listPtr;

				}

				~Reference() {

					if (this->listPtr != nullptr) {

						this->listPtr->Clear();

					}

				}



				/**
				 *	List Pointer
				 */
			private:
				NoDuplicatesList<T>* listPtr;

			public:
				NoDuplicatesList<T>* GetListPtr() {
					return listPtr;
				}



				/**
				 *	Property Getters
				 */
			public:
				T& GetHead() {

					return listPtr->GetHead();
				}

				T& GetTail() {

					return listPtr->GetTail();
				}

				Node* GetHeadNode() {

					return listPtr->GetHeadNode();
				}

				Node* GetTailNode() {

					return listPtr->GetTailNode();
				}

				size_t GetSize() {

					return listPtr->GetSize();
				}



				/**
				 *	Basic Methods
				 */
			public:
				Node* AddAt(const T& obj, const T& obj2) {

					return listPtr->AddAt(obj, obj2);

				}
				Node* AddAfter(const T& obj, const T& obj2) {

					return listPtr->AddAfter(obj, obj2);

				}

				Node* Add(const T& obj) {

					return listPtr->Add(obj);

				}

				void Remove(const T& obj) {

					listPtr->Remove(obj);

				}

				void Clear() {

					listPtr->Clear();

				}

				void Foreach(void (*callback)(T& item)) {

					listPtr->Foreach(callback);

				}

				void Foreach(void (*callback)(T& item, const int& index)) {

					listPtr->Foreach(callback);

				}

				void Foreach(void (*callback)(T& item, MultiTypeArray& captureVariables), MultiTypeArray& captureVariables) {

					listPtr->Foreach(callback);

				}

				void Foreach(void (*callback)(T& item, const int& index, MultiTypeArray& captureVariables), MultiTypeArray& captureVariables) {

					listPtr->Foreach(callback);

				}



			};

		};

	}

}