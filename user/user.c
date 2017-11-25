#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"

// >> [ CRUD ]
//  [ Cria a lista encadeada vazia ]
User* createListUser() { return NULL; }

// [ Cadastrar usuário ]
void singUpUser(User **DataUser) {
  User *_newUser = (User*)malloc(sizeof(User));

  //while (valName(_newUser->nome)) {
  printf("Nome: ");
  scanf(" %49[^\n]", _newUser->nome);
  //}

  //while (valName(_newUser->sobrenome)) {
  printf("Sobrenome: ");
  scanf(" %49[^\n]", _newUser->sobrenome);
  //}

  printf("Data de Nascimento: ");
    scanf(" %10[^\n]", _newUser->data_nascimento);

  //while (valCPF(_newUser->cpf)) {
  printf("CPF: ");
  scanf(" %11[^\n]", _newUser->cpf);
  //}
  
  //while (valName(_newUser->nome_mae)) {
  printf("Nome completo da Mãe: ");
  scanf(" %49[^\n]", _newUser->nome_mae);
  //}

  printf("RG: ");
  scanf(" %49[^\n]", _newUser->rg);

  printf("Endereço [Sigla do Estado]:");
  scanf(" %2[^\n]", _newUser->endereco.sigla_estado);

  printf("Endereço [Cidade]:");
  scanf(" %50[^\n]", _newUser->endereco.cidade);

  printf("Endereço [Rua]:");
  scanf(" %50[^\n]", _newUser->endereco.rua);

  printf("Endereço [Número]: ");
  scanf("%d", &_newUser->endereco.numero);

  printf("Endereço [Bairro]:");
  scanf(" %49[^\n]", _newUser->endereco.bairro);

  printf("CNH: ");
  scanf(" %49[^\n]", _newUser->cnh);

  printf("Email: ");
  scanf(" %49[^\n]", _newUser->rg);

  printf("Telefone: ");
  scanf(" %49[^\n]", _newUser->fone);

  _newUser -> proxUser = *DataUser;
  *DataUser = _newUser;
}

// [ Ver todos os Usuários cadastrados ]
void listUser(User *DataUser) {
  User *aux = NULL;
  for(aux = DataUser; aux != NULL; aux=aux->proxUser) {
    printf("%s\n", aux->nome);
    printf("%s\n", aux->sobrenome);
    printf("%s\n", aux->data_nascimento);
    printf("%s\n", aux->cpf);
    printf("%s\n", aux->nome_mae);
    printf("%s\n", aux->rg);
    printf("%s\n", aux->endereco.sigla_estado);
    printf("%s\n", aux->endereco.cidade);
    printf("%s\n", aux->endereco.rua);
    printf("%d\n", aux->endereco.numero);
    printf("%s\n", aux->endereco.bairro);
    printf("%s\n", aux->cnh);
    printf("%s\n", aux->rg);
    printf("%s\n", aux->fone);
    printf("-------------------\n");
  }
}

// [ Verifica se existe o cpf cadastrado ]
int searchUser(User *DataUser) {
  char cpf[12];
  printf("Informe o CPF: ");
  scanf(" %11[^\n]", cpf);

  for(User *aux = DataUser->cpf; aux != NULL; aux=aux->proxUser) {
    if (strcmp(aux->cpf, cpf) == 0) // Se o cpf for igual ao cadastrado ele retorna 0
      printf("%s\n", aux->nome);
      printf("%s\n", aux->sobrenome);
      return 1;
  }
  printf("Cliente não cadastrado\n");
  return 0; // Não encontrou o elemento
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
      cpf[i] -= 48;  // um vetor de tipo int usando tabela ASCII.
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
  if (strlen(name) == 0 || strlen(name) < 4) {     
    return 1;  // False
  } 
  for (int i = 0; name[i] != '\0'; i++) {
    if (name[i] >= 33 && name[i] <= 45 && name[i] >= 47 && name[i] <= 64) {
      printf("\n >> Nome inválido! \n");
      return 1;  // False
    }
  }

  return 0;  // True
}

// [ Validar Data ]
// int valData(char data[11]) { // [-] Aceitar apenas 18 anos acima
// 	if (strlen(data) > 0) {
// 		for (int i = 0; data[i] != '\0'; ++i) {
// 			if (i < 2) {
// 				if (!(data[i] >= 48 && data[i] <= 57)) {
//           			printf("Placa Inválida\n");
//           			return 1;  // False
//         		}
// 			}
// 			if (i > 3 && i < 6) {}
// 		}
// 		return 0; // True

// 	} else {
// 		return 1/ // False
// 	}

// }

// [ I/O dos dados e memoria ]

// void saveDataUser(char* array) { // Salvar a lista em arquivo *.text
// 	FILE *file = fopen("user.dat", "wb"); // Substitui todo o texto já
// existente 	fwrite(User, sizeof(char), sizeof(user), file);
// 	fclose(file);
// }

// [ Liberar memória ao sair ]
void freeMemory(User* p) { free(p); }