// cppexperiment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <future>
#include <any>

int some_task(const uint32_t &index, const std::vector<int> &input) {
	std::cout << "input num " << index << '\n';
	return input[index];
}

int main()
{
	constexpr const uint32_t N = 100;

	std::vector<std::future<int> > results;
	results.resize(N);
	std::vector<int> inputs(N);
	std::fill(inputs.begin(), inputs.end(), 1);

	for (uint32_t i = 0; i < N; ++i) {
		results[i] = std::async(std::launch::async, some_task, i, inputs);
		//auto r2 = std::async(std::launch::async, some_task, 2);
	}

	uint32_t total = 0;

	for (uint32_t i = 0; i < N; ++i) {
		total += results[i].get();
	}

	std::cout << "total " << total << '\n';
	//std::cout << r1.get() << ' ' << r2.get() << '\n';
	return 0;
}


