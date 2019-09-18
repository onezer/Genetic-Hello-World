#include "genetic.h"

Genetic::Genetic(std::string goal, Parameters parameters) : goal{goal}, parameters{parameters}
{
}

void Genetic::InitializePopulation(int num)
{
	population = Population(num, goal, parameters);
}

int Genetic::Iterate()
{
	population.CreateEntities(parameters.new_entities);

	int cost = population.Iterate();

	return cost;
}

std::string Genetic::GetBestGene()
{
	return population.BestGene();
}
