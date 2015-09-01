#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "statistics_errors.h"
#include "statistics_reporting.h"

//max str length
#define SIZE_MAX 100 

int is_integer(char *str);
long int get_mode(int *a, int size);
void sort(int *array, int size);

int main( int argc, char **argv )
{
	//check input args
	if(argc != 2) 
	{
		return INCORRECT_COMMAND_LINE_ARGUMENTS;
	}
	
	//open the file, read the first 99 chars of each string into a buffer and record the number of strings found
	FILE *file = fopen( argv[1], "r" );
	if(file == NULL) { return FILE_FAILED_TO_OPEN; }
	int ret;
	long int count=0;
	char buf[SIZE_MAX];
	for(;;)
	{
		ret = fscanf(file, "%99s", buf);
		if(ret == EOF) break;
		count++;
	}
	if(count == 0) return PARSING_ERROR_EMPTY_FILE;
	ret = fclose(file);
	if(ret != 0) return FILE_FAILED_TO_CLOSE; 

	//Use the number of strings to alloc memory for our double pointers
	char **pp = (char **)malloc(count * sizeof(*pp));
	char **begin = pp;
	int *intPtr = (int *)malloc(count * sizeof(int));
	int *ib = intPtr;
	

	//reopen file
	file = fopen( argv[1], "r" );
	if(file == NULL) { return FILE_FAILED_TO_OPEN; }
	//only read as many strings as we allocated memory for
	int i=0;
	for(i=0; i<count; ++i)
	{
		//vars to pass to getline()
		char *line = NULL;
		size_t len = 0;
		ssize_t ret;

		//get a line from the file and store as string		
		ret = getline(&line, &len, file);
		//if read was successful
		if(ret != -1)
		{
		
			//use strtok() to split line into multiple strings
			//split on space, tab, or newline
			char *token = strtok(line, " \t\n");	
			while(token) {
				*pp = strdup(token);
				//printf("string token: %s\n", *pp);
				pp++;	
				token = strtok(NULL, " \t\n");
			}
		}
		free(line);
	}
	//close file
	ret = fclose(file);
	if(ret != 0) return FILE_FAILED_TO_CLOSE; 
	
	//point to beginning of str array
	pp = begin;
	for(i=0; i<count; i++)
	{
		//check if it's a valid integer
		if(is_integer(*pp))
		{
			//copy to int array
			*intPtr = atoi(*pp);
			intPtr++;
		}
		free(*pp);
		pp++;
	}
	free(begin);
	pp=NULL;
	begin=NULL;
	//sort array
	intPtr = ib;
	sort(intPtr, (int)count);
	long int test = get_mode(intPtr, (int)count);
	free(ib);
	ib=NULL;
	intPtr=NULL;
	
		
	// These are here to showcase use of the reporting function and can be removed
	long int mode = 14;
	// Call this function with the proper arguments, in the correct order (count,mode)
	REPORT(count, mode);
	return EXIT_SUCCESS;

}

long int get_mode(int *a, int size) {
	//*a is an array pointer with the numbers
	int i=0;
	int j=0;
	int *numbers = malloc(sizeof(*numbers)*size);	
	int *freq = calloc(size, sizeof(*freq));
	for(i=0; i<size; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}

		

int is_integer(char *str) {
	if(*str == '-') 
	{
		++str;
	}
	if(!*str)
	{
		//empty string or just -
		exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
	}
	while(*str)
	{
		if(!isdigit(*str))
		{
			exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
		}
		else
		{
			++str;
		}
	}
	return 1;
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
