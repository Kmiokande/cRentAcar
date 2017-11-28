#include "user/user.h"
#include "car/car.h"
#include <stdio.h>
#include <stdlib.h>

#define clear "\e[1;1H\e[2J" // PARÂMETRO PARA LIMPAR TELA

// ASSINATURAS
void Logo(void);
void logoExit();
void mPrincipal(void);
void mCadastramento();
void mLocacao(void);
void mVeiculos();
void mHistoricos(void);
void Indisponivel(void);
// FIM

User *DataUser;
Car *DataCar;

int main() {
    User *DataUser = (User *) NULL;
    Car *DataCar = (Car *) NULL;
//    loadUser(DataUser);

	int op = 10;

	while (op != 0) {
		printf(clear);
		Logo();
		mPrincipal(); // MENU PRINCIPAL
		printf("\nInforme uma opção acima: ");
		scanf("%d", &op);

		if (op == 1) {
			printf(clear);
			mCadastramento(); // MENU DE CADASTRAMENTO
		}
		else if (op == 2) {
			printf(clear);
			mLocacao(); // MENU DE LOCAÇÃO
		}
		else if (op == 3) {
			printf(clear);
			mVeiculos(); // MENU DE VEICULOS
		}
		else if (op == 4) {
			printf(clear);
			mHistoricos(); // MENU DE HISTÓRICOS
		}
		else if (op == 0) {
			printf(clear);
			printf("// Projeto disponível no Github!\n >> UFRN - BSI 2017.2\n\n - João Eudes\n - Bruno\n\n");
			logoExit();
			printf("\n\n\n [ Aperte ENTER para sair... ] \n");
        	while (getchar() != '\n');
            	getchar();
			break;
		}
		else {
			printf("Opção inválida!\n");
			printf("Aperte ENTER para voltar...\n");
			while (getchar() != '\n');
            	getchar();
		}
	}

	return 0;
}

void Logo(void) {
	printf("*********************************\n");
	printf("**          cRentAcar          **\n");
	printf("*********************************\n");
}

void logoExit() {	
	printf(" .d8888b.  8888888b.                   888     .d8888b.						\n");
	printf("d88P  Y88b 888   Y88b                  888    d88P  Y88b 					\n");
	printf("888    888 888    888                  888    888    888 					\n"); 
	printf("888        888   d88P .d88b.  88888b.  888888 888         8888b.  888d888	\n");
	printf("888        8888888P' d8P  Y8b 888 '88b 888    888            '88b 888P' 	\n");
	printf("888    888 888 T88b  88888888 888  888 888    888    888 .d888888 888		\n");   
	printf("Y88b  d88P 888  T88b Y8b.     888  888 Y88b.  Y88b  d88P 888  888 888		\n");  
	printf(" 'Y8888P'  888   T88b 'Y8888  888  888  'Y888  'Y8888P'  'Y888888 888	  \n\n"); 
}

void mPrincipal(void) {
	printf("\n*********************************\n");
	printf("**       MENU PRINCIPAL        **\n");
    printf("** [1] - MENU DE CLIENTE       **\n");
	printf("** [2] - MENU DE LOCAÇÃO       **\n");
	printf("** [3] - MENU DE VEÍCULOS      **\n");
	printf("** [4] - MENU DE HISTÓRICOS    **\n");
	printf("**                             **\n");
	printf("** [0] - SAIR                  **\n");
	printf("*********************************\n");
}

void mCadastramento() {
	printf("\n**********************************\n");
    printf("**    MENU DE CLIENTE           **\n");
	printf("** [1] - CADASTRAR NOVO CLIENTE **\n");
	printf("** [2] - CONSULTAR CLIENTE      **\n");
	printf("** [3] - MOSTRAR CADASTROS      **\n");
	printf("** [4] - ATUALIZAR CADASTRO     **\n");
	printf("** [5] - EXCLUIR CADASTRO       **\n");
	printf("**                              **\n");
	printf("** [0] - VOLTAR                 **\n");
	printf("**********************************\n");

	int op;
	printf("\nInforme uma opção acima: ");
	scanf("%d", &op);

	if (op == 1) {
		singUpUser(&DataUser);
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 2) {
		searchUser(DataUser);
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 3) {
		listUser(DataUser);
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 4) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 5) {
		removeUser(DataUser);
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 0) {
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else {
		printf("Opção inválida!\n");
		printf("Aperte ENTER para voltar...\n");
		while (getchar() != '\n');
            getchar();
	}
}

void mLocacao(void) {
	printf("\n*******************************************************\n");
	printf("**                  MENU DE LOCAÇÃO                  **\n");
	printf("** [1] - ALUGAR VEÍCULO                              **\n");
	printf("** [2] - DEVOLUÇÃO DE VEÍCULO                        **\n");
	printf("** [3] - CONSULTAR VEÍCULOS DISPONÍVEIS              **\n");
	printf("** [4] - CONSULTAR REGISTRO DE EMPRÉSTIMOS EFETUADOS **\n");
	printf("**                                                   **\n");
	printf("** [0] - VOLTAR                                      **\n");
	printf("*******************************************************\n");

	int op;
	printf("\nInforme uma opção acima: ");
	scanf("%d", &op);
	if (op == 1) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 2) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 3) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 4) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 0) {
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else {
		printf("Opção inválida!\n");
		printf("Aperte ENTER para voltar...\n");
		while (getchar() != '\n');
            getchar();
	}
}

void mVeiculos() {
	printf("\n******************************\n");
	printf("**     MENU DE VEÍCULOS     **\n");
	printf("** [1] - CADASTRAR VEÍCULO  **\n");
	printf("** [2] - CONSULTAR VEÍCULO  **\n");
	printf("** [3] - MOSTRAR VEÍCULOS   **\n");
	printf("** [4] - EDITAR VEÍCULO     **\n");
	printf("** [5] - EXCLUIR VEÍCULO    **\n");
	printf("**                          **\n");
	printf("** [0] - VOLTAR             **\n");
	printf("******************************\n");

	int op;
	printf("\nInforme uma opção acima: ");
	scanf("%d", &op);
	if (op == 1) {
		singUpCar(&DataCar);	
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 2) {
		searchCar(DataCar);
		
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 3) {
		listCar(DataCar);
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 4) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 0) {
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else {
		printf("Opção inválida!\n");
		printf("Aperte ENTER para voltar...\n");
		while (getchar() != '\n');
            getchar();
	}
}

void mHistoricos(void) {
	printf("\n**********************************\n");
	printf("**      MENU DE HISTÓRICOS      **\n");
	printf("** [1] - VEÍCULOS MAIS LOCADOS  **\n");
	printf("** [2] - MELHORES CLIENTES      **\n");
	printf("** [3] - CONSULTAR LUCROS       **\n");
	printf("**                              **\n");
	printf("** [0] - VOLTAR                 **\n");
	printf("**********************************\n");

	int op;
	printf("\nInforme uma opção acima: ");
	scanf("%d", &op);
	if (op == 1) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 2) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 3) {
		Indisponivel();
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else if (op == 0) {
		printf("Aperte ENTER para voltar...\n");
        while (getchar() != '\n');
            getchar();
	}
	else {
		printf("Opção inválida!\n");
		printf("Aperte ENTER para voltar...\n");
		while (getchar() != '\n');
            getchar();
	}
}

void Indisponivel(void) {
	printf("OPÇÃO INDISPONÍVEL!!!\n");
}
