#include "population.h"

#include <algorithm>

Population::Population(int num, std::string goal) : goal{goal}
{
	CreateEntities(num);
}

void Population::CreateEntities(int num)
{
	for (int i = 0; i < num; ++i) {
		std::string currentGene;
		std::string tempGoal(goal);
		for (int j = 0; j < goal.size(); ++j) {
			int pos = rand() % goal.size();

			currentGene.push_back(goal[pos]);
			tempGoal.erase(pos, 1);
		}
		AddEntity(currentGene);
	}
}

int Population::Iterate(Parameters parameters)
{
	while (genePool.size() < parameters.max_population) {
		if (rand() % 2 == 1) {
			AddEntity(genePool[rand() % genePool.size()].second.Mutation());
		}
		else {
			int first = rand() % genePool.size();
			int second = rand() % genePool.size();

			while (first == second) {
				second = rand() % genePool.size();
			}

			AddEntity(genePool[first].second.Crossover(genePool[second].second.GetGene));
		}
		
	}

	SortGenePool();

	for (int i = 0; i < parameters.die_num; ++i) {
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

void Population::AddEntity(std::string gene)
{
	Entity currentEntity(gene, goal);

	genePool.push_back(std::pair<int, Entity>(currentEntity.Cost(), currentEntity));
}

void Population::SortGenePool()
{
	std::sort(genePool.begin(), genePool.end(), Compare);
}
