#include "historic.h"

// [ I/O dos dados e memoria ]
void saveHistoric(Historic *DataHistoric) {
    FILE *file = fopen("historic/historic.dat", "w+");
    if (file == NULL) {
        printf("Houve um erro ao abrir o arquivo.\n");
        exit(1);
    } else {
        for (Historic *p = DataHistoric; p != NULL; p = p->proxHistoric) {
            fprintf(file, "%s|%s|%s|%f|%d|\n", p->cpfUser, p->placa, p->data, p->priceTotal, p->status);
        }
        fclose(file);
    }
}

Historic *loadHistoric(Historic *DataHistoric) {
    FILE *file = fopen("historic/historic.dat", "a+");

    char data[12];
    char placa[9];
    char cpfUser[12];
    int status;
    float priceTotal;

    if (file == NULL) {
        printf("Erro, não foi possivel abrir o arquivo\n");
    } else {
        while (fscanf(file, "%12[^|]|%9[^|]|%12[^|]|%f|%d|\n", cpfUser, placa, data, &priceTotal, &status) != EOF) {
            Historic *_newHistoric = (Historic *) malloc(sizeof(Historic));

                strcpy(_newHistoric->cpfUser, cpfUser);
                strcpy(_newHistoric->placa, placa);
                strcpy(_newHistoric->data, data);
                _newHistoric->priceTotal = priceTotal;
                _newHistoric->status = status;

                _newHistoric->proxHistoric = DataHistoric;
                
                DataHistoric = _newHistoric;

        }
    }
    fclose(file);
    return DataHistoric;
}

void showHistoric(Historic* DataHistoric) {
    for (Historic *aux = DataHistoric; aux != NULL; aux = aux->proxHistoric) {
        printf("%s | ", aux->data);
        if (aux->status == 0) {
            printf("%sAlugado %s | ", KGRN, KNRM);
        } else {
            printf("%sDevolvido %s | ", KGRN, KNRM);
        }
        printf("Preço: %.2f | ", aux->priceTotal);
        printf("Placa: %s\n", aux->placa);
    }
}

void showEarn(Historic* DataHistoric) {
    float lucro = 0;
    for (Historic *aux = DataHistoric; aux != NULL; aux = aux->proxHistoric) {
        lucro += aux->priceTotal;
    }

    if (lucro != 0) {
        printf("cRentCar obteve %.2f de Lucro.\n", lucro);
    } else {
        printf("Nenhum lucro, está zerado.\n");
    }
}

void showBestUser(User* DataUser) {
    char cpf[12];
    int max = 0;
    for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
        if (aux->score > max) {
            strcpy(cpf, aux->cpf);
            max = aux->score;
        };
    }

    if (max != 0) {
        for (User *aux = DataUser; aux != NULL; aux = aux->proxUser) {
            if (strcmp(aux->cpf, cpf) == 0) {
                printf("O(A) cliente VIP do cRentCar é %s, CPF: %s com %d locações.\n", aux->nome, aux->cpf, aux->score);
            };
        }
    } else {
        printf("Nenhum Cliente VIP\n");
    }
}
