#include "population.h"

#include <algorithm>
#include <iostream>

Population::Population() : parameters{ Parameters(0, 0, 0) }
{
}

Population::Population(int num, std::string goal, Parameters parameters) : goal{goal}, parameters{parameters}
{
	CreateEntities(num);
	SortGenePool();
}

void Population::CreateEntities(int num)
{
	for (int i = 0; i < num && genePool.size() < parameters.max_population; ++i) {
		std::unique_ptr<std::string> currentGene = std::make_unique<std::string>();
		std::string tempGoal(goal);
		for (int j = 0; j < goal.size(); ++j) {
			int pos = rand() % tempGoal.size();

			currentGene->push_back(tempGoal[pos]);
			tempGoal.erase(pos, 1);
		}
		AddEntity(std::move(currentGene));
	}
}

int Population::Iterate()
{
	while (genePool.size() < parameters.max_population) {
		if (rand() % 1 == 0 && genePool.size() > 1) {
			int first = rand() % genePool.size();
			int second = rand() % genePool.size();

			while (first == second) {
				second = rand() % genePool.size();
			}

			AddEntity(std::move(genePool[first].second.Crossover(genePool[second].second.GetGene())));
		}
		else {
			AddEntity(std::move(genePool[rand() % genePool.size()].second.Mutation()));
		}
		
	}

	SortGenePool();

	for (int i = 0; i < parameters.die_num; ++i) {
		if (genePool.size() == 1) {
			throw std::exception("Population is dead!");
		}
		genePool.pop_back();
	}

	return genePool[0].first;
}

std::string Population::BestGene()
{
	SortGenePool();
	return genePool[0].second.GetGene();
}

bool Compare(const std::pair<int, Entity> & first, const std::pair<int, Entity> & second)
{
	return (first.first < second.first);
}

void Population::AddEntity(std::unique_ptr<std::string> gene)
{
	if (genePool.size() == parameters.max_population) {
		return;
	}

	Entity currentEntity(std::move(gene), goal);

	genePool.push_back(std::pair<int, Entity>(currentEntity.Cost(), std::move(currentEntity)));
}

void Population::SortGenePool()
{
	std::sort(genePool.begin(), genePool.end(), Compare);
}
