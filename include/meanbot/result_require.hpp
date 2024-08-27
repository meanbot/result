//                      _ _   
//  _ __ ___  ___ _   _| | |_ 
// | '__/ _ \/ __| | | | | __|  result - result & error handling
// | | |  __/\__ \ |_| | | |_   ------------------------------------------
// |_|  \___||___/\__,_|_|\__|  https://github.com/meanbot/result
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include "meanbot/result.hpp"
#include <meanbot/error.hpp>
#include <boost/preprocessor/variadic/size.hpp>


//result project does not have a custom namespace (e.g. result) !

#define MEANBOT_RESULT_REQUIRE(...)                                                                                    \
MEANBOT_RESULT_EXPAND(BOOST_PP_CAT(MEANBOT_RESULT_REQUIRE_, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__))
 

#define MEANBOT_RESULT_CALL(...)                                                                                       \
MEANBOT_RESULT_EXPAND(BOOST_PP_CAT(MEANBOT_RESULT_CALL_, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))(__VA_ARGS__))

// MEANBOT_RESULT_REQUIRE_*

#define MEANBOT_RESULT_REQUIRE_1(cond)        MEANBOT_RESULT_REQUIRE_2(cond, meanbot::error::invalid_call) 

#define MEANBOT_RESULT_REQUIRE_2(cond, err_code)                                                                          \
if (!(cond))                                                                                                           \
{                                                                                                                      \
	return meanbot::fail(err_code);                                                                                     \
} 

// MEANBOT_RESULT_CALL_*

#define MEANBOT_RESULT_CALL_1(op)                                                                                      \
if (auto res = op; !res)                                                                                               \
{                                                                                                                      \
	return meanbot::fail(res.error());                                                                                  \
}

#define MEANBOT_RESULT_CALL_2(op, result)                                                                              \
if (auto res = op; !res)                                                                                               \
{                                                                                                                      \
	return meanbot::fail(res.error());                                                                                  \
}                                                                                                                      \
else                                                                                                                   \
{                                                                                                                      \
	result = res.value();                                                                                               \
}

// generic helper

#define MEANBOT_RESULT_EXPAND(x)   x
