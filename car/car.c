#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "car.h"

// >> [ CRUD ]
//  [ Cria a lista encadeada vazia ]
Car* createListCar() { return NULL; }

// [ Cadastrar usuário ]
void singUpCar(Car **DataCar) {
  Car* _newCar = (Car*)malloc(sizeof(Car));

  //while (valModel(_newCar->modelo)) {
  printf("Modelo: ");
  scanf(" %30[^\n]", _newCar->modelo);
  //}

  //while (valColor(_newCar->cor)) {
  printf("Cor: ");
  scanf(" %8[^\n]", _newCar->cor);
  //}

  //while (valYear(_newCar->ano)) {
  printf("Ano: ");
  scanf(" %4[^\n]", _newCar->ano);
  //}

  printf("Preco: R$");
  scanf("%f", &_newCar->preco);

  while (valPlate(_newCar->placa)) {
    printf("Placa: ");
    scanf(" %8[^\n]", _newCar->placa);
  }

  while (valRenavam(_newCar->ano, _newCar->renavam)) {
    printf("Renavam: ");
    scanf(" %11[^\n]", _newCar->renavam);
  }

  _newCar->status = 1; // 1 - Disponível para alugar | 0 - Indisponível
  _newCar->qtd_alugado = 0;

  _newCar -> proxCar = *DataCar;
  *DataCar = _newCar;
}

// [ Ver todos os carros cadastrados ]
void listCar(Car *DataCar) {
  Car *aux = NULL;
  for(aux = DataCar; aux != NULL; aux=aux->proxCar) {
    printf("%s\n", aux->modelo);
    printf("%s\n", aux->cor);
    printf("%s\n", aux->ano);
    printf("%.2f\n", aux->preco);
    printf("%s\n", aux->placa);
    printf("%s\n", aux->renavam);
    printf("%d\n", aux->status);
    printf("%d\n", aux->qtd_alugado);
    printf("-------------------\n");
  }
}

// >> [ Validações ]
// [ Valida Modelo ]
int valModel(char model[31]) {
  if (strlen(model) != 0) {
	  for (int i = 0; model[i] != '\0'; i++) {
	    if (model[i] >= 34 && model[i] <= 43 && model[i] >= 58 && model[i] <= 64) {
	      printf("Modelo inválido!");
	      return 1;  // Return False   	
	    }
	  }
	  return 0; // True
  }
  return 1;  // Return False
}

// [ Valida Cor ]
int valColor(char color[9]) {
  if (strlen(color) != 0) {
	  for (int i = 0; color[i] != '\0'; i++) {
	    if (color[i] >= 34 && color[i] <= 43 && color[i] >= 58 && color[i] <= 64)
	      printf("Cor inválido! \n");
	      return 1;  // Return False
	  }
	  return 0; // True
  }
  return 1;  // Return False
}

// [ Valida Ano ]
int valYear(char year[5]) {
  int i;
  for (i = 0; year[i] != '\0'; i++) {
    if (year[i] >= 48 && year[i] <= 57) return 0;  // Return True
  }
  return 1;  // Return False
}

// [ Valida Placa]
int valPlate(char plate[9]) {
  if (strlen(plate) == 0) {
    return 1; // False
  } else if (strlen(plate) == 8 && plate[3] == '-') { // Check se existe '-'
    for (int i = 0; plate[i] != '\0'; ++i) {
      if (i < 3) {  // Letras
        if (!((plate[i] >= 65 && plate[i] <= 90) || (plate[i] >= 97 && plate[i] <= 122))) {
          printf("Placa Inválida\n");
          return 1;  // False
        }
      }
      if (i > 3) {  // Numeros
        if (!(plate[i] >= 48 && plate[i] <= 57)) {
          printf("Placa Inválida\n");
          return 1;  // False
        }
      }
    }
    return 0;  // True
  } else {
    printf("Placa Inválida\n");
    return 1;  // False
  }
}

// [ Valida renavam ]
int valRenavam(char ano[5], char renavam[12]) {
  int Iano, comp;

  comp = strlen(renavam);  // Vai verificar o comprimento do renavam

  sscanf(ano, "%d", &Iano);  // Ano em Inteiro

  for (int i = 0; i < 11; i++) {
    if (renavam[i] >= '0' && renavam[i] <= '9') {  // Verifica se o renavam possui número
      if ((comp == 9 && Iano <= 2012) || (comp == 11 && Iano >= 2013)) {  // Verifica o comprimento do renavam e o ano
        return 0;            // Return True
      }
    }
  }
  return 1;  // Return False
}

// [ Valida Km ]
int valKm(char km[7]) {
  for (int i = 0; km[i] != '\0'; i++) {
    if (!(km[i] >= '0' && km[i] <= '9')) {  // Verifica se é tudo número
      return 1; }// Return False
  }
  return 0;  // Return True
}

// >> [ File I/O ]
void saveDataCar(char *array) {
	FILE *file = fopen("car.dat", "a+"); // Substitui todo o texto já existente
	if (file != NULL) {
		fwrite(array, sizeof(char), sizeof(array), file);
		fclose(file);
	} else {
		printf("Arquivo aberto ou não encontrado\n");
	}
}
