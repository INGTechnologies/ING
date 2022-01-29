
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

	if (uint8Map.find(result) == uint8Map.end()) {

		uint8Map[result] = true;

		return result;

	}
	else {

		return GenUInt8();

	}

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

	if (uint16Map.find(result) == uint16Map.end()) {

		uint16Map[result] = true;

		return result;

	}
	else {

		return GenUInt16();

	}

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

	if (uint32Map.find(result) == uint32Map.end()) {

		uint32Map[result] = true;

		return result;

	}
	else {

		return GenUInt32();

	}

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

	if (uint64Map.find(result) == uint64Map.end()) {

		uint64Map[result] = true;

		return result;

	}
	else {

		return GenUInt64();

	}

}

void IdGenerator::RemoveUInt64Id(uint64_t id) {

	if (uint64Map.find(id) == uint64Map.end()) {
		return;
	}

	uint64Map.erase(id);

}

void IdGenerator::RegisterUInt64Id(uint64_t id) {

	uint64Map[id] = true;

}

void IdGenerator::ClearUInt8Ids() {

	for (auto it = uint8Map.cbegin(); it != uint8Map.cend();)
	{
		uint8Map.erase(it++);
	}

}

void IdGenerator::ClearUInt16Ids() {

	for (auto it = uint16Map.cbegin(); it != uint16Map.cend();)
	{
		uint16Map.erase(it++);
	}

}

void IdGenerator::ClearUInt32Ids() {

	for (auto it = uint32Map.cbegin(); it != uint32Map.cend();)
	{
		uint32Map.erase(it++);
	}

}

void IdGenerator::ClearUInt64Ids() {

	for (auto it = uint64Map.cbegin(); it != uint64Map.cend();)
	{
		uint64Map.erase(it++);
	}

}

void IdGenerator::ClearIds() {

	ClearUInt8Ids();
	ClearUInt16Ids();
	ClearUInt32Ids();
	ClearUInt64Ids();

}
