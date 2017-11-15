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
	char cpf[12];
	char nome_mae[80];
	char rg[20];
	char email[80];
	char cnh[20];
	struct end endereco;
	char fone[15];
	struct user* proxUser;
} User;

User* createList() {
  return NULL;
}

// Cadastrar usuário
User* singUp(User* DataUser) {
	User* _newUser = (User*) malloc(sizeof(User));
	_newUser->proxUser = DataUser;

	if (_newUser != NULL) {

		printf("Nome: ");
		scanf(" %49[^\n]", _newUser->nome);

		printf("Sobrenome: ");
		scanf(" %49[^\n]", _newUser->sobrenome);

		printf("Data de Nascimento: ");
		scanf(" %49[^\n]", _newUser->data_nascimento);

		while(valCPF(_newUser)) {
			printf("CPF: ");
			scanf(" %11[^\n]", _newUser->cpf);
		}

		printf("Nome da Mãe: ");
		scanf(" %49[^\n]", _newUser->nome_mae);

		printf("RG: ");
		scanf(" %49[^\n]", _newUser->rg);

		printf("Email: ");
		scanf(" %49[^\n]", _newUser->rg);

		printf("Endereço [Sigla do Estado]:");
		scanf(" %49[^\n]", _newUser->endereco.sigla_estado);

		printf("Endereço [Cidade]:");
		scanf(" %49[^\n]", _newUser->endereco.cidade);

		printf("Endereço [Rua]:");
		scanf(" %49[^\n]", _newUser->endereco.rua);

		printf("Endereço [Número]:");
		scanf("%d", _newUser->endereco.numero);

		printf("Endereço [Bairro]:");
		scanf(" %49[^\n]", _newUser->endereco.bairro);

		printf("CNH: ");
		scanf(" %49[^\n]", _newUser->cnh);

		printf("Telefone: ");
		scanf(" %49[^\n]", _newUser->fone);
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
int valCPF(char cpf[12]) {
	int i, comp, aux = 0, dig1, dig2, result1, result2, valor;

	// Faz a contagem de quantos caracteres possui no vetor.
	comp = strlen(cpf);

	// Se na condição o CPF não possuir 11 digitos apresenta erro, caso contrario inicia a verificação dos dois ultimos digitos.
	if (comp != 11) {
		return 1;
	}
	else {

		// Efetua a conversao do vetor de tipo char para um vetor de tipo int usando tabela ASCII.
		for (i=0; i<11; i++) {
			cpf[i] -= 48;
		}

		// PRIMEIRO DIGITO.
		for (i=0; i<9; i++) {
			aux += cpf[i] * (10-i);
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
			aux += cpf[i] * (11-i);
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
		if (dig1 == cpf[9] && dig2 == cpf[10]) {
			return 0;
		}
		else {
			return 1;
		}
	}
}

// Valida nome
int valName(char name[50]) {
	int i;
	for(i=0; name[i]!='\0'; i++) {
		if(name[i] >= 33 && name[i] <= 45 && name[i] >= 47 && name[i] <= 64)
			return 1; // False
	}
	return 0; // True
}

void freeMemory(User* p) {
	free(p);
}