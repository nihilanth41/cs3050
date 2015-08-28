#include <stdio.h>
#include <stdlib.h>
#include "statistics_errors.h"
#include "statistics_reporting.h"

//temporarily?
#define ARRAY_SIZE 100

int main( int argc, char **argv )
{
	//for checking return values
	static int ret=0;

	//check input args
	if(argc != 1) 
	{
		return INCORRECT_COMMAND_LINE_ARGUMENTS;
		
	}

	//attempt to open file ro
	FILE *file = fopen( "test.lst", "r" );
	if(file == NULL) return FILE_FAILED_TO_OPEN; 
	//file can have any size from 0 to MAX_INT
	int *a = malloc(sizeof(int));
	long int count = 0;
	for(;;)
	{
		ret = fscanf(file, "%d", a);
		if(ret == EOF) break;
		printf("Number [%ld] is %d\n", count, *a);
		count++;
	}
	free(a);
	if(count == 0) return PARSING_ERROR_EMPTY_FILE;
	ret = fclose(file);
	if(ret != 0) return FILE_FAILED_TO_CLOSE; 
	// These are here to showcase use of the reporting function and can be removed
	long int mode = 14;
	// Call this function with the proper arguments, in the correct order (count,mode)
	REPORT(count, mode);
	return EXIT_SUCCESS;

}
