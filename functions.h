#ifndef _FUNCTIONH_
#define _FUNCTIONH_

#include <stdio.h>
#include <string.h>
#include <time.h>

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KNRM  "\x1B[0m"

// Bool
#define False 0
#define True 1

int validatorGlobal(char vetor[], char type, int min);
int isDigit(char i);

#endif