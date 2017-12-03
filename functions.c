#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "functions.h"

int validatorGlobal(char vetor[], char type, int min) {
    // Type N = Number
    // Type S = String
    if (strlen(vetor) >= min) {
        if (type == 'N') {
            for (int i = 0; vetor[i] != '\0'; i++) {
                if (!isdigit(vetor[i])) {
                    printf(" >> Inválido! \n");
                    return False;
                }
            }
        } else if (type == 'S') {
            for (int i = 0; vetor[i] != '\0'; i++) {
                if (isdigit(vetor[i])) {
                    printf(" >> Inválido! \n");
                    return False;
                }
            }

        }
        return True;

    }
    printf(" >> No mínimo %d caracteres!\n", min);
    return False;
}