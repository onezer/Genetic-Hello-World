#pragma once

class Parameters {
public:
	Parameters(int elite_num, int best_threshold, int max_population, int new_entities) : elite_num{ elite_num },
		best_threshold{ best_threshold }, 
		max_population{ max_population },
		new_entities{ new_entities }
	{}

	int elite_num; //number of maximum entities that are passing to the next generation
	int best_threshold; //minimum cost of an elite entity
	int max_population; //maximum number of entities in a population
	int new_entities; //new random entities created in each generation
};