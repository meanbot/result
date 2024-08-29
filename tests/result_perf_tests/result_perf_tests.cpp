//                      _ _   
//  _ __ ___  ___ _   _| | |_ 
// | '__/ _ \/ __| | | | | __|  result - result & error handling
// | | |  __/\__ \ |_| | | |_   ------------------------------------------
// |_|  \___||___/\__,_|_|\__|  https://github.com/meanbot/result
// 
// SPDX-FileCopyrightText: 2024 meanbot <https://github.com/meanbot>
// SPDX-License-Identifier: MIT

#include <benchmark/benchmark.h>
#include <fmt/core.h>


void benchmark_test(benchmark::State &state)
{
	for (auto _ : state)
	{
		int x = 0;

		x++;
		benchmark::DoNotOptimize(x);
	}
}

BENCHMARK(benchmark_test);

int main(int argc, char *argv[])
{
	int   result = 0;

	benchmark::Initialize(&argc, argv);
	if (benchmark::ReportUnrecognizedArguments(argc, argv))
	{
		result = 1;
	}
	else
	{
		benchmark::RunSpecifiedBenchmarks();
		benchmark::Shutdown();
	}

	return result;
}
