//                      _ _   
//  _ __ ___  ___ _   _| | |_ 
// | '__/ _ \/ __| | | | | __|  result - result & error handling
// | | |  __/\__ \ |_| | | |_   ------------------------------------------
// |_|  \___||___/\__,_|_|\__|  https://github.com/meanbot/result
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#include <cstdint>
#include <fmt/core.h>


extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv)
{
	(void) argc;
	(void) argv;

	return 0;
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t data_size)
{
	(void) data;
	(void) data_size;

	return 0;
}
