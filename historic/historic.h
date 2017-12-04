#ifndef _MATRIXH_
#define _MATRIXH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct historic {
    char data[12];
    char placa[9];
    char cpfUser[12];
    int qDias;
    int status;
    float priceTotal;
    struct historic *proxHistoric;
} Historic;

void addInHistoric(char cpf[12], char placa[9], char data[11], int dias, float price, int status, Historic **DataHistoric);

void saveHistoric(Historic *DataHistoric);

Historic *loadHistoric(Historic *DataHistoric);

#endif