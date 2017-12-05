#include "car.h"

// >> [ CRUD ]

// [ Cadastrar usuário ]
void singUpCar(Car **DataCar) {
    Car *_newCar = (Car *) malloc(sizeof(Car));

    do {
        printf("Modelo: ");
        scanf(" %30[^\n]", _newCar->modelo);
    } while (!valModel(_newCar->modelo));

    do {
        printf("Cor: ");
        scanf(" %8[^\n]", _newCar->cor);
    } while (!validatorGlobal(_newCar->cor, 'S', 3));

    do {
        printf("Ano [xxxx]: ");
        scanf(" %d", &_newCar->ano);
    } while (!valYear(_newCar->ano));

    printf("Preco: R$");
    scanf(" %f", &_newCar->preco);

    do {
        printf("Placa [xxx-xxxx]: ");
        scanf(" %8[^\n]", _newCar->placa);
    } while (!valPlate(_newCar->placa));

    do {
        printf("Renavam [Ano até 2012: 9 digitos - Acima: 11 digitos]: ");
        scanf(" %11[^\n]", _newCar->renavam);
    } while (!(validatorGlobal(_newCar->renavam, 'N', 9) && valRenavam(_newCar->ano, _newCar->renavam)));

    do {
        printf("Km: ");
        scanf(" %6[^\n]", _newCar->km);
    } while (!validatorGlobal(_newCar->km, 'N', 1));

    _newCar->status = 1; // 1 - Disponível para alugar | 0 - Indisponível
    _newCar->qtd_alugado = 0;

    strcpy(_newCar->cpf, "\t");
    _newCar->proxCar = *DataCar;
    *DataCar = _newCar;
    saveCar(*DataCar);
}

// [ Deleta cadastro do carro ]
Car *deleteCar(Car *DataCar) {
    char placa[9];
    printf("Informe a placa: ");
    scanf(" %8[^\n]", placa);

    Car *ant = NULL; // Ponteiro para elemento anterior
    Car *p = DataCar; // Ponteiro para percorrer a lista
    // Procura elemento na lista guardando o anterior
    while (p != NULL && strcmp(p->placa, placa) != 0) {
        ant = p;
        p = p->proxCar;
    }
    if (p == NULL) // Verifica se achou o elemento
        return DataCar; // Não achou retorna a lista original
    // Retira elemento
    if (ant == NULL) { // Retira o elemento do inicio da lista
        DataCar = p->proxCar;
        printf("\n\tCadastro excluído com sucesso.\n");
    } else { // Retira o elemento do meio da lista
        ant->proxCar = p->proxCar;
        printf("\n\tCadastro excluído com sucesso.\n");
    }
    free(p); // Libera o elemento
    return DataCar;
}

// [ Ver todos os carros cadastrados ]
void listCar(Car *DataCar) {
    if (DataCar != NULL) {
        Car *aux = NULL;
        for (aux = DataCar; aux != NULL; aux = aux->proxCar) {
            if (aux->status == 1)
                printf("Status: [%s ■ %s] ", KGRN, KNRM);
            else
                printf("Status: [%s x %s] ", KRED, KNRM);
            printf("Modelo: %s | ", aux->modelo);
            printf("Placa: %s | ", aux->placa);
            printf("Preço: R$%.2f | ", aux->preco);

            printf("Qtd Alugado: %d\n", aux->qtd_alugado);
            printf("\n--------------------------------------------------\n");
        }
    } else {
        printf("\n\n>> Sem veículos cadastrados!\n");
    }
}

// [ Busca cadastro do carro pela placa ]
int searchCar(Car *DataCar) {
    char placa[9];
    printf("Informe a placa: ");
    scanf(" %8[^\n]", placa);

    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (strcmp(aux->placa, placa) == 0) { // Se a placa for igual ao cadastrado ele retorna 0
            printf("Modelo: %s\n", aux->modelo);
            printf("Cor: %s\n", aux->cor);
            printf("Ano: %d\n", aux->ano);
            printf("Placa: %s\n", aux->placa);
            printf("Preço: R$ q%.2f\n", aux->preco);
            printf("Renavam: %s\n", aux->renavam);
            printf("Km: %s\n", aux->km);
            if (aux->status == 1)
                printf("Status: Disponível\n");
            else
                printf("Status: Indisponível\n");
            printf("Quantidade de vezes alugado: %d\n", aux->qtd_alugado);
            return False;
        }
    }
    printf("Carro não cadastrado\n");
    return True; // Não encontrou o elemento
}

// [ Carros disponiveis ]
void CarFree(Car *DataCar) {
    if (DataCar != NULL) {
        printf("Carros disponiveis:\n");
        for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
            if (aux->status == 1) { // Se 1, está livre
                printf("Status: [%s ■ %s] ", KGRN, KNRM);
                printf("Modelo: %s | ", aux->modelo);
                printf("Placa: %s | ", aux->placa);
                printf("Preço: R$%.2f | ", aux->preco);

                printf("Qtd Alugado: %d\n", aux->qtd_alugado);
            }
        }
    } else {
        printf("Nenhum carro disponivel!\n");
    }
}

int checkIfCarAvariable(char placa[9], Car *DataCar) {
    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (strcmp(aux->placa, placa) && (aux->status == 1)) {
            return True;
        }
    }
    return False;
}

int checkIfCarRented(char placa[9], Car *DataCar) {
    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (strcmp(aux->placa, placa) && (aux->status == 0)) {
            return True;
        }
    }
    return False;
}

// [ Carros Alugados ]
void CarRented(Car *DataCar) {
    if (DataCar != NULL) {
        printf("Carros Alugados:\n");
        for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
            if (aux->status == 0) { // Se 0, está alugado
                printf("Status: [%s x %s] ", KRED, KNRM);
                printf("Modelo: %s | ", aux->modelo);
                printf("Placa: %s | ", aux->placa);
                printf("A quem está locado: %s\n", aux->cpf);
            }
        }
    } else {
        printf("Nenhum Carro alugado!\n");
    }

}
 // [ Alugar carro ]
void rentCar(Car *DataCar, Historic *DataHistoric, User *DataUser) {
    char placa[9];
    int dias;

    time_t tempo;
    struct tm *timeptr;
    // Date
    char date[11];
    tempo = time(NULL);
    timeptr = localtime(&tempo);
    strftime(date,sizeof(date), "%d/%m/%Y", timeptr);

    listCar(DataCar);
    do {
        printf("Placa do Carro que deseja alugar: ");
        scanf(" %8[^\n]", placa);
    } while (checkIfCarAvariable(placa, DataCar));
    if (DataUser != NULL) {
    for (Car *car = DataCar; car != NULL; car = car->proxCar) {
        if (strcmp(car->placa, placa) == 0) { // Se a placa for igual ao cadastrado ele retorna 0
            do {
                printf("CPF: ");
                scanf(" %11[^\n]", car->cpf);
            } while (!checkExistUser(car->cpf, DataUser));

            char temp[3];
            do {
                printf("Dias de aluguel: ");
                scanf(" %3[^\n]", temp);
            } while  (!validatorGlobal(temp, 'N', 1));
            dias = (int) atof(temp);

            float price = dias * car->preco;
            printf("O Preço Total R$: %.2f\n Continuar (S/n)? ", price);

            char opition;
            scanf(" %c", &opition);

            if (opition == 'S' || opition == 's') {

                car->status--;
                car->qtd_alugado++;
                incrementScore(DataUser, car->cpf);

                // Save in Historic
                addInHistoric(car->cpf, car->placa, date, price, 0, &DataHistoric); // 0 - Indisponível
                // Save User
                saveUser(DataUser);
                // Save Car
                saveCar(DataCar);

                printf("Carro alugado com sucesso!\n");

            } else {
                printf("Aluguel cancelado!\n");
            }
        }
    }
    } else { printf("Nenhum cliente cadastrado! Faça o Cadastro e tente novamente\n"); }
}

// [ Devolve carro ]
void returnCar(Car *DataCar, Historic *DataHistoric, User *DataUser) {
    if (DataCar != NULL) {
        char placa[9];
        int dias;

        time_t tempo;
        struct tm *timeptr;
        // Date
        char date[11];
        tempo = time(NULL);
        timeptr = localtime(&tempo);
        strftime(date, sizeof(date), "%d/%m/%Y", timeptr);

        listCar(DataCar);

        do {
            printf("Placa do Carro que deseja devolver: ");
            scanf(" %8[^\n]", placa);
        } while(checkIfCarRented(placa, DataCar));

        for (Car *car = DataCar; car != NULL; car = car->proxCar) {
            if (strcmp(car->placa, placa) == 0) { // Se a placa for igual ao cadastrado ele retorna 0
                printf("Continuar devolução (S/n)? ");

                char opition;
                scanf(" %c", &opition);

                if (opition == 'S' || opition == 's') {
                    printf("Carro Devolvido com sucesso!\n");

                    //Save in Historic
                    for (Historic *historic = DataHistoric; historic != NULL; historic = historic->proxHistoric) {
                        if (strcmp(car->placa, placa) == 0) {
                            addInHistoric(historic->cpfUser, car->placa, date, 0, 1, &DataHistoric); // 1 - Disponível | 0 - Indisponível
                        }
                    }

                    car->status = 1;

                    // Save Car
                    saveCar(DataCar);

                } else {
                    printf("Aluguel cancelado!\n");
                }
            }
        }
    } else { printf("Nenhum carro cadastrado! Faça o Cadastro e tente novamente\n"); }
}

// [ Mostra o carro mais alugado ]
void showBestCar(Car *DataCar) {
    char placa[9];
    int max = 0;
    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (aux->qtd_alugado > max) {
            strcpy(placa, aux->placa);
            max = aux->qtd_alugado;
        }
    }

    if (max != 0) {
        for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
            if (strcmp(aux->placa, placa) == 0) {
                printf("O Carro mais alugado do cRentCar é o %s, placa: %s com %d locações.\n", aux->modelo, aux->placa, aux->qtd_alugado);
            }
        }
    } else {
        printf("Nenhum carro foi alugado.\n");
    }
}

// >> [ Validações ]
// [ Valida Modelo ]
int valModel(char model[31]) {
    if (strlen(model) != 0) {
        for (int i = 0; model[i] != '\0'; i++) {
            if (model[i] >= 34 && model[i] <= 43 && model[i] >= 58 && model[i] <= 64) {
                printf("Modelo inválido!");
                return False;
            }
        }
        return True;
    }
    return False;
}

// [ Valida Cor ]
// Using Validator Global

// [ Valida Ano ]
int valYear(int year) {
    if (year >= 1900 && year <= 3000) {
        return True;
    }
    printf("Ano inválido!\n");
    return False;
}

// [ Valida Placa]
int valPlate(char plate[9]) {
    if (strlen(plate) == 8 && plate[3] == '-') { // Check se existe '-'
        for (int i = 0; plate[i] != '\0'; ++i) {
            if (i < 3) {  // Letras
                if (!((plate[i] >= 65 && plate[i] <= 90) || (plate[i] >= 97 && plate[i] <= 122))) {
                    printf("Placa Inválida\n");
                    return False;
                }
            } else if (i > 3) {  // Numeros
                if (!(plate[i] >= 48 && plate[i] <= 57)) {
                    printf("Placa Inválida\n");
                    return False;
                }
            }
        }
        return True;
    } else {
        printf("Placa Inválida\n");
        return False;
    }
}

// [ Valida renavam ]
int valRenavam(int ano, char renavam[12]) {
    int comp = (int) strlen(renavam);
    return ((comp == 9 && ano <= 2012) || (comp == 11 && ano >= 2013));  // Verifica o comprimento do renavam e o ano
}

// [ I/O dos dados e memoria ]
void saveCar(Car *DataCar) {
    FILE *file = fopen("car/car.dat", "w+");
    if (file == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    } else {
        for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
            fprintf(file, "%s|%s|%d|%.2f|%s|%s|%s|%s|%d|%d|\n", aux->modelo, aux->cor, aux->ano, aux->preco, aux->placa, aux->renavam, aux->km, aux->cpf, aux->status, aux->qtd_alugado);
        }
        fclose(file);
    }
}

Car *loadCar(Car *DataCar) {
    FILE *file = fopen("car/car.dat", "a+");

    char modelo[31];
    char cor[9];
    int ano;
    float preco;
    char placa[9];
    char renavam[12];
    char km[7];
    char cpf[12];
    int status;
    int qtd_alugado;

    if (file == NULL) {
        printf("Erro, não foi possivel abrir o arquivo\n");
    } else {
        while (fscanf(file, "%30[^|]|%8[^|]|%d|%f|%8[^|]|%11[^|]|%6[^|]|%11[^|]|%d|%d|\n", modelo, cor, &ano, &preco, placa, renavam, km, cpf, &status, &qtd_alugado) != EOF) {
            Car *_newCar = (Car *) malloc(sizeof(Car));

            strcpy(_newCar->modelo, modelo);
            strcpy(_newCar->cor, cor);
            _newCar->ano = ano;
            _newCar->preco = preco;
            strcpy(_newCar->placa, placa);
            strcpy(_newCar->renavam, renavam);
            strcpy(_newCar->km, km);
            strcpy(_newCar->cpf, cpf);
            _newCar->status = status;
            _newCar->qtd_alugado = qtd_alugado;

            printf("%s", _newCar->modelo);

            _newCar->proxCar = DataCar;
            DataCar = _newCar;
        }
    }
    fclose(file);
    return DataCar;
}