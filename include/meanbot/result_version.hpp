//                      _ _   
//  _ __ ___  ___ _   _| | |_ 
// | '__/ _ \/ __| | | | | __|  result - result & error handling
// | | |  __/\__ \ |_| | | |_   ------------------------------------------
// |_|  \___||___/\__,_|_|\__|  https://github.com/meanbot/result
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include <cstdint>
#include <string>


//result project does not have a custom namespace (e.g. result) !
namespace meanbot
{

// https://semver.org
struct result_version final
{
	static constexpr std::string_view   NAME          = "meanbot.result";
	static constexpr std::string_view   DESCRIPTION   = "result & error handling";
	static constexpr std::string_view   URL           = "https://github.com/meanbot/result";

	static constexpr uint32_t           MAJOR         = 0; // when you make incompatible API changes
	static constexpr uint32_t           MINOR         = 0; // when you add functionality in a backward compatible manner
	static constexpr uint32_t           PATCH         = 1; // when you make backward compatible bug fixes
	static constexpr std::string_view   PRERELEASE    = "";
	static constexpr std::string_view   BUILDMETADATA = "";

	// <MAJOR>.<MINOR>.<PATCH>[-<PRERELEASE>][+BUILDMETADATA]
	static constexpr std::string_view   STRING        = "0.0.1";
};//struct result_version

}//namespace meanbot
