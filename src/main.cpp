#include <iostream>
#include "genetic.h"

#include <time.h>

int main(){

	srand(time(NULL));
	
	Parameters parameters(100, 30, 50);
	Genetic gen("Hello World!", parameters);

	gen.InitializePopulation(100);

	int cost = 1;

	for (int i = 0; i < 1000 && cost != 0; ++i) {
		cost = gen.Iterate();
		if (i % 5 == 0 || cost == 0) {
			std::cout << i << ". gen: " << gen.GetBestGene() << "\n";
		}
		
	}


	return 0;
}