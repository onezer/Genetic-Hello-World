#include <iostream>
#include "genetic.h"
#include <time.h>

int main(){

	srand(time(NULL));

	int initial_num = 2000;
	int max_population = 2000;
	int die_num = 1500;
	int new_entities = 1;
	

	try {
		Parameters parameters(max_population, new_entities, die_num);
		Genetic gen("Egyszer volt hol nem volt, volt egyszer egy...", parameters);

		gen.InitializePopulation(initial_num);

		int cost = 1;

		for (int i = 0; i < 200 && cost != 0; ++i) {
			cost = gen.Iterate();
			if (i % 2 == 0 || cost == 0) {
				std::cout << i << ". gen: " << gen.GetBestGene() << "\n";
			}

		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}