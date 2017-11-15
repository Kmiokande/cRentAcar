#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "user.h"

User createUser() {
	printf("Nome: ");
	scanf("%49[^\n]s", _User.nome);

	printf("Sobrenome: ");
	scanf("%49[^\n]s", _User.sobrenome);

	printf("Data de Nascimento: ");
	scanf("%49[^\n]s", _User.nome);

	printf("CPF: ");
	scanf("%49[^\n]s", _User.cpf);

	printf("Nome da Mãe: ");
	scanf("%49[^\n]s", _User.nome_mae);

	printf("RG: ");
	scanf("%49[^\n]s", _User.rg);

	printf("Email: ");
  	scanf("%49[^\n]s", _User.rg);

	printf("Endereço [Sigla do Estado]:");
	scanf("%49[^\n]s", _User.endereco.sigla_estado);

	printf("Endereço [Cidade]:");
	scanf("%49[^\n]s", _User.endereco.cidade);

	printf("Endereço [Rua]:");
	scanf("%49[^\n]s", _User.endereco.rua);

	printf("Endereço [Número]:");
	scanf("%49[^\n]s", _User.endereco.numero);

	printf("Endereço [Bairro]:");
	scanf("%49[^\n]s", _User.endereco.bairro);

	printf("CNH: ");
	scanf("%49[^\n]s", _User.cnh);

	printf("Telefone: ");
	scanf("%49[^\n]s", _User.telefone);

}

void saveDataUser(char *array) {
	FILE *file = fopen("user.dat", "wb"); // Substitui todo o texto já existente
	fwrite(user, sizeof(char), sizeof(user), file);
	fclose(file);
}

// Validação de CPF
int valCPF(char cpf[11]) {
	int i, comp, aux = 0, dig1, dig2, result1, result2, valor;

	// Faz a contagem de quantos caracteres possui no vetor.
	comp = strlen(cpf);

	// Se na condição o CPF não possuir 11 digitos apresenta erro, caso contrario inicia a verificação dos dois ultimos digitos.
	if (comp != 11) {
		return 0;
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
			return 1;
		}
		else {
			return 0;
		}
	}
}
