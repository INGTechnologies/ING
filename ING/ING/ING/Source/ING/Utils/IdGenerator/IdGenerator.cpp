
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

	while (uint8Map.find(result) == uint8Map.end()) {
		result = GenUInt8();
	}

	uint8Map[result] = true;

	return result;

}

void IdGenerator::RemoveUInt8Id(uint8_t id) {

	if (uint8Map.find(id) == uint8Map.end()) {
		return;
	}

	uint8Map.erase(id);

}

void IdGenerator::RegisterUInt8Id(uint8_t id) {

	uint8Map[id] = true;

}



/**
 *	UInt 16 Generator
 */
uint16_t IdGenerator::GenUInt16() {

	uint16_t result = rand() % 65534 + 1;

	while (uint16Map.find(result) == uint16Map.end()) {
		result = GenUInt16();
	}

	uint32Map[result] = true;

	return result;

}

void IdGenerator::RemoveUInt16Id(uint16_t id) {

	if (uint16Map.find(id) == uint16Map.end()) {
		return;
	}

	uint16Map.erase(id);

}

void IdGenerator::RegisterUInt16Id(uint16_t id) {

	uint16Map[id] = true;

}



/**
 *	UInt 32 Generator
 */
uint32_t IdGenerator::GenUInt32() {

	uint32_t result = rand() % 4294967294 + 1;

	while (uint32Map.find(result) == uint32Map.end()) {
		result = GenUInt32();
	}

	uint32Map[result] = true;

	return result;

}

void IdGenerator::RemoveUInt32Id(uint32_t id) {

	if (uint32Map.find(id) == uint32Map.end()) {
		return;
	}

	uint32Map.erase(id);

}

void IdGenerator::RegisterUInt32Id(uint32_t id) {

	uint32Map[id] = true;

}



/**
 *	UInt 64 Generator
 */
uint64_t IdGenerator::GenUInt64() {

	uint64_t result = rand() % 18446744073709551614 + 1;

	while (uint64Map.find(result) == uint64Map.end()) {
		result = GenUInt64();
	}

	uint64Map[result] = true;

	return result;

}

void IdGenerator::RemoveUIn64Id(uint64_t id) {

	if (uint64Map.find(id) == uint64Map.end()) {
		return;
	}

	uint64Map.erase(id);

}

void IdGenerator::RegisterUInt64Id(uint64_t id) {

	uint64Map[id] = true;

}