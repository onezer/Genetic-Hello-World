#include "entity.h"

#include <math.h>
#include <stdlib.h>
#include <unordered_map>


Entity::Entity(const std::string & gene, const std::string & goal) : gene{ gene }, goal{ goal }
{
}

Entity::Entity(std::string && gene, std::string && goal) : gene { gene }, goal{ goal }
{
}

int Entity::Cost() const
{
	int cost = 0;

	//for (int i = 0; i < (int)gene.size(); ++i) {
	//	int pos = Position(gene[i], goal);
	//
	//	if (pos == -1) {
	//		throw std::exception("Invalid gene!");
	//	}
	//
	//	cost += std::abs(pos - i);
	//}

	for (int i = 0; i < (int)gene.size(); ++i) {
		if (gene[i] != goal[i]) {
			++cost;
		}
	}

	return cost;
}

std::string Entity::Crossover(const std::string & other) const
{
	std::string newGene;

	for (int i = 0; i < (int)gene.size(); ++i) {

		char c = rand() % 2 == 1 ? gene[i] : other[i];

		newGene.push_back(c);
	}

	return newGene;
}

std::string Entity::Mutation() const
{
	std::string newGene(gene);

	int mutation_num = rand() % 4 + 1;

	for (int i = 0; i < mutation_num; ++i) {
		int first = rand() % (int)gene.size();
		int second = rand() % (int)gene.size();
		while (first == second) {
			second = rand() % (int)gene.size();
		}

		std::swap(newGene[first], newGene[second]);
	}

	return newGene;
}

const std::string & Entity::GetGene() const
{
	return gene;
}

int Entity::Position(char c, const std::string & s) const
{
	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] == c) {
			return i;
		}
	}

	return -1;
}

