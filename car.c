#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "car.h"
#include "../functions.h"

// >> [ CRUD ]

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
    printf("Modelo: %s\n", aux->modelo);
    printf("Cor: %s\n", aux->cor);
    printf("Ano: %s\n", aux->ano);
    printf("Placa: %s\n", aux->placa);
    printf("Preço: %.2fR$\n", aux->preco);
    printf("Renavam: %s\n", aux->renavam);
    if (aux->status == 1)
		printf("Status: Veículo disponível\n");
	else
		printf("Status: Veículo indisponível\n");
    printf("Quantidade de vezes alugado: %d\n", aux->qtd_alugado);
    printf("\n--------------------------------------------------\n");
  }
}

// [ Busca cadastro do carro pela placa ]
int searchCar(Car *DataCar) {
    char placa[9];
    printf("Informe a placa: ");
    scanf(" %8[^\n]", placa);

    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (strcmp(aux->placa, placa) == 0) { // Se a placa for igual ao cadastrado ele retorna 0
            printf("Modelo: %s\n", aux->modelo);
            printf("Cor: %s\n", aux->cor);
            printf("Ano: %s\n", aux->ano);
            printf("Placa: %s\n", aux->placa);
            printf("Preço: %.2fR$\n", aux->preco);
            printf("Renavam: %s\n", aux->renavam);
            if (aux->status == 1)
				printf("Status: Veículo disponível\n");
			else
				printf("Status: Veículo indisponível\n");
            printf("Quantidade de vezes alugado: %d\n", aux->qtd_alugado);
            return False();
        }
    }
    printf("Carro não cadastrado\n");
    return True(); // Não encontrou o elemento
}

void rentCar(Car *DataCar) { // Irei terminar depois | Dor de cabeça
    char placa[9];
    char cpf[12];

    listCar(DataCar);
    printf("CPF do cliente: ");
    scanf(" %11[^\n]", cpf);
    printf("Placa do Carro que deseja alugar: ");
    scanf(" %8[^\n]", placa);

    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (strcmp(aux->placa, placa) == 0) { // Se a placa for igual ao cadastrado ele retorna 0
            DataCar->status = 0; // Errado aqui
        }
    }
}

// >> [ Validações ]
// [ Valida Modelo ]
int valModel(char model[31]) {
  if (strlen(model) != 0) {
	  for (int i = 0; model[i] != '\0'; i++) {
	    if (model[i] >= 34 && model[i] <= 43 && model[i] >= 58 && model[i] <= 64) {
	      printf("Modelo inválido!");
            False();
	    }
	  }
      return True();
  }
    False();
}

// [ Valida Cor ]
int valColor(char color[9]) {
  if (strlen(color) != 0) {
	  for (int i = 0; color[i] != '\0'; i++) {
	    if (color[i] >= 34 && color[i] <= 43 && color[i] >= 58 && color[i] <= 64)
	      printf("Cor inválido! \n");
          False();
	  }
      return True();
  }
    False();
}

// [ Valida Ano ]
int valYear(char year[5]) {
  int i;
  for (i = 0; year[i] != '\0'; i++) {
      if (year[i] >= 48 && year[i] <= 57) return True();
  }
    False();
}

// [ Valida Placa]
int valPlate(char plate[9]) {
  if (strlen(plate) == 0) {
      False();
  } else if (strlen(plate) == 8 && plate[3] == '-') { // Check se existe '-'
    for (int i = 0; plate[i] != '\0'; ++i) {
      if (i < 3) {  // Letras
        if (!((plate[i] >= 65 && plate[i] <= 90) || (plate[i] >= 97 && plate[i] <= 122))) {
          printf("Placa Inválida\n");
            False();
        }
      }
      if (i > 3) {  // Numeros
        if (!(plate[i] >= 48 && plate[i] <= 57)) {
          printf("Placa Inválida\n");
            False();
        }
      }
    }
      return True();
  } else {
    printf("Placa Inválida\n");
      False();
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
          return True();
      }
    }
  }
    False();
}

// [ Valida Km ]
int valKm(char km[7]) {
  for (int i = 0; km[i] != '\0'; i++) {
    if (!(km[i] >= '0' && km[i] <= '9')) {  // Verifica se é tudo número
        False();
    }
  }
    return True();
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
