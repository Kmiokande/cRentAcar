#ifndef _USERH_
#define _USERH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../functions.h"

struct end {
  char sigla_estado[3];
  char cidade[51];
  char rua[51];
  int numero;
  char bairro[31];
};

typedef struct user {
  char nome[50];
  char sobrenome[50];
  char data_nascimento[11];
  char cpf[12];
  char nome_mae[80];
  char rg[20];
  char cnh[20];
  struct end endereco;
  char email[80];
  char fone[15];
  int score;
  struct user* proxUser;
} User;

// Maninupulação do arquivo
User *loadUser(User *DataUser); // Salvar Dados em Arquivo 'user.dat'
void saveUser(User *DataUser); // Carregar Dados do Arquivo 'user.dat'

// CRUD
void singUpUser(User **DataUser); // Cadastrar usuário
void listUser(User *DataUser); // Ver todos os usuarios cadastrados
void searchUser(User *DataUser); // Busca cadastro do cliente pelo CPF
void editUser(User *DataUser);

User *deleteUser(User *DataUser); // Deleta cadastro da lista

// Validações
int valCPF(char cpf[12]); // CPF
int valAddress(); // Endereço
int valFone(); // Telefone
int valEmail(); // Email
int valName(char name[50]); // Nome
int valData(char data[12]); // Data Nascimento

// Others
int checkExistUser(char cpf[12], User *DataUser);
int bestClients();

void freeMemory();
#endif