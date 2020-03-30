// cppexperiment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <future>
#include <any>

int some_task(const uint32_t &size) {
	std::cout << "input num " << size << '\n';
	return 1;
}

int main()
{
	constexpr const uint32_t N = 100;

	std::vector<std::future<int> > results;
	results.resize(N);

	for (uint32_t i = 0; i < N; ++i) {
		results[i] = std::async(std::launch::async, some_task, i + 1);
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


