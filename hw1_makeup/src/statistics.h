#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "statistics_errors.h"

#define BUFFER 100

int parser(FILE* inputFile, int** numberSequence);
int median(int* numberSequence, int size);
