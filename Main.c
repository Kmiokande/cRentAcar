#include <stdio.h>
#include <stdlib.h>

#define clear "\e[1;1H\e[2J" // PARÂMETRO PARA LIMPAR TELA

// ASSINATURAS
void Logo(void);
void mPrincipal(void);
void mCadastramento(void);
void mLocacao(void);
void mVeiculos(void);
void mHistoricos(void);
void Indisponivel(void);
// FIM

int main() {
	int op = 10;
	user * DataUser = NULL; // Cria a Lista encadeada
	

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
			printf("clear");
			mHistoricos(); // MENU DE HISTÓRICOS
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

	return 0;
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

void mVeiculos(void) {
	printf("\n******************************\n");
	printf("**     MENU DE VEÍCULOS     **\n");
	printf("** [1] - CADASTRAR VEÍCULO  **\n");
	printf("** [2] - EDITAR VEÍCULO     **\n");
	printf("** [3] - EXCLUIR VEÍCULO    **\n");
	printf("**                          **\n");
	printf("** [0] - VOLTAR             **\n");
	printf("******************************\n");

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
