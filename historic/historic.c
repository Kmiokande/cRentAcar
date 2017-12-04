#include "historic.h"

void addInHistoric(char cpf[12], char placa[9], char data[11], float price, int status, Historic **DataHistoric) {

    Historic *_newHistoric = (Historic *) malloc(sizeof(Historic));

    strcpy(_newHistoric->cpfUser, cpf);
    strcpy(_newHistoric->placa, placa);
    strcpy(_newHistoric->data, data);
    _newHistoric->priceTotal = price;
    _newHistoric->status = status;

    _newHistoric->proxHistoric = *DataHistoric;
    saveHistoric(_newHistoric);
    *DataHistoric = _newHistoric;
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
                _newHistoric->status, status;

                _newHistoric->proxHistoric = DataHistoric;
                
                DataHistoric = _newHistoric;

        }
    }
    fclose(file);
    return DataHistoric;
}
