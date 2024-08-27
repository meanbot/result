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
#include <fmt/format.h>


//result project does not have a custom namespace (e.g. result) !

template <class T>
struct fmt::formatter<meanbot::result<T>>
{
	static constexpr auto parse(const format_parse_context &ctx)
	{
		return ctx.begin();
	}

	template <typename format_context>
	constexpr auto format(const meanbot::result<T> &result, format_context &ctx) const
	{
		if (result)
		{
			return format_to(ctx.out(), "{}", result.value());
		}
		else
		{
			return format_to(ctx.out(), "error(code = {})", result.error());
		}
	}
};

template <>
struct fmt::formatter<meanbot::result<void>>
{
	static constexpr auto parse(const format_parse_context &ctx)
	{
		return ctx.begin();
	}

	template <typename format_context>
	constexpr auto format(const meanbot::result<void> &result, format_context &ctx) const
	{
		if (result)
		{
			return format_to(ctx.out(), "<void>");
		}
		else
		{
			return format_to(ctx.out(), "error({})", result.error());
		}
	}
};

