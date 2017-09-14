#include <stdio.h>
#include <stdlib.h>

// ASSINATURAS
void Logo(void);
void mPrincipal(void);
void mCadastramento(void);
void mLocacao(void);
void mVeiculos(void);
void mHistoricos(void);
void Indisponivel(void);
// FIM

int op;

void main(void) {
	int menu, op;

	while (menu != 0) {
		system("clear");
		Logo();
		mPrincipal();
		printf("\nInforme uma opção acima: ");
		scanf("%d", &op);

		if (op == 1) {
			system("clear");
			mCadastramento();
		}
		else if (op == 2) {
			system("clear");
			mLocacao();
		}
		else if (op == 3) {
			system("clear");
			mVeiculos();
		}
		else if (op == 4) {
			system("clear");
			mHistoricos();
		}
		else if (op == 0) {
			printf("Aperte ENTER para sair...\n");
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
}

void Logo(void) {
	printf("*********************************\n");
	printf("**          cRentAcar          **\n");
	printf("*********************************\n");
}

void mPrincipal(void) {
	printf("\n*********************************\n");
	printf("**       MENU PRINCIPAL        **\n");
	printf("** [1] - MENU DE CADASTRAMENTO **\n");
	printf("** [2] - MENU DE LOCAÇÃO       **\n");
	printf("** [3] - MENU DE VEÍCULOS      **\n");
	printf("** [4] - MENU DE HISTÓRICOS    **\n");
	printf("**                             **\n");
	printf("** [0] - SAIR                  **\n");
	printf("*********************************\n");
}

void mCadastramento(void) {
	printf("\n**********************************\n");
	printf("**    MENU DE CADASTRAMENTO     **\n");
	printf("** [1] - CADASTRAR NOVO CLIENTE **\n");
	printf("** [2] - CONSULTAR CLIENTE      **\n");
	printf("** [3] - ATUALIZAR CADASTRO     **\n");
	printf("** [4] - EXCLUIR CADASTRO       **\n");
	printf("**                              **\n");
	printf("** [0] - VOLTAR                 **\n");
	printf("**********************************\n");
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

void mVeiculos(void) {
	printf("\n******************************\n");
	printf("**     MENU DE VEÍCULOS     **\n");
	printf("** [1] - CADASTRAR VEÍCULO  **\n");
	printf("** [2] - EDITAR VEÍCULO     **\n");
	printf("** [3] - EXCLUIR VEÍCULO    **\n");
	printf("**                          **\n");
	printf("** [0] - VOLTAR             **\n");
	printf("******************************\n");
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

void mHistoricos(void) {
	printf("\n**********************************\n");
	printf("**      MENU DE HISTÓRICOS      **\n");
	printf("** [1] - VEÍCULOS MAIS LOCADOS  **\n");
	printf("** [2] - MELHORES CLIENTES      **\n");
	printf("** [3] - CONSULTAR LUCROS       **\n");
	printf("**                              **\n");
	printf("** [0] - VOLTAR                 **\n");
	printf("**********************************\n");
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
