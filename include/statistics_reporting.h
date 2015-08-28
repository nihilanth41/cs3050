#ifndef H_STATISTICS_REPORTING_H
#define H_STATISTICS_REPORTING_H

#include <stdio.h>

/* Call this function with the count first, followed by the mode */
#define REPORT(a,b) \
	do \
		fprintf(stdout, "%ld,%ld\n", a, b); \
	while(0) \

#endif
