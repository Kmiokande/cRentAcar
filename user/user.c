#include "user.h"

// >> 1. [ CRUD ]
// 1.1 - Cadastrar Usuário/cliente -> Salvar na lista encadeada -> Salvar no arquivo user.dat [x]
// 1.2 - Editar Usuário/cliente -> Refactor na lista encadeada -> Salvar no arquivo user.data [x]
// 1.3 - Remover Usuário/cliente -> Refactor na lista encadeada -> Salvar no arquivo user.dat [x]
// 1.4 - Listar Usuários/CLiente

// 1.1 - [ Cadastrar Usuário ]
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
        printf("Data de Nascimento [xx/xx/xxxx]: ");
        scanf(" %10[^\n]", _newUser->data_nascimento);
    } while (!valData(_newUser->data_nascimento));

    do {
        printf("CPF [xxxxxxxxxxx](11): ");
        scanf(" %11[^\n]", _newUser->cpf);
    } while (!valCPF(_newUser->cpf));

    do {
        printf("Nome completo da Mãe: ");
        scanf(" %79[^\n]", _newUser->nome_mae);
    } while (!validatorGlobal(_newUser->nome_mae, 'S', 4));

    do {
        printf("RG [xxxxxxxxx](9): ");
        scanf(" %9[^\n]", _newUser->rg);
    } while (!validatorGlobal(_newUser->rg, 'N', 9));

    do {
        printf("Endereço [Sigla do Estado][XX](2): ");
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

    do {
        printf("Endereço [Número]: ");
        scanf(" %5[^\n]", _newUser->endereco.numero);
    } while (!validatorGlobal(_newUser->endereco.numero, 'N', 1));

    do {
        printf("Endereço [Bairro]:");
        scanf(" %30[^\n]", _newUser->endereco.bairro);
    } while (!validatorGlobal(_newUser->endereco.bairro, 'S', 3));

    do {
        printf("CNH [xxxxxxxxxxx](11): ");
        scanf(" %11[^\n]", _newUser->cnh);
    } while (!validatorGlobal(_newUser->cnh, 'N', 11));

    do {
        printf("Email: ");
        scanf(" %49[^\n]", _newUser->email);
    } while (!valEmail(_newUser->email));

    do {
        printf("Telefone: [(xx)xxxxx-xxxx]");
        scanf(" %14[^\n]", _newUser->fone);
    } while (valTelefone(_newUser->fone));

    _newUser->score = 0;

    _newUser->proxUser = *DataUser;
    *DataUser = _newUser;
    saveUser(*DataUser);
}

// 1.2 - [ Edita Cliente pelo CPF  ]
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
            printf("\n6 - CPF");
            printf("\nDígito da opção:");
            int op;
            scanf(" %1d", &op);
            switch (op) {
                case 1:
                    do {
                        printf("Nome: ");
                        scanf(" %49[^\n]", aux->nome);
                    } while (!validatorGlobal(aux->nome, 'S', 4));
                    break;
                case 2:
                    do {
                        printf("Sobrenome: ");
                        scanf(" %49[^\n]", aux->sobrenome);
                    } while (!validatorGlobal(aux->sobrenome, 'S', 4));
                    break;
                case 3:
                    do {
                        printf("Endereço [Sigla do Estado][XX](2): ");
                        scanf(" %2[^\n]", aux->endereco.sigla_estado);
                    } while (!validatorGlobal(aux->endereco.sigla_estado, 'S', 2));

                    do {
                        printf("Endereço [Cidade]: ");
                        scanf(" %50[^\n]", aux->endereco.cidade);
                    } while (!validatorGlobal(aux->endereco.cidade, 'S', 3));

                    do {
                        printf("Endereço [Rua]: ");
                        scanf(" %50[^\n]", aux->endereco.rua);
                    } while (!validatorGlobal(aux->endereco.rua, 'S', 3));

                    do {
                        printf("Endereço [Número]: ");
                        scanf(" %5[^\n]", aux->endereco.numero);
                    } while (!validatorGlobal(aux->endereco.numero, 'N', 5));

                    do {
                        printf("Endereço [Bairro]:");
                        scanf(" %30[^\n]", aux->endereco.bairro);
                    } while (!validatorGlobal(aux->endereco.bairro, 'S', 3));

                    break;
                case 4:
                    do {
                        printf("Email: ");
                        scanf(" %49[^\n]", aux->email);
                    } while (!valEmail(aux->email));

                    break;
                case 5:
                    do {
                        printf("Telefone: [(xx)xxxxx-xxxx]");
                        scanf(" %14[^\n]", aux->fone);
                    } while (valTelefone(aux->fone));
                    break;
                case 6:
                    do {
                        printf("CPF [xxxxxxxxxxx](11): ");
                        scanf(" %11[^\n]", aux->cpf);
                    } while (!valCPF(aux->cpf));
                    break;
                default:
                    printf("Opção Inválida!");
            }
        }
    }
    printf("Cliente não cadastrado\n");
}

// 1.3 - [ Deleta cadastro do cliente pelo CPF ] 
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
        return DataUser; // Não achou retorna a lista original
    // Retira elemento
    if (ant == NULL) { // Retira o elemento do inicio da lista
        DataUser = p->proxUser;
        printf("\n\tCadastro excluído com sucesso.\n");
    } else { // Retira o elemento do meio da lista
        ant->proxUser = p->proxUser;
        printf("\n\tCadastro excluído com sucesso.\n");
    }
    free(p); // Libera o elemento
    return DataUser;
}

// 1.4 - [ Ver todos os Usuários cadastrados ]
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

// >> 2. [ Validações ]
// 2.1 - Validação Nome e Sobrenome do usuário [x] [Usando ValidorGlobal]
// 2.2 - Validação data de Nascimento [x] (xx/xx/xx)
// 2.3 - Validação CPF [x] (xxx.xxx.xxx-xx)
// 2.4 - Valida Nome da mãe [x] [Usando ValidorGlobal]
// 2.5 - Validação Rg [x] (xxxxxxxxx[9])
// 2.6 - Endereços [x]
// 2.6.1 - Sigla [x] (XX)           [Usando ValidorGlobal]
// 2.6.2 - Cidade [x]               [Usando ValidorGlobal]
// 2.6.3 - Rua [x]                  [Usando ValidorGlobal]
// 2.6.4 - Número [x]
// 2.6.5 - Bairro [x]               [Usando ValidorGlobal]
// 2.7 - Validação CNH [x] (xxxxxxxxxxx[11])  [Usando ValidorGlobal]
// 2.8 - Validação Email [x] (*@*.*)
// 2.9 - Validação número de telefone [x] ((xx)xxxxx-xxxx)

// 2.2 - [ Validação Data ] [-] Aceitar apenas 18 anos acima (xx/xx/xxxx)
int valData(const char data[11]) {

    if (strlen(data) == 10) {
        for (int i = 0; data[i] != '\0'; ++i) {
            if ((i < 2) || (i > 2 && i < 5) || (i > 5 && i < 10)) {
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


// 2.3 - [ Validação de CPF ]
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

// 2.8 - [ Validação Email ]
int valEmail(char email[80]) {
    if (strlen(email) >= 8) {
        int v = 0;
        int a = 0;
        for (int i = 0; email[i] != '\0'; ++i) {
            if (email[i] == '@') {
                v++;
                a++;
            } else if (email[i] == '.') {
                v++;
            } else if (v == 2 && a == 1) {
                return True;
            }
        }
    }
    return False;
}

int valTelefone(char fone[15]) {
    int s = 0;
    int n = 0;
    for (int i = 0; fone[i] != '\0'; ++i) {
        if ((i == 0) || (i == 3)) {
            if ((fone[i] == '(') || (fone[i] == ')')) {
                s++;
            }
        } else if (isDigit(fone[i])) {
            n++;
        } else if (s == 2 && n == 11) {
            return True;
        }
    }
    return False;

}

// >> 3. [ Outros ]
// 3.1 - Checar se o CPF existe no sistema [x]
// 3.2 - Procura cliente pelo CPF [x]
// 3.3 - Incrementar Score [x]

// 3.1 - [ Checar se o CPF existe no sistema ]
int checkExistUser(char cpf[12], User *DataUser) {
    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (!strcmp(aux->cpf, cpf)) { // [STRCMP] Retorna 0 se o cpf for igual
            return True;
        }
    }
    printf("CPF não encontrado ou não cadastrado!\n");
    return False;
}

// 3.2 - [ Procura cliente pelo CPF ]
void searchUser(User *DataUser) {
    char cpf[12];
    printf("Informe o CPF: ");
    scanf(" %11[^\n]", cpf);

    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (!strcmp(aux->cpf, cpf)) { // [STRCMP] Retorna 0 se o cpf for igual
            printf("%s\n", aux->nome);
            printf("%s\n", aux->sobrenome);
            return;
        }
    }
    printf("\n\n>> Cliente não encontrado cadastrados!\n"); // Não encontrou o elemento
}

void incrementScore(User *DataUser, char cpf[11]) {
    for (User *user = DataUser; user != NULL; user = user->proxUser) {
        if (strcmp(user->cpf, cpf) == 0) {
            user->score++;
            break;
        }
    }

}

// >> 4. [ I/O dos dados e memoria ]
// 4.1 - Salvar lista encadeada de DataUser(clientes) no arq. User.dat [x]
// 4.2 - Carregar lista encadeada de DataUser(clientes) do arq. User.dat [x]

// 4.1 - [ Salvar lista encadeada de DataUser(clientes) no arq. User.dat ]
void saveUser(User *DataUser) {
    FILE *file = fopen("user/user.dat", "w+");
    if (file == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    } else {
        for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
            fprintf(file, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%d|\n", aux->nome, aux->sobrenome,
                    aux->data_nascimento, aux->cpf, aux->nome_mae, aux->rg, aux->endereco.sigla_estado,
                    aux->endereco.cidade, aux->endereco.rua, aux->endereco.numero, aux->endereco.bairro, aux->cnh,
                    aux->email, aux->fone, aux->score);
        }
        fclose(file);
    }
}

// 4.2 - [ Carregar lista encadeada de DataUser(clientes) do arq. User.dat ]
User *loadUser(User *DataUser) {
    FILE *file = fopen("user/user.dat", "a+");

    char nome[50];
    char sobrenome[50];
    char data_nascimento[11];
    char cpf[12];
    char nome_mae[80];
    char rg[10];
    char sigla_estado[3];
    char cidade[51];
    char rua[51];
    char numero[6];
    char bairro[31];
    char cnh[12];
    char email[50];
    char fone[15];
    int score;

    if (file == NULL) {
        printf("Erro, não foi possivel abrir o arquivo\n");
    } else {
        while (fscanf(file,
                      "%49[^|]|%49[^|]|%10[^|]|%11[^|]|%79[^|]|%9[^|]|%2[^|]|%50[^|]|%50[^|]|%5[^|]|%30[^|]|%11[^|]|%48[^|]|%14[^|]|%d|\n",
                      nome, sobrenome, data_nascimento, cpf, nome_mae, rg, sigla_estado, cidade, rua, numero, bairro,
                      cnh, email, fone, &score) != EOF) {
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
                strcpy(_newUser->endereco.numero, numero);
                strcpy(_newUser->endereco.bairro, bairro);
                strcpy(_newUser->cnh, cnh);
                strcpy(_newUser->email, email);
                strcpy(_newUser->fone, fone);
                _newUser->score = score;

                _newUser->proxUser = DataUser;
                DataUser = _newUser;
            }
        }
    }
    fclose(file);
    return DataUser;
}
