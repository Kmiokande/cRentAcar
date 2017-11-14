#include <stdlib.h>
#include <time.h>

#include "user.h"

struct {
	char nome[50];
	char sobrenome[50];
	char data_nascimento[20];
	char cpf[20];
	char nome_mae[80];
	char rg[20];
	char email[80];
	char CNH[20];
	char endereco[120];
	char fone[15];
} user[200];

void saveDataUser(char *array) {
	FILE *file = fopen("user.dat", "wb"); // Substitui todo o texto já existente
	fwrite(user, sizeof(char), sizeof(user), file);
	fclose(file);
}

// Validação de CPF
void valCPF(char cpf[11], int icpf[11]) {
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
			printf("\nCPF válido.\n");
		}
		else {
			printf("\nCPF inválido.\n");
		}
	}
}