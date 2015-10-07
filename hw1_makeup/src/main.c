#include <stdio.h>
#include <stdlib.h>
#include "statistics_errors.h"
#include "parser.h" 

int main(int argc, char **argv) {
	if(argc != 2)
		exit(INCORRECT_COMMAND_LINE_ARGUMENTS);
	
	//first argument is input file
	FILE *infile = fopen("r", argv[1]); 
	if(infile == NULL)
		exit(FILE_FAILED_TO_OPEN);
		
	//second argument is output file
	FILE *outfile = fopen("w", argv[2]);
	//parser to get int 
	
	//input file has n numbers 
	//output file has n lines
	//i'th line of output file should be median of first i numbers of the file
	//median in this case is:
	//	i odd: (i-1)/2 < median in the list 
	//	i even: median (i/2+1)th 
	
