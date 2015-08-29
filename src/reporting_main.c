#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statistics_errors.h"
#include "statistics_reporting.h"

//max str length
#define SIZE_MAX 100 

long int mode(int *array, int size);
void sort(int *array, int size);

int main( int argc, char **argv )
{
	//check input args
	if(argc != 2) 
	{
		return INCORRECT_COMMAND_LINE_ARGUMENTS;
	}
	
	//attempt to open file ro
	FILE *file = fopen( argv[1], "r" );
	if(file == NULL) { return FILE_FAILED_TO_OPEN; }
	//file can have any size from 0 to MAX_INT
	//get the number of strings
	static int ret;
	long int count=0;
	char buf[SIZE_MAX];
	for(;;)
	{
		ret = fscanf(file, "%99s", buf);
		if(ret == EOF) break;
		count++;
	}
	if(count == 0) return PARSING_ERROR_EMPTY_FILE;
	//close file
	ret = fclose(file);
	if(ret != 0) return FILE_FAILED_TO_CLOSE; 
	
	//alloc memory for string pointers 
	char **pp = (char **)malloc(count * sizeof(char *));
	char **begin = pp;
	//reopen file
	file = fopen( argv[1], "r" );
	if(file == NULL) { return FILE_FAILED_TO_OPEN; }
	//only read as many strings as we allocated memory for
	int i=0;
	for(i=0; i<count; ++i)
	{
		//get string from file
		ret = fscanf(file, "%99s", buf);
		//allocate memory for string
		//alternatively use sizeof(buf)
		*pp = strdup(buf);
		pp++;	
		//point string pointer at string 
		//increment string pointer
		if(ret == EOF) break;
	}
	pp = begin;
	for(i=0; i<count; i++)
	{
		printf("%s\n", *pp);
		pp++;
	}

	
		
	// These are here to showcase use of the reporting function and can be removed
	long int mode = 14;
			
	// Call this function with the proper arguments, in the correct order (count,mode)
	REPORT(count, mode);
	return EXIT_SUCCESS;

}


void sort(int *p, int size)
{ //merge sort 
	int hold = 0;
	int pass = 0;
	for(pass=1; pass<size; pass++)
	{
		int i=0;
		for(i=0; i<(size-1); i++)
		{
			if(*(p+i) > *(p+i+1)) //if larger value appears in smaller index then swap
			{
				hold = *(p+i); //hold larger value
				*(p+i) = *(p+i+1); //swap smaller value into smaller index
				*(p+i+1) = hold; //swap larger value with larger index		
			}
		}
	}
}
