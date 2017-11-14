#include <stdlib.h>
#include <time.h>

#include "car.h"

void saveDataCar(char *array) {
	FILE *file = fopen("car.dat", "wb"); // Substitui todo o texto já existente
	fwrite(array, sizeof(char), sizeof(array), file);
	fclose(file);
}
