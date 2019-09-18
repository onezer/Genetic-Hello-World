#pragma once

#include"parameters.hpp"
#include<string>

class Genetic {
public:
	Genetic();

	void InitializePopulation(int num);

	int Iterate(); //returns the lowest cost in current generation

	std::string GetBestGene();
};