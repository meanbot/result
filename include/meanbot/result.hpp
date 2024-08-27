//                      _ _   
//  _ __ ___  ___ _   _| | |_ 
// | '__/ _ \/ __| | | | | __|  result - result & error handling
// | | |  __/\__ \ |_| | | |_   ------------------------------------------
// |_|  \___||___/\__,_|_|\__|  https://github.com/meanbot/result
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#pragma once


#include <meanbot/error.hpp>
#include <tl/expected.hpp>


//result project does not have a custom namespace (e.g. result) !
namespace meanbot
{

template <typename T = void>
using result = tl::expected<T, error_type>;

template <typename T>
using expected = tl::expected<T, error_type>;

using unexpected = tl::unexpected<error_type>;

template <typename T>
expected<typename std::decay<T>::type> success(T &&t)
{
	return expected<typename std::decay<T>::type>(std::forward<T>(t));
}

inline expected<void> success()
{
	return expected<void>();
}

template <typename E>
unexpected fail(E &&e)
{
	return unexpected(std::forward<error_type>(static_cast<error_type>(e)));
}

} //namespace meanbot
