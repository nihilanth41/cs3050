#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "statistics_errors.h"

#define BUFFER 100

int parser(FILE* inputFile, int** numberSequence);
void mergeSort(int* numberSequence, int low, int high, int size);
void partition(int* numberSequence, int low, int mid, int high, int size);
int mode(int* numberSequence, int size);