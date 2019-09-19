#pragma once

#include<string>
#include<memory>

class Entity {
	
	std::unique_ptr<std::string> gene;
	std::string goal;

public:
	bool elite;

	Entity(std::unique_ptr<std::string> gene, const std::string goal);

	int Cost() const;

	std::unique_ptr<std::string> Crossover(const std::string & other) const;
	std::unique_ptr<std::string> Mutation() const;

	const std::string & GetGene() const;

private:

	int Position(char c, const std::string & s) const;
};