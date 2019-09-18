#pragma once

#include <string>
#include <memory>
#include <vector>

#include "parameters.hpp"
#include "entity.h"

class Population {

	std::vector<std::pair<int, std::string>> genePool;

public:
	Population(int num, std::string goal);

	
	int Iterate(Parameters parameters); //returns lowest cost
	std::string BestGene();

private:

	void SortGenePool();

};