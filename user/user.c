#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "../functions.h"

// >> [ CRUD ]

// [ Cadastrar usuário ]
void singUpUser(User **DataUser) {
    User *_newUser = (User *) malloc(sizeof(User));

    do {
        printf("Nome: ");
        scanf(" %49[^\n]", _newUser->nome);
    } while (!validatorGlobal(_newUser->nome, 'S', 4));

    do {
        printf("Sobrenome: ");
        scanf(" %49[^\n]", _newUser->sobrenome);
    } while (!validatorGlobal(_newUser->sobrenome, 'S', 4));

    do {
    printf("Data de Nascimento: ");
    scanf(" %10[^\n]", _newUser->data_nascimento);
    } while (!valData(_newUser->data_nascimento));

    do {
        printf("CPF: ");
        scanf(" %11[^\n]", _newUser->cpf);
    } while (!valCPF(_newUser->cpf));

    do {
        printf("Nome completo da Mãe: ");
        scanf(" %49[^\n]", _newUser->nome_mae);
    } while (!validatorGlobal(_newUser->nome_mae, 'S', 4));


    printf("RG: ");
    scanf(" %49[^\n]", _newUser->rg);

    do {
        printf("Endereço [Sigla do Estado]: ");
        scanf(" %2[^\n]", _newUser->endereco.sigla_estado);
    } while (!validatorGlobal(_newUser->endereco.sigla_estado, 'S', 2));

    do {
        printf("Endereço [Cidade]: ");
        scanf(" %50[^\n]", _newUser->endereco.cidade);
    } while (!validatorGlobal(_newUser->endereco.cidade, 'S', 3));

    do {
        printf("Endereço [Rua]: ");
        scanf(" %50[^\n]", _newUser->endereco.rua);
    } while (!validatorGlobal(_newUser->endereco.rua, 'S', 3));

    printf("Endereço [Número]: ");
    scanf(" %d", &_newUser->endereco.numero);

    do {
        printf("Endereço [Bairro]:");
        scanf(" %49[^\n]", _newUser->endereco.bairro);
    } while (!validatorGlobal(_newUser->endereco.bairro, 'S', 3));

    printf("CNH: ");
    scanf(" %49[^\n]", _newUser->cnh);

    printf("Email: ");
    scanf(" %49[^\n]", _newUser->email);

    printf("Telefone: ");
    scanf(" %49[^\n]", _newUser->fone);

    _newUser->score = 0;

    _newUser->proxUser = *DataUser;
    *DataUser = _newUser;
    saveUser(*DataUser);
}

// [ Ver todos os Usuários cadastrados ]
void listUser(User *DataUser) {
    if (DataUser != NULL) {
        User *aux = NULL;
        for (aux = DataUser; aux != NULL; aux = aux->proxUser) {
            printf("\nNome: %s %s\n", aux->nome, aux->sobrenome);
            printf("Data de Nascimento: %s\n", aux->data_nascimento);
            printf("CPF: %s\n", aux->cpf);
            printf("Email: %s\n", aux->email);
            printf("Fone: %s\n", aux->fone);
            printf("-------------------\n");
        }
    } else {
        printf("\n\n>> Sem usuários cadastrados!\n");
    }
}

// [ Verifica se existe o cpf cadastrado ]
void searchUser(User *DataUser) {
    char cpf[12];
    printf("Informe o CPF: ");
    scanf(" %11[^\n]", cpf);

    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (strcmp(aux->cpf, cpf) == 0) { // Se o cpf for igual ao cadastrado ele retorna 0
            printf("%s\n", aux->nome);
            printf("%s\n", aux->sobrenome);
            return;
        }
    }
    printf("\n\n>> Cliente não encontrado cadastrados!\n"); // Não encontrou o elemento
}


// [ Verifica se existe o cpf cadastrado ]
void editUser(User *DataUser) {
    char cpf[12];
    printf("Informe o CPF: ");
    scanf(" %11[^\n]", cpf);

    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (strcmp(aux->cpf, cpf) == 0) { // Se o cpf existir ele retorna 0
            printf("O deseja editar?");
            printf("\n1 - Nome");
            printf("\n2 - Sobrenome");
            printf("\n3 - Endereço");
            printf("\n4 - Telefone");
            printf("\n5 - Email");
            printf("\nDígito da opção:");
            int op;
            scanf(" %1d", &op);
            switch (op) {
                case 1:
                    do {
                        printf("Nome: ");
                        scanf(" %49[^\n]", aux->nome);
                    } while (validatorGlobal(aux->nome, 'S', 4));
                    break;
                case 2:
                    do {
                        printf("Sobrenome: ");
                        scanf(" %49[^\n]", aux->sobrenome);
                    } while (validatorGlobal(aux->sobrenome, 'S', 4));
                    break;
                case 3:
                    do {
                        printf("Endereço [Sigla do Estado]: ");
                        scanf(" %2[^\n]", aux->endereco.sigla_estado);
                    } while (validatorGlobal(aux->endereco.sigla_estado, 'S', 2));

                    do {
                        printf("Endereço [Cidade]: ");
                        scanf(" %50[^\n]", aux->endereco.cidade);
                    } while (validatorGlobal(aux->endereco.cidade, 'S', 3));

                    do {
                        printf("Endereço [Rua]: ");
                        scanf(" %50[^\n]", aux->endereco.rua);
                    } while (validatorGlobal(aux->endereco.rua, 'S', 3));

                    printf("Endereço [Número]: ");
                    scanf(" %d", &aux->endereco.numero);

                    do {
                        printf("Endereço [Bairro]: ");
                        scanf(" %49[^\n]", aux->endereco.bairro);
                    } while (validatorGlobal(aux->endereco.bairro, 'S', 3));
                    break;
                case 4:
                    printf("Email: ");
                    scanf(" %49[^\n]", aux->email);
                    break;
                case 5:
                    printf("Telefone: ");
                    scanf(" %49[^\n]", aux->fone);
                    break;
                default:
                    printf("Opção Inválida!");
            }
        }
    }
    printf("Cliente não cadastrado\n");
}

// [ Deleta cadastro do usuario ] 
User *deleteUser(User *DataUser) {
    char cpf[12];
    printf("Informe o CPF:");
    scanf(" %11[^\n]", cpf);

    User *ant = NULL; // Ponteiro para elemento anterior
    User *p = DataUser; // Ponteiro para percorrer a lista
    // Procura elemento na lista guardando o anterior
    while (p != NULL && strcmp(p->cpf, cpf) != 0) {
        ant = p;
        p = p->proxUser;
    }
    if (p == NULL) // Verifica se achou o elemento
        printf("\n\tAchou o elemento\n");
    // Retira elemento
    if (ant == NULL) { // Retira o elemento do inicio da lista
        DataUser = p->proxUser;
        printf("\n\tRetirou o elemento do inicio da lista!\n");
    } else { // Retira o elemento do meio da lista
        ant->proxUser = p->proxUser;
        printf("\n\tRetirou o elemento do meio da lista!\n");
    }
    free(p); // Libera o elemento
    return DataUser;
}

// >> [ Validações ]
// [ Validação de CPF ]
int valCPF(char cpf[12]) {
    int i, comp, aux = 0, dig;
    comp = (int) strlen(cpf);  // Contagem da quantidade de caracteres no vetor.

    if (comp == 11 && cpf[1] != cpf[3] && cpf[2] != cpf[7]) { // Verifica se existe os 11 dígitos do CPF
        for (int j = 9; j <= 10; ++j) {
            aux = 0;

            for (i = 0; i < j; i++)
                aux += (cpf[i] - 48) * ((j + 1) - i);

            dig = aux % 11;
            dig = (dig < 2 ? 0 : 11 - dig);

            if ((cpf[j] - 48) != dig) {
                printf("\n >> CPF inválido! \n");
                return False;
            }
        }

        // RESULTADOS DA VALIDAÇÃO.
        return True;
    }
    printf(">> CPF Inválido!\n");
    return False;
}

// [ Valida Nome e Sobrenome ]
int valName(char name[50]) {
    int comp = (int) strlen(name);
    if (comp > 4) {
        for (int i = 0; name[i] != '\0'; i++) {
            if (name[i] >= 33 && name[i] <= 45 || name[i] >= 47 && name[i] <= 64) {
                printf("\n >> Nome inválido! Digite apenas letras \n");
                return False;
            }
        }

        return True;
    }
    return False;
}


// [ Validar Data ]
int valData(char data[11]) { // [-] Aceitar apenas 18 anos acima
    if (strlen(data) == 10) {
        for (int i = 0; data[i] != '\0'; ++i) {
            if (i < 2 || i > 2 && i < 5 || i > 5 && i < 10) {
                if (!(data[i] >= 48 && data[i] <= 57)) {
                    printf("Data inválida! Digite no formato: dd/mm/aaaa\n");
                    return False;
                }
            }
        }
        return True;

    } else {
        printf("Data inválida! Digite no formato: dd/mm/aaaa\n");
        return False;
    }

}


int checkExistUser(char cpf[12], User *DataUser) {
    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (strcmp(aux->cpf, cpf) == 0) { // Se o cpf for igual ao cadastrado ele retorna 0
            return True;
        }
    }
    return False;
}

// [ I/O dos dados e memoria ]
void saveUser(User *DataUser) {
    FILE *file = fopen("user/user.dat", "w+");
    if (file == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    } else {
        for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
            fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%d|%s|%s|%s|%s|%d|\n", aux->nome, aux->sobrenome, aux->data_nascimento, aux->cpf, aux->nome_mae, aux->rg, aux->endereco.sigla_estado, aux->endereco.cidade, aux->endereco.rua, aux->endereco.numero, aux->endereco.bairro, aux->cnh, aux->email, aux->fone, aux->score);
        }
        fclose(file);
    }
}

User *loadUser(User *DataUser) {
    FILE *file = fopen("user/user.dat", "r");

    char nome[50];
    char sobrenome[50];
    char data_nascimento[12];
    char cpf[12];
    char nome_mae[80];
    char rg[20];
    char sigla_estado[3];
    char cidade[51];
    char rua[51];
    int numero;
    char bairro[31];
    char cnh[20];
    char email[80];
    char fone[15];
    int score;

    if (file == NULL) {
        printf("Erro, não foi possivel abrir o arquivo\n");
    } else {
        while (fscanf(file, "%49[^|]|%49[^|]|%11[^|]|%11[^|]|%79[^|]|%19[^|]|%2[^|]|%50[^|]|%50[^|]|%d|%30[^|]|%19[^|]|%79[^|]|%14[^|]|%d|\n", nome, sobrenome, data_nascimento, cpf, nome_mae, rg, sigla_estado, cidade, rua, &numero, bairro, cnh, email, fone, &score) != EOF) {
            User *_newUser = (User *) malloc(sizeof(User));

            if (nome[0] >= 33) {
                strcpy(_newUser->nome, nome);
                strcpy(_newUser->sobrenome, sobrenome);
                strcpy(_newUser->data_nascimento, data_nascimento);
                strcpy(_newUser->cpf, cpf);
                strcpy(_newUser->nome_mae, nome_mae);
                strcpy(_newUser->rg, rg);
                strcpy(_newUser->endereco.sigla_estado, sigla_estado);
                strcpy(_newUser->endereco.cidade, cidade);
                strcpy(_newUser->endereco.rua, rua);
                _newUser->endereco.numero = numero;
                strcpy(_newUser->endereco.bairro, bairro);
                strcpy(_newUser->cnh, cnh);
                strcpy(_newUser->email, email);
                strcpy(_newUser->fone, fone);

                _newUser->proxUser = DataUser;
                DataUser = _newUser;
            }
        }
    }
    fclose(file);
    return DataUser;
}
