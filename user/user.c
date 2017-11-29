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
    } while (validatorGlobal(_newUser->nome, 'S', 4));

    do {
        printf("Sobrenome: ");
        scanf(" %49[^\n]", _newUser->sobrenome);
    } while (validatorGlobal(_newUser->sobrenome, 'S', 4));

    //do {
    printf("Data de Nascimento: ");
    scanf(" %11[^\n]", _newUser->data_nascimento);
    //} while (valDate(_newUser->data_nascimento));

    do {
        printf("CPF: ");
        scanf(" %11[^\n]", _newUser->cpf);
    } while (valCPF(_newUser->cpf));

    do {
        printf("Nome completo da Mãe: ");
        scanf(" %49[^\n]", _newUser->nome_mae);
    } while (validatorGlobal(_newUser->nome_mae, 'S', 4));


    printf("RG: ");
    scanf(" %49[^\n]", _newUser->rg);

    do {
        printf("Endereço [Sigla do Estado]: ");
        scanf(" %2[^\n]", _newUser->endereco.sigla_estado);
    } while (validatorGlobal(_newUser->endereco.sigla_estado, 'S', 2));

    do {
        printf("Endereço [Cidade]:");
        scanf(" %50[^\n]", _newUser->endereco.cidade);
    } while (validatorGlobal(_newUser->endereco.cidade, 'S', 3));

    do {
        printf("Endereço [Rua]:");
        scanf(" %50[^\n]", _newUser->endereco.rua);
    } while (validatorGlobal(_newUser->endereco.rua, 'S', 3));

    printf("Endereço [Número]: ");
    scanf(" %d", &_newUser->endereco.numero);

    do {
        printf("Endereço [Bairro]:");
        scanf(" %49[^\n]", _newUser->endereco.bairro);
    } while (validatorGlobal(_newUser->endereco.bairro, 'S', 3));

    printf("CNH: ");
    scanf(" %49[^\n]", _newUser->cnh);

    printf("Email: ");
    scanf(" %49[^\n]", _newUser->rg);

    printf("Telefone: ");
    scanf(" %49[^\n]", _newUser->fone);

    _newUser->proxUser = *DataUser;
    *DataUser = _newUser;
    saveUser(*DataUser);
}

// [ Ver todos os Usuários cadastrados ]
void listUser(User *DataUser) {
    User *aux = NULL;
    for (aux = DataUser; aux != NULL; aux = aux->proxUser) {
        printf("Nome: %s %s\n", aux->nome, aux->sobrenome);
        printf("Data de Nascimento: %s\n", aux->data_nascimento);
        printf("CPF: %s\n", aux->cpf);
        printf("-------------------\n");
    }
}

// [ Verifica se existe o cpf cadastrado ]
int searchUser(User *DataUser) {
    char cpf[12];
    printf("Informe o CPF: ");
    scanf(" %11[^\n]", cpf);

    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (strcmp(aux->cpf, cpf) == 0) { // Se o cpf for igual ao cadastrado ele retorna 0
            printf("%s\n", aux->nome);
            printf("%s\n", aux->sobrenome);
            return False();
        }
    }
    printf("Cliente não cadastrado\n");
    return True(); // Não encontrou o elemento
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
                        printf("Endereço [Cidade]:");
                        scanf(" %50[^\n]", aux->endereco.cidade);
                    } while (validatorGlobal(aux->endereco.cidade, 'S', 3));

                    do {
                        printf("Endereço [Rua]:");
                        scanf(" %50[^\n]", aux->endereco.rua);
                    } while (validatorGlobal(aux->endereco.rua, 'S', 3));

                    printf("Endereço [Número]: ");
                    scanf(" %d", &aux->endereco.numero);

                    do {
                        printf("Endereço [Bairro]:");
                        scanf(" %49[^\n]", aux->endereco.bairro);
                    } while (validatorGlobal(aux->endereco.bairro, 'S', 3));
                    break;
                case 4:
                    printf("Email: ");
                    scanf(" %49[^\n]", aux->rg);
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
        printf("\n\tPassou!\n");
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

            for (i = 0; i < j; i++) {
                aux += (cpf[i] - 48) * ((j + 1) - i);
            }

            dig = aux % 11;
            dig = (dig < 2 ? 0 : 11 - dig);

            if ((cpf[j] - 48) != dig) {
                printf("\n >> CPF inválido! \n");
                return False();
            }
        }

        // RESULTADOS DA VALIDAÇÃO.
        return True();
    }
    printf("CPF Inválido!\n");
    return False();
}

// [ Valida Nome e Sobrenome ]
int valName(char name[50]) {
    int comp = (int) strlen(name);
    if (comp > 4) {
        for (int i = 0; name[i] != '\0'; i++) {
            if (name[i] >= 33 && name[i] <= 45 || name[i] >= 47 && name[i] <= 64) {
                printf("\n >> Nome inválido! \n");
                return False();
            }
        }

        return True();
    }
    return False();
}


// [ Validar Data ]
int valData(char data[12]) { // [-] Aceitar apenas 18 anos acima
    if (strlen(data) == 11) {
        for (int i = 0; data[i] != '\0'; ++i) {
            if (i < 2) {
                if (!(data[i] >= 48 && data[i] <= 57)) {
                    printf("Placa Inválida\n");
                    return False();
                }
            }
            if (i > 3 && i < 6) {}
        }
        return True();

    } else {
        return False();
    }

}

// [ I/O dos dados e memoria ]

void saveUser(User *Data) {
    FILE *file = fopen("user/user.dat", "w+");
    if (!file) {
        printf("Houve um erro ao abrir o arquivo.\n");
    } else {
        fseek(file, 0, SEEK_SET);
        for (User *aux = Data; aux != NULL; aux = aux->proxUser) {
            fwrite(aux, sizeof(User), 1, file);
        }
        fclose(file);

    }
}

void loadUser(User *Data) {
    FILE *file = fopen("user/user.dat", "rb+");
    if (!file) {
        printf("Houve um erro ao abrir o arquivo.\n");
    } else {
        fseek(file, 0, SEEK_SET);
        fread(&Data, sizeof(User), 1, file);
        fclose(file);

    }
}