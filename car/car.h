#ifndef _CARH_
#define _CARH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../user/user.h"
#include "../functions.h"
#include "../historic/historic.h"

// Colors Text for Terminal Unix

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"


 typedef struct car {
  char modelo[31];
  char cor[9];
  int ano;
  float preco;
  char placa[9];
  char renavam[12];
  char km[7];
  char cpf[12];
  int status;
  int qtd_alugado;
  struct car* proxCar;
} Car;

// CRUD
void listCar(Car* DataCar);
void singUpCar(Car **DataCar); // Cadastrar carro
int searchCar(Car *DataCar); // Busca cadastro do carro pela placa
void editCar(Car *DataCar);
Car *deleteCar(Car *DataCar); // Deleta cadastro do carro pela placa

void rentCar(Car *DataCar, Historic *DataHistoric, User *DataUser);
void CarRented(Car *DataCar); // Mostra os carros alugados
void CarFree(Car *DataCar); // Mostra os carros disponiveis

// Validações
int valModel(char model[31]); // Modelo
int valColor(char color[9]); // Cor
int valYear(int year); // Ano
int valPrice(); // Preço
int valPlate(char plate[9]); // Placa
int valRenavam(int ano, char renavam[12]); // Renavam
int valKm(char km[7]); // km's rodados
int valDate(); // Data

// Maninupulação do arquivo
void saveCar(Car *DataCar); // Salvar Dados em Arquivo 'car.dat'
Car *loadCar(Car *DataCar); // Carregar Dados do Arquivo 'car.dat'

// Others
int checkExistCar(char placa[9], Car *DataCar);

#endif