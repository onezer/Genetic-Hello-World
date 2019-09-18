#pragma once

#include<string>

class Entity {
	
	std::string gene;
	std::string goal;

public:
	bool elite;

	Entity(const std::string & gene, const std::string goal);

	int Cost() const;

	std::string Crossover(const std::string & other) const;
	std::string Mutation() const;

	std::string GetGene() const;

private:

	int Position(char c, const std::string & s) const;
};