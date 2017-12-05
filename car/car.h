#ifndef _CARH_
#define _CARH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../user/user.h"
#include "../functions.h"
#include "../historic/historic.h"


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
Car *deleteCar(Car *DataCar); // Deleta cadastro do carro pela placa

void rentCar(Car *DataCar, Historic *DataHistoric, User *DataUser); // Aluga carros
void returnCar(Car *DataCar, Historic *DataHistoric, User *DataUser); // Devolve carros
void CarRented(Car *DataCar); // Mostra os carros alugados
void CarFree(Car *DataCar); // Mostra os carros disponiveis

// Validações
int valModel(char model[31]); // Modelo
int valYear(int year); // Ano
int valPlate(char plate[9]); // Placa
int valRenavam(int ano, char renavam[12]); // Renavam

// Maninupulação do arquivo
void saveCar(Car *DataCar); // Salvar Dados em Arquivo 'car.dat'
Car *loadCar(Car *DataCar); // Carregar Dados do Arquivo 'car.dat'

// Others
void showBestCar(Car *DataCar);
int checkIfCarAvariable(char placa[9], Car *DataCar);
int checkIfCarRented(char placa[9], Car *DataCar);

void showBestCar(Car *DataCar);

#endif