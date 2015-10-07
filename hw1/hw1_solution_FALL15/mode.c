#include "statistics.h"

int mode(int* numberSequence, int size) {
	mergeSort(numberSequence, 0, size-1, size);

	int currently_counting = numberSequence[0]; //we will start counting at the first index
	int current_count = 1; //count starts at 1 to avoid double counting first index

	int mode = 0;
	int mode_count = 0;

	int i = 0;

	for(i = 1; i < size; i++) { //start at index 1 because index 0 is already counted above
		if(numberSequence[i] != currently_counting) {
			/* the >= takes care of the case that two counts are equal and we want to return the highest
			of the modes with an equal count */
			if(current_count >= mode_count) { 
				mode = numberSequence[i-1];
				mode_count = current_count;
			}

			currently_counting = numberSequence[i];
			current_count = 1;
		} else {
			current_count += 1;
		}
	}
	//one final check for the highest number in the list
	if(current_count >= mode_count) { 
		mode = numberSequence[i-1]; //i was last at size, so i-1 is the last element in the list
	}

	return mode;
}