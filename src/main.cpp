#include <iostream>
#include "genetic.h"

#include <time.h>

int main(){

	srand(time(NULL));

	int initial_num = 100;
	int max_population = 100;
	int die_num = 50;
	int new_entities = 30;
	
	Parameters parameters(max_population, new_entities, die_num);
	Genetic gen("Hello World!", parameters);

	gen.InitializePopulation(initial_num);

	int cost = 1;

	for (int i = 0; i < 1000 && cost != 0; ++i) {
		cost = gen.Iterate();
		if (i % 5 == 0 || cost == 0) {
			std::cout << i << ". gen: " << gen.GetBestGene() << "\n";
		}
		
	}


	return 0;
}