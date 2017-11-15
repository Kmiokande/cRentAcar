#include <stdlib.h>
#include <time.h>

#include "car.h"

typedef struct car {
	char modelo[31];
	char cor[9];
	char ano[5];
	char preco[11];
	char placa[9];
	int renavam[12];
	char km[7];
	char status;
	char qtd_alugado[120];
  	struct Car* proxCar;
} Car;


// Validação de cor
int valColor(char color[9]) {
	int i;
	for(i=0; color[i]!='\0'; i++) {
		if(color[i] >= 33 && color[i] <= 64)
			return 1; // Return False 
	}
	return 0; // Return True 
}

int valYear(char year[5]) {
	int i;
	for(i=0; year[i]!='\0'; i++) {
		if(color[i] >= 48 && color[i] <= 57)
			return 0; // Return True 
	}
	return 1; // Return False
}

// void saveDataCar(char *array) {
// 	FILE *file = fopen("car.dat", "wb"); // Substitui todo o texto já existente
// 	fwrite(array, sizeof(char), sizeof(array), file);
// 	fclose(file);
// }
