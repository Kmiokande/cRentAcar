#include <stdlib.h>
#include <time.h>

#include "car.h"

struct car {
	char modelo[10];
	char cor[10];
	char ano[4];
	char preco[10];
	char placa[7];
	int renavam;
	char km[80];
	char status;
	char qtd_alugado[120];
} car[20];

void saveDataCar(char *array) {
	FILE *file = fopen("car.dat", "wb"); // Substitui todo o texto já existente
	fwrite(car, sizeof(char), sizeof(car), file);
	fclose(file);
}
