#pragma once

/**
 *	Include Entry Point
 */
#include <ING/EntryPoint/EntryPoint.h>



#include <iostream>                                                             
#include <string>                                                               
#include <tuple>    



#include <nlohmann/json.hpp>



namespace ING {

	namespace Utils {

		using JSON = nlohmann::json;

		template<typename InputType>
		static JSON ParseJSON (const InputType& input) {

			return JSON::parse(input);

		}

	}

}