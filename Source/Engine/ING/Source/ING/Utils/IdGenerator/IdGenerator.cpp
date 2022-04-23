
/**
 *	Include Header
 */
#include "IdGenerator.h"



/**
 *	Include Utils
 */
#include <ING/Utils/Utils.h>

using namespace ING::Utils;



/**
 *	Include Random
 */
#include <random>



/**
 *	Constructors And Destructor
 */
IdGenerator::IdGenerator() {

}
IdGenerator::~IdGenerator() {

}



/**
 *	UInt 8 Generator
 */
uint8_t IdGenerator::GenUInt8() {

	uint8_t result = rand() % 254 + 1;

	bool isRepeat = false;

	for (std::unordered_map<uint8_t, bool>*& uint8Map : uint8MapVector) {

		if (uint8Map->find(result) != uint8Map->end()) {

			isRepeat = true;
			break;

		}

	}

	if (isRepeat) {

		return GenUInt8();

	}
	else {

		for (std::unordered_map<uint8_t, bool>*& uint8Map : uint8MapVector) {

			if (uint8Map->size() < uint8Map->max_size()) {

				(*uint8Map)[result] = true;

				return result;

			}

		}

		uint8MapVector.push_back(new std::unordered_map<uint8_t, bool>());

		(*(uint8MapVector[uint8MapVector.size() - 1]))[result] = true;

	}

}

void IdGenerator::RemoveUInt8Id(uint8_t id) {

	for (std::unordered_map<uint8_t, bool>*& uint8Map : uint8MapVector) {

		if (uint8Map->find(id) != uint8Map->end()) {

			uint8Map->erase(id);

			break;

		}

	}

}

void IdGenerator::RegisterUInt8Id(uint8_t id) {

	for (std::unordered_map<uint8_t, bool>*& uint8Map : uint8MapVector) {

		if (uint8Map->size() < uint8Map->max_size()) {

			(*uint8Map)[id] = true;

		}

	}

}



/**
 *	UInt 16 Generator
 */
uint16_t IdGenerator::GenUInt16() {

	uint16_t result = rand() % 65534 + 1;

	bool isRepeat = false;

	for (std::unordered_map<uint16_t, bool>*& uint16Map : uint16MapVector) {

		if (uint16Map->find(result) != uint16Map->end()) {

			isRepeat = true;
			break;

		}

	}

	if (isRepeat) {

		return GenUInt16();

	}
	else {

		for (std::unordered_map<uint16_t, bool>*& uint16Map : uint16MapVector) {

			if (uint16Map->size() < uint16Map->max_size()) {

				(*uint16Map)[result] = true;

				return result;

			}

		}

		uint16MapVector.push_back(new std::unordered_map<uint16_t, bool>());

		(*(uint16MapVector[uint16MapVector.size() - 1]))[result] = true;

	}

}

void IdGenerator::RemoveUInt16Id(uint16_t id) {

	for (std::unordered_map<uint16_t, bool>*& uint16Map : uint16MapVector) {

		if (uint16Map->find(id) != uint16Map->end()) {

			uint16Map->erase(id);

			break;

		}

	}

}

void IdGenerator::RegisterUInt16Id(uint16_t id) {

	for (std::unordered_map<uint16_t, bool>*& uint16Map : uint16MapVector) {

		if (uint16Map->size() < uint16Map->max_size()) {

			(*uint16Map)[id] = true;

		}

	}

}



/**
 *	UInt 32 Generator
 */
uint32_t IdGenerator::GenUInt32() {

	std::random_device rd;

	/* Random number generator */
	std::default_random_engine generator(rd());

	/* Distribution on which to apply the generator */
	std::uniform_int_distribution<unsigned int> distribution(0, 0xFFFFFFFF - 1);

	uint32_t result = distribution(generator) + 1;

	bool isRepeat = false;

	for (std::unordered_map<uint32_t, bool>*& uint32Map : uint32MapVector) {

		if (uint32Map->find(result) != uint32Map->end()) {

			isRepeat = true;
			break;

		}

	}

	if (isRepeat) {

		return GenUInt32();

	}
	else {

		for (std::unordered_map<uint32_t, bool>*& uint32Map : uint32MapVector) {

			if (uint32Map->size() < uint32Map->max_size()) {

				(*uint32Map)[result] = true;

				return result;

			}

		}

		uint32MapVector.push_back(new std::unordered_map<uint32_t, bool>());

		(*(uint32MapVector[uint32MapVector.size() - 1]))[result] = true;

	}

}

void IdGenerator::RemoveUInt32Id(uint32_t id) {

	for (std::unordered_map<uint32_t, bool>*& uint32Map : uint32MapVector) {

		if (uint32Map->find(id) != uint32Map->end()) {

			uint32Map->erase(id);

			break;

		}

	}

}

void IdGenerator::RegisterUInt32Id(uint32_t id) {

	for (std::unordered_map<uint32_t, bool>*& uint32Map : uint32MapVector) {

		if (uint32Map->size() < uint32Map->max_size()) {

			(*uint32Map)[id] = true;

		}

	}

}



/**
 *	UInt 64 Generator
 */
uint64_t IdGenerator::GenUInt64() {

	std::random_device rd;

	/* Random number generator */
	std::default_random_engine generator(rd());

	/* Distribution on which to apply the generator */
	std::uniform_int_distribution<unsigned long> distribution(0, 0xFFFFFFFFFFFFFFFF - 1);

	uint64_t result = distribution(generator) + 1;//rand() % 18446744073709551614 + 1;

	bool isRepeat = false;

	for (std::unordered_map<uint64_t, bool>*& uint64Map : uint64MapVector) {

		if (uint64Map->find(result) != uint64Map->end()) {

			isRepeat = true;
			break;

		}

	}

	if (isRepeat) {

		return GenUInt64();

	}
	else {

		for (std::unordered_map<uint64_t, bool>*& uint64Map : uint64MapVector) {

			if (uint64Map->size() < uint64Map->max_size()) {

				(*uint64Map)[result] = true;

				return result;

			}

		}

		uint64MapVector.push_back(new std::unordered_map<uint64_t, bool>());

		(*(uint64MapVector[uint64MapVector.size() - 1]))[result] = true;

		return result;

	}

}

void IdGenerator::RemoveUInt64Id(uint64_t id) {

	for (std::unordered_map<uint64_t, bool>*& uint64Map : uint64MapVector) {

		if (uint64Map->find(id) != uint64Map->end()) {

			uint64Map->erase(id);

			break;

		}

	}

}

void IdGenerator::RegisterUInt64Id(uint64_t id) {

	for (std::unordered_map<uint64_t, bool>*& uint64Map : uint64MapVector) {

		if (uint64Map->size() < uint64Map->max_size()) {

			(*uint64Map)[id] = true;

		}

	}

}



void IdGenerator::ClearUInt8Ids() {

	for (std::unordered_map<uint8_t, bool>*& uint8Map : uint8MapVector) {

		for (auto it = uint8Map->cbegin(); it != uint8Map->cend();)
		{
			uint8Map->erase(it++);
		}

		delete uint8Map;

	}

}

void IdGenerator::ClearUInt16Ids() {

	for (std::unordered_map<uint16_t, bool>*& uint16Map : uint16MapVector) {

		for (auto it = uint16Map->cbegin(); it != uint16Map->cend();)
		{
			uint16Map->erase(it++);
		}

		delete uint16Map;

	}

}

void IdGenerator::ClearUInt32Ids() {

	for (std::unordered_map<uint32_t, bool>*& uint32Map : uint32MapVector) {

		for (auto it = uint32Map->cbegin(); it != uint32Map->cend();)
		{
			uint32Map->erase(it++);
		}

		delete uint32Map;

	}

}

void IdGenerator::ClearUInt64Ids() {

	for (std::unordered_map<uint64_t, bool>*& uint64Map : uint64MapVector) {

		for (auto it = uint64Map->cbegin(); it != uint64Map->cend();)
		{
			uint64Map->erase(it++);
		}

		delete uint64Map;

	}

}

void IdGenerator::ClearIds() {

	ClearUInt8Ids();
	ClearUInt16Ids();
	ClearUInt32Ids();
	ClearUInt64Ids();

}
