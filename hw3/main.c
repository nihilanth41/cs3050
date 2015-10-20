#include <stdlib.h>
#include <stdio.h>
#include "statistics_errors.h"



int main(int argc, char** argv) {
	//take 5 args from cmd line 
	if(argc != 6)
		exit(INCORRECT_COMMAND_LINE_ARGUMENTS);
	//arg 1 is number_computers 
	//arg 2 is log file 
	//arg 3 is CBad (Name of computer infected first)
	//arg 4 is tBad (time when CBad is infected)
	//arg 5 is output file name 
	
	//syntax of log file is (c1, c2, t) 
	//computer c1 and c2 communicated at time t
	
	return 0;
}
