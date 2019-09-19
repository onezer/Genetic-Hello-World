#include "genetic.h"

#include <iostream>
#include <time.h>
#include <chrono>

int main(){

	srand(time(NULL));

	int initial_num = 100000;
	int max_population = 100000;
	int die_num = 60000;
	int new_entities = 0;
	

	try {
		Parameters parameters(max_population, new_entities, die_num);
		Genetic gen("Egyszer volt hol nem volt, volt egyszer egy taltos, aki nagyon szeretett volna krumplit enni, de az anyja megtiltotta neki, ezert elment hazulrol :(", parameters);

		gen.InitializePopulation(initial_num);
		std::cout << "Initialization complete\n\n";
		int cost = 1;

		for (int i = 0; i < 500 && cost != 0; ++i) {
			auto start = std::chrono::steady_clock::now();
			cost = gen.Iterate();
			auto end = std::chrono::steady_clock::now();

			if (i % 1 == 0 || cost == 0) {
				std::cout << i << ". gen: " << gen.GetBestGene() << "\n";
			}

			std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us\n\n";

		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}