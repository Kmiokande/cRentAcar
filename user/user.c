#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "user.h"

struct end {
  char sigla_estado[2];
  char cidade[50];
  char rua[50];
  int numero;
  char bairro[30];
};

typedef struct user {
  char nome[50];
  char sobrenome[50];
  char data_nascimento[10];
  char cpf[12];
  char nome_mae[80];
  char rg[20];
  char cnh[20];
  struct end endereco;
  char email[80];
  char fone[15];
  struct user* proxUser;
} User;

// >> [ CRUD ]
//  [ Cria a lista encadeada vazia ]
User* createListUser() { return NULL; }

// [ Cadastrar usuário ]
User* singUpUser(User* DataUser) {
  User* _newUser = (User*)malloc(sizeof(User));
  _newUser->proxUser = DataUser;

  if (_newUser != NULL) {
    while (valName(_newUser->nome)) {
      printf("Nome: ");
      scanf(" %49[^\n]", _newUser->nome);
    }

    while (valName(_newUser->sobrenome)) {
      printf("Sobrenome: ");
      scanf(" %49[^\n]", _newUser->sobrenome);
    }

    printf("Data de Nascimento: ");
    scanf(" %9[^\n]", _newUser->data_nascimento);

    while (valCPF(_newUser->cpf)) {
      printf("CPF: ");
      scanf(" %11[^\n]", _newUser->cpf);
    }
    while (valName(_newUser->nome_mae)) {
      printf("Nome completo da Mãe: ");
      scanf(" %49[^\n]", _newUser->nome_mae);
    }

    printf("RG: ");
    scanf(" %49[^\n]", _newUser->rg);

    printf("Endereço [Sigla do Estado]:");
    scanf(" %49[^\n]", _newUser->endereco.sigla_estado);

    printf("Endereço [Cidade]:");
    scanf(" %49[^\n]", _newUser->endereco.cidade);

    printf("Endereço [Rua]:");
    scanf(" %49[^\n]", _newUser->endereco.rua);

    printf("Endereço [Número]:");
    scanf(" %d", &_newUser->endereco.numero);

    printf("Endereço [Bairro]:");
    scanf(" %49[^\n]", _newUser->endereco.bairro);

    printf("CNH: ");
    scanf(" %49[^\n]", _newUser->cnh);

    printf("Email: ");
    scanf(" %49[^\n]", _newUser->rg);

    printf("Telefone: ");
    scanf(" %49[^\n]", _newUser->fone);
  }

  return _newUser;
}

// [ Ver todos os Usuários cadastrados ]
void listUser(User* DataUser) {
  User* p;
  for (p = DataUser; p != NULL; p = p->proxUser) {
    printf("- %s\n", p->nome);
  }
}

// >> [ Validações ]
// [ Validação de CPF ]
int valCPF(char cpf[12]) {
  int i, comp, aux = 0, dig1, dig2, result1, result2, valor;

  comp = strlen(cpf);  // Contagem da quantidade de caracteres no vetor.

  // Se na condição o CPF não possuir 11 digitos apresenta erro, caso contrario
  // inicia a verificação dos dois ultimos digitos.
  if (comp != 11) {
    if (comp > 0) {
      printf("\n >> Digite os 11 caracteres do CPF! \n");
    }
    return 1;
  } else {
    for (i = 0; i < 11; i++) {  // Efetua a conversao do vetor de tipo char para
                                // um vetor de tipo int usando tabela ASCII.
      cpf[i] -= 48;
    }

    for (i = 0; i < 9; i++) {  // Primeiro Dígito.
      aux += cpf[i] * (10 - i);
    }

    result1 = aux % 11;

    if (result1 == 0 || result1 == 1) {
      dig1 = 0;
    } else {
      dig1 = 11 - result1;
    }

    aux = 0;  // Reseta o aux

    for (i = 0; i < 10; i++) {  // Segundo Dígito.
      aux += cpf[i] * (11 - i);
    }

    valor = (aux / 11) * 11;
    result2 = aux - valor;

    if (result2 == 0 || result2 == 1) {
      dig2 = 0;
    } else {
      dig2 = 11 - result2;
    }

    // RESULTADOS DA VALIDAÇÃO.
    if (dig1 == cpf[9] && dig2 == cpf[10]) {
      return 0;
    } else {
      printf("\n >> CPF inválido! \n");
      return 1;
    }
  }
}

// [ Valida Nome e Sobrenome ]
int valName(char name[50]) {
  if (strlen(name) > 3) {
    for (int i = 0; name[i] != '\0'; i++) {
      if (name[i] >= 33 && name[i] <= 45 && name[i] >= 47 && name[i] <= 64) {
        printf("\n >> Nome inválido! \n");
        return 1;  // False
      }
    }
  } else {
    printf("Digite mais caracteres, este não é um nome válido!");
    return 1;  // False
  }

  return 0;  // True
}

// [ I/O dos dados e memoria ]

// void saveDataUser(char* array) { // Salvar a lista em arquivo *.text
// 	FILE *file = fopen("user.dat", "wb"); // Substitui todo o texto já
// existente 	fwrite(User, sizeof(char), sizeof(user), file);
// 	fclose(file);
// }

// [ Liberar memória ao sair ]
void freeMemory(User* p) { free(p); }