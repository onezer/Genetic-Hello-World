#pragma once

#include "parameters.hpp"
#include <string>
#include "population.h"

class Genetic {
	Population population;
	Parameters parameters;
	std::string goal;

public:
	Genetic(std::string goal, Parameters parameters);

	void InitializePopulation(int num);

	int Iterate(); //returns the lowest cost in current generation

	std::string GetBestGene();
};