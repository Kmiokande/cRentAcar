#include <stdlib.h>
#include <time.h>

#include "car.h"

typedef struct car {
	char modelo[10];
	char cor[10];
	char ano[4];
	char preco[10];
	char placa[7];
	int renavam;
	char km[80];
	char status;
	char qtd_alugado[120];
  	struct Car* proxCar;
} Car;

// void saveDataCar(char *array) {
// 	FILE *file = fopen("car.dat", "wb"); // Substitui todo o texto já existente
// 	fwrite(array, sizeof(char), sizeof(array), file);
// 	fclose(file);
// }
