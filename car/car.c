#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "car.h"
#include "../functions.h"
#include "../user/user.h"

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KWHT  "\x1B[37m"
#define KNRM  "\x1B[0m"

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
        printf("Ano: ");
        scanf(" %d", &_newCar->ano);
    } while (!valYear(_newCar->ano));

    printf("Preco: R$");
    scanf("%f", &_newCar->preco);

    do {
        printf("Placa: ");
        scanf(" %8[^\n]", _newCar->placa);
    } while (!valPlate(_newCar->placa));

    do {
        printf("Renavam: ");
        scanf(" %11[^\n]", _newCar->renavam);
    } while (!(validatorGlobal(_newCar->renavam, 'N', 9) && valRenavam(_newCar->ano, _newCar->renavam)));

    printf("Km: ");
    scanf(" %6[^\n]", _newCar->km);

    _newCar->status = 1; // 1 - Disponível para alugar | 0 - Indisponível
    _newCar->qtd_alugado = 0;

    strcpy(_newCar->cpf, "\t");
    _newCar->proxCar = *DataCar;
    *DataCar = _newCar;
    saveCar(*DataCar);
}

// Editar atributos do carro
void editCar(Car *DataCar) {
    char placa[9];
    printf("Informe a Placa do carro: ");
    scanf(" %8[^\n]", placa);
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
        printf("\n\tPassou!\n");
    }
    if (p == NULL) // Verifica se achou o elemento
        printf("\n\tAchou o elemento\n");
    // Retira elemento
    if (ant == NULL) { // Retira o elemento do inicio da lista
        DataCar = p->proxCar;
        printf("\n\tRetirou o elemento do inicio da lista!\n");
    } else { // Retira o elemento do meio da lista
        ant->proxCar = p->proxCar;
        printf("\n\tRetirou o elemento do meio da lista!\n");
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
                printf("Status: [%s ■ %s] ", KRED, KNRM);
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
            printf("Preço: %.2fR$\n", aux->preco);
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
                printf("%s - [ %s ]\n", aux->modelo, aux->placa);
            }
        }
    } else {
        printf("Nenhum carro disponivel!\n");
    }
}

int checkExistCar(char placa[9], Car *DataCar) {
    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (aux->placa == placa) { // Se 1, está livre
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
                printf("%s - [ %s ]\n", aux->modelo, aux->placa);
            }
        }
    } else {
        printf("Nenhum Carro alugado!\n");
    }

}

void rentCar(Car *DataCar, Historic *DataHistoric, User *DataUser) {
    char placa[9];
    int dias;

    listCar(DataCar);
    do {
        printf("Placa do Carro que deseja alugar: ");
        scanf(" %8[^\n]", placa);
    } while (checkExistCar(placa, DataCar));

    for (Car *aux = DataCar; aux != NULL; aux = aux->proxCar) {
        if (strcmp(aux->placa, placa) == 0) { // Se a placa for igual ao cadastrado ele retorna 0
            aux->status = 0;
            do {
                printf("CPF: ");
                scanf(" %11[^\n]", aux->cpf);
            } while (valCPF(aux->cpf) && checkExistUser(aux->cpf, DataUser));

            printf("Quantos dias de aluguel?");
            scanf(" %d", &dias);

            float price = dias * aux->preco;
            char data[] = "01/09/2017"; // <- Se possível puxar data atual
            printf("O Preço Tota R$: %f", price);
            printf("Carro alugado com sucesso!");

            // Save in Historic
            addInHistoric(aux->cpf, aux->placa, data, price, 0, &DataHistoric);
            aux->status++;
        }
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

// [ Valida Km ]
int valKm(char km[7]) {
    for (int i = 0; km[i] != '\0'; i++) {
        if (!(km[i] >= '0' && km[i] <= '9')) {  // Verifica se é tudo número
            False;
        }
    }
    return True;
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
    FILE *file = fopen("car/car.dat", "r");

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
