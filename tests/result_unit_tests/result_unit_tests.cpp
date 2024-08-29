//                      _ _   
//  _ __ ___  ___ _   _| | |_ 
// | '__/ _ \/ __| | | | | __|  result - result & error handling
// | | |  __/\__ \ |_| | | |_   ------------------------------------------
// |_|  \___||___/\__,_|_|\__|  https://github.com/meanbot/result
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#include <fmt/core.h>
#include <catch2/catch_all.hpp>


CATCH_TEST_CASE("test", "")
{
	CATCH_REQUIRE(1 == 1);
}

int main(int argc, char *argv[])
{
	int   result = Catch::Session().run(argc, argv);

	return result;
}
