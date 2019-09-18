#pragma once

#include <string>
#include <memory>
#include <vector>

#include "parameters.hpp"
#include "entity.h"

class Population {

	std::vector<std::pair<int, Entity>> genePool;

	std::string goal;

public:
	Population(int num, std::string goal);

	void CreateEntities(int num);
	
	int Iterate(Parameters parameters); //returns lowest cost
	std::string BestGene();

private:
	void AddEntity(std::string);
	void SortGenePool();
};