#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "car.h"

typedef struct car {
  char modelo[31];
  char cor[9];
  char ano[5];
  char preco[11];
  char placa[9];
  char renavam[12];
  char km[7];
  int status;
  int qtd_alugado;
  struct car* proxCar;
} Car;

// >> [ CRUD ]
//  [ Cria a lista encadeada vazia ]
Car* createListCar() {
  return NULL;
}

// [ Cadastrar usuário ]
Car* singUpCar(Car* DataCar) {
  Car* _newCar = (Car*)malloc(sizeof(Car));
  _newCar->proxCar = DataCar;

  if (_newCar != NULL) {
    printf("Modelo: ");
    scanf(" %30[^\n]", _newCar->modelo);

    printf("Cor: ");
    scanf(" %8[^\n]", _newCar->cor);

    printf("Ano: ");
    scanf(" %4[^\n]", _newCar->ano);

    printf("Preco: ");
    scanf(" %10[^\n]", _newCar->preco);

    printf("Placa: ");
    scanf(" %8[^\n]", _newCar->placa);

    printf("Renavam: ");
    scanf(" %11[^\n]", _newCar->renavam);

    _newCar->status = 1;
    _newCar->qtd_alugado = 0;
  }

  return _newCar;
}

// >> [ Validações ]
// [ Valida Modelo ]
int valModel(char model[31]) {
  int i;
  for (i = 0; model[i] != '\0'; i++) {
    if (model[i] >= 34 && model[i] <= 43 && model[i] >= 58 && model[i] <= 64)
      return 1; // Return False
  }
  return 0; // Return True
}

// [ Valida Cor ]
int valColor(char color[9]) {
  int i;
  for (i = 0; color[i] != '\0'; i++) {
    if (color[i] >= 33 && color[i] <= 64) 
      return 1;  // Return False
  }
  return 0;  // Return True
}

// [ Valida Ano ]
int valYear(char year[5]) {
  int i;
  for (i = 0; year[i] != '\0'; i++) {
    if (year[i] >= 48 && year[i] <= 57) 
      return 0;  // Return True
  }
  return 1;  // Return False
}

// [ Valida Placa]
int valPlate(char plate[9]) {
  int i, j, k;
  for (i = 0; i < 3; i++) { // Percorre as três primeiras posições do vetor
    if(plate[i] >= 65 && plate[i] <= 90 || plate[i] >= 97 && plate[i] <= 122) // Verifica se são letras
      for (j = 3; j < 4; j++) // Percorre a quarta posição do vetor
        if (plate[j] == 45) // Verifica se possui um '-'
          for (k = 4; k < 9; k++) // Percorre o restante do vetor
            if (plate[k] >= 48 && plate[k] <= 57) // Verifica se são números
              return 0; // Return True
  }
  return 1; // Return False
}

// void saveDataCar(char *array) {
// 	FILE *file = fopen("car.dat", "wb"); // Substitui todo o texto já
// existente 	fwrite(array, sizeof(char), sizeof(array), file);
// 	fclose(file);
// }
