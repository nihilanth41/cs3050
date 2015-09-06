#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "statistics_errors.h"
#include "statistics_reporting.h"

long int get_size(char **argv);
void get_mode(int *a, long int size, long int *mode, long int *count);
int is_integer(char *str);
void sort(int *array, int size);

int main( int argc, char **argv )
{
	//check input args
	if(argc != 2) 
	{
		return INCORRECT_COMMAND_LINE_ARGUMENTS;
	}

	long int size = get_size(argv);
	int ret=0;

	//Use the number of strings to alloc memory for our double pointers
	char **pp = (char **)malloc(size * sizeof(*pp));
	char **begin = pp;
	int *intPtr = (int *)malloc(size * sizeof(int));
	int *ib = intPtr;
	

	//reopen file
	FILE *file = fopen( argv[1], "r" );
	if(file == NULL) { return FILE_FAILED_TO_OPEN; }
	//only read as many strings as we allocated memory for
	int i=0;
	for(i=0; i<size; ++i)
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
	for(i=0; i<size; i++)
	{
		//check if it's a valid integer
		if(is_integer(*pp))
		{
			//copy to int array
			*intPtr = atoi(*pp);
			intPtr++;
		}
		else
		{
			exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
		}
		free(*pp);
		pp++;
	}

	free(begin);
	pp=NULL;
	begin=NULL;
	//sort array
	intPtr = ib;
	sort(intPtr, size);
	long int count=0;
	long int mode=0;
	get_mode(intPtr, size, &mode, &count);
	free(ib);
	ib=NULL;
	intPtr=NULL;
	
		
	// Call this function with the proper arguments, in the correct order (count,mode)
	REPORT(count, mode);
	return EXIT_SUCCESS;

}

long int get_size(char **argv) {
	
	//open the file, read the first 99 chars of each string into a buffer and record the number of strings found
	FILE *file = fopen( argv[1], "r" );
	if(file == NULL) { exit(FILE_FAILED_TO_OPEN); }
	int ret;
	long int count=0;
	char buf[100];
	for(;;)
	{
		ret = fscanf(file, "%99s", buf);
		if(ret == EOF) break;
		count++;
	}
	if(count == 0) 
		exit(PARSING_ERROR_EMPTY_FILE);

	ret = fclose(file);
	if(ret != 0) 
		exit(FILE_FAILED_TO_CLOSE);
	
	return count;
}

void get_mode(int *a, long int size, long int *mode, long int *count) {
	//assign values for current mode
	int currentMode=0;
	int currentFreq=0;
	
	//values for temp
	int tempMode=*a;
	int tempFreq=1;
	//set first value manually
	int i=1;
	for(i=1; i<size; i++)
	{
		//if we are at a transition
		//then check the mode of our tracking number against our current mode
		if(*(a+i) != tempMode || i == size) 
		{
			//cmp modes
			if(tempFreq > currentFreq)
			{
				//assign new mode if temp is larger 
				currentMode = tempMode;
				currentFreq = tempFreq;
			}
			//assign new tempMode b/c transition
			tempMode = *(a+i);
			tempFreq = 1;
			//return to beginning of for loop
			continue;
		}
		//otherwise tempMode = current number, increment tempFreq
		tempFreq++;
	
		//if at the last element 
		if(i == size)
		{
			//cmp modes
			if(tempFreq > currentFreq)
			{
				currentMode = tempMode;
				currentFreq = tempFreq;
			}
		}
	}
	//end of array
	*mode = currentMode;
	*count = tempFreq;
}





		

int is_integer(char *str) {
		//empty string or just -
	if(*str == '-') 
	{
		++str;
	}
	if(!*str)
	{
		return 0;
	}
	while(*str)
	{
		if(!isdigit(*str))
		{
			return 0;
		}
		else
		{
			++str;
		}
	}
	return 1;
}



void sort(int *p, int size)
{ 
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
