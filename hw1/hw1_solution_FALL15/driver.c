#include "statistics_reporting.h"
#include "statistics.h"


int main(int argc, char** argv){
	
	if(argc != 2){
		exit(INCORRECT_COMMAND_LINE_ARGUMENTS);
	}

	int* numberSequence = malloc(sizeof(long int) * BUFFER); //create the array we will use to store all the inputs

	FILE* inputFile = fopen(argv[1], "r");

	if(inputFile == NULL){
		exit(FILE_FAILED_TO_OPEN);	
	}

	int size = parser(inputFile, &numberSequence);  //create size variable

	#ifdef execute_mode
		REPORT((long) size, (long) mode(numberSequence, size));
		free(numberSequence);
	#endif
	
}