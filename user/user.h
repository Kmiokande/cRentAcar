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
  char numero[6];
  char bairro[31];
};

typedef struct user {
  char nome[50];
  char sobrenome[50];
  char data_nascimento[11];
  char cpf[12];
  char nome_mae[80];
  char rg[10];
  char cnh[12];
  struct end endereco;
  char email[50];
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
int valCPF(char cpf[12]); // CPF  xxx.xxx.xxx-xx
int valTelefone(char fone[15]); // Telefone  (xx)xxxxx-xxxx
int valEmail(char email[80]); // Email  xxxxxx@xxxx.xxx
int valData(const char data[12]); // Data Nascimento  xx/xx/xx
int valRG(const char rg[12]); // RG   xx.xxx.xxx-x

// Others
int checkExistUser(char cpf[12], User *DataUser);
void incrementScore(User* DataUser, char cpf[11]);
int bestClients();

void freeMemory();
#endif