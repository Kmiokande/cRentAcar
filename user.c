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
