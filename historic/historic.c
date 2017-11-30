#include <stdio.h>
#include "historic.h"

void addInHistoric(char *cpf[12], char *placa[9], char *data[12], float price, int status, Historic *DataHistoric) {

    Historic *_newHistoric = (Historic *) malloc(sizeof(Historic));

    strcpy(_newHistoric->cpfUser, cpf);
    strcpy(_newHistoric->placa, placa);
    strcpy(_newHistoric->data, data);
    _newHistoric->priceTotal = price;
    _newHistoric->status = status;

    DataHistoric->proxHistoric = _newHistoric;
}

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
    FILE *file = fopen("historic/historic.dat", "r");

    Historic* p;

    if (file == NULL) {
        printf("Erro, não foi possivel abrir o arquivo\n");
    } else {
        while (fscanf(file, "%12[^|]|%9[^|]|%12[^|]|%f|%d|\n", p->cpfUser, p->placa, p->data, p->priceTotal, p->status) != EOF) {
            Historic *_newHistoric = (Historic *) malloc(sizeof(Historic));

            // if (cpfUser[0] >= 33) {
                strcpy(_newHistoric->cpfUser, p->cpfUser);
                strcpy(_newHistoric->placa, p->placa);
                strcpy(_newHistoric->data, p->data);
                _newHistoric->priceTotal = p->priceTotal;
                _newHistoric->status, p->status;

                _newHistoric->proxHistoric = DataHistoric;
                
                DataHistoric = _newHistoric;
            // }
        }
    }
    fclose(file);
    return DataHistoric;
}
