#pragma once

/*
 *	Include Entry Point
 */
#include <ING\EntryPoint\EntryPoint.h>



/*
 *	Include IOStream And Unordered Map
 */
#include <iostream>

#include <unordered_map>



namespace ING {

	namespace Utils {

		class ING_API IdGenerator
		{

			/*
			 *	Constructors And Destructor
			 */
		public:
			IdGenerator();
			~IdGenerator();



			/*
			 *	UInt 8 Generator
			 */
		private:
			std::unordered_map<uint8_t, bool> uint8Map;

		public:
			uint8_t GenUInt8();
			void RemoveUInt8Id(uint8_t id);
			void RegisterUInt8Id(uint8_t id);



			/*
			 *	UInt 16 Generator
			 */
		private:
			std::unordered_map<uint16_t, bool> uint16Map;

		public:
			uint16_t GenUInt16();
			void RemoveUInt16Id(uint16_t id);
			void RegisterUInt16Id(uint16_t id);



			/*
			 *	UInt 32 Generator
			 */
		private:
			std::unordered_map<uint32_t, bool> uint32Map;

		public:
			uint32_t GenUInt32();
			void RemoveUInt32Id(uint32_t id);
			void RegisterUInt32Id(uint32_t id);



			/*
			 *	UInt 64 Generator
			 */
		private:
			std::unordered_map<uint64_t, bool> uint64Map;

		public:
			uint64_t GenUInt64();
			void RemoveUIn64Id(uint64_t id);
			void RegisterUInt64Id(uint64_t id);

		};

	}

}