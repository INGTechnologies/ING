#pragma once

/**
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/**
 *	Include IOStream And Unordered Map
 */
#include <iostream>

#include <unordered_map>



namespace ING {

	namespace Utils {

		class ING_API IdGenerator
		{

			/**
			 *	Constructors And Destructor
			 */
		public:
			IdGenerator();
			~IdGenerator();



			/**
			 *	UInt 8 Generator
			 */
		private:
			std::vector < std::unordered_map<uint8_t, bool>*> uint8MapVector;

		public:
			uint8_t GenUInt8();
			void RemoveUInt8Id(uint8_t id);
			void RegisterUInt8Id(uint8_t id);



			/**
			 *	UInt 16 Generator
			 */
		private:
			std::vector < std::unordered_map<uint16_t, bool>*> uint16MapVector;

		public:
			uint16_t GenUInt16();
			void RemoveUInt16Id(uint16_t id);
			void RegisterUInt16Id(uint16_t id);



			/**
			 *	UInt 32 Generator
			 */
		private:
			std::vector < std::unordered_map<uint32_t, bool>*> uint32MapVector;

		public:
			uint32_t GenUInt32();
			void RemoveUInt32Id(uint32_t id);
			void RegisterUInt32Id(uint32_t id);



			/**
			 *	UInt 64 Generator
			 */
		private:
			std::vector < std::unordered_map<uint64_t, bool>*> uint64MapVector;

		public:
			uint64_t GenUInt64();
			void RemoveUInt64Id(uint64_t id);
			void RegisterUInt64Id(uint64_t id);



			/**
			 *	Clear Methods
			 */
		public:
			void ClearUInt8Ids();
			void ClearUInt16Ids();
			void ClearUInt32Ids();
			void ClearUInt64Ids();
			void ClearIds();

		};

	}

}