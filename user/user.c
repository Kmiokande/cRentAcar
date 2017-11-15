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
	char data_nascimento[20];
	char cpf[20];
	char nome_mae[80];
	char rg[20];
	char email[80];
	char cnh[20];
	struct end endereco;
	char fone[15];
	User* proxUser;
} User;

User* creatList(){
  return NULL;
}

// Cadastrar usuário
User* singUp(User* DataUser) {
	User* _newUser = (User*) malloc(sizeof(User));
	_newUser->proxUser = DataUser;

	if (_newUser != NULL) {

		printf("Nome: ");
		scanf("%49[^\n]s", &_newUser->nome);

		printf("Sobrenome: ");
		scanf("%49[^\n]s", &_newUser->sobrenome);

		printf("Data de Nascimento: ");
		scanf("%49[^\n]s", &_newUser->data_nascimento);

		printf("CPF: ");
		scanf("%49[^\n]s", &_newUser->cpf);

		printf("Nome da Mãe: ");
		scanf("%49[^\n]s", &_newUser->nome_mae);

		printf("RG: ");
		scanf("%49[^\n]s", &_newUser->rg);

		printf("Email: ");
		scanf("%49[^\n]s", &_newUser->rg);

		printf("Endereço [Sigla do Estado]:");
		scanf("%49[^\n]s", &_newUser->endereco.sigla_estado);

		printf("Endereço [Cidade]:");
		scanf("%49[^\n]s", &_newUser->endereco.cidade);

		printf("Endereço [Rua]:");
		scanf("%49[^\n]s", &_newUser->endereco.rua);

		printf("Endereço [Número]:");
		scanf("%49[^\n]s", &_newUser->endereco.numero);

		printf("Endereço [Bairro]:");
		scanf("%49[^\n]s", &_newUser->endereco.bairro);

		printf("CNH: ");
		scanf("%49[^\n]s", &_newUser->cnh);

		printf("Telefone: ");
		scanf("%49[^\n]s", &_newUser->fone);
	}

	return _newUser;
}


void listUser(User* DataUser) {
	User* p;
	for(p = DataUser; p != NULL; p = p->proxUser) {
    	printf("- %s\n", p->nome);
	}
}

// void saveDataUser(char* array) {
// 	FILE *file = fopen("user.dat", "wb"); // Substitui todo o texto já existente
// 	fwrite(User, sizeof(char), sizeof(user), file);
// 	fclose(file);
// }

// Validação de CPF
int valCPF(char cpf[11], int icpf[11]) {
	int i, comp, aux = 0, dig1, dig2, result1, result2, valor;

	// Efetua a conversao do vetor de tipo char para um vetor de tipo int usando tabela ASCII.
	for (i=0; i<11; i++) {
		icpf[i] = cpf[i] - 48;
	}

	// Faz a contagem de quantos caracteres possui no vetor.
	comp = strlen(cpf);

	// Se na condição o CPF não possuir 11 digitos apresenta erro, caso contrario inicia a verificação dos dois ultimos digitos.
	if (comp != 11) {
		printf("\nCPF Inválido, o mesmo não apresenta 11 digitos!\n");
	}
	else {
		// PRIMEIRO DIGITO.
		for (i=0; i<9; i++) {
			aux += icpf[i] * (10-i);
		}

		result1=aux%11;

		if (result1 == 0 || result1 == 1) {
			dig1 = 0;
		}
		else {
			dig1 = 11 - result1;
		}

		// SEGUNDO DIGITO.
		aux = 0; // Reseta o aux

		for (i=0; i<10; i++) {
			aux += icpf[i] * (11-i);
		}

		valor = (aux/11) * 11;
		result2 = aux - valor;

		if (result2 == 0 || result2 == 1) {
			dig2 = 0;
		}
		else {
			dig2 = 11 - result2;
		}

		// RESULTADOS DA VALIDAÇÃO.
		if (dig1 == icpf[9] && dig2 == icpf[10]) {
			return 1;
		}
		else {
			return 0;
		}
	}
}


void freeMemory(User* p) {
	free(p);
}