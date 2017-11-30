#include <stdio.h>
#include <string.h>
#include "functions.h"

int False() {
    return 1;
}

int True() {
    return 0;
}

int validatorGlobal(char vetor[], char type, int min) {
    // Type N = Number
    // Type S = String
    if (strlen(vetor) >= min) {
        if (type == 'N') {
            for (int i = 0; vetor[i] != '\0'; i++) {
                if (vetor[i] >= 58 || vetor[i] <= 48) {
                    printf("\n >> Inválido! \n");
                    return False();
                }
            }
            return True();
        } else if (type == 'S') {
            for (int i = 0; vetor[i] != '\0'; i++) {
                if (vetor[i] >= 33 && vetor[i] <= 45 || vetor[i] >= 47 && vetor[i] <= 64) {
                    printf(" >> Inválido! \n");
                    return False();
                }
            }
            return True();

        }

    }
    printf(" >> No mínimo %d caracteres!\n", min);
    return False();
}