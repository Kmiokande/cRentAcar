#ifndef _MATRIXH_
#define _MATRIXH_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../functions.h"
#include "../user/user.h"

typedef struct historic {
    char data[12];
    char placa[9];
    char cpfUser[12];
    int status;
    float priceTotal;
    struct historic *proxHistoric;
} Historic;

void addInHistoric(char cpf[12], char placa[9], char data[11], float price, int status, Historic **DataHistoric);

void saveHistoric(Historic *DataHistoric);

void showHistoric(Historic* DataHistoric);

void showEarn(Historic* DataHistoric);

void showBestUser(User* DataUser);

Historic *loadHistoric(Historic *DataHistoric);

#endif