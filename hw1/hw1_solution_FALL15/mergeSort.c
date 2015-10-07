#include "statistics.h"

void mergeSort(int* numberSequence, int low, int high, int size){

		int mid = 0;
		if(low < high){
			mid = (low+high)/2;
			mergeSort(numberSequence, low, mid, size);
			mergeSort(numberSequence, mid+1, high, size);
			partition(numberSequence, low, mid, high, size);
		}
}

void partition(int* numberSequence, int low, int mid, int high, int size){

	long int* temp = malloc(sizeof(long int) * size);
	int k = 0;
	int l = low;
	int i = low;
	int m = mid + 1;

	while(l <= mid && m <= high){

		if(numberSequence[l] <= numberSequence[m]){
			temp[i] = numberSequence[l];
			l++;
		} else{
			temp[i] = numberSequence[m];
			m++;
		}
		
		i++;
	}

	if(l > mid){
		for(k = m;k <= high;k++){
			temp[i] = numberSequence[k];
			i++;
		}
	} else{
		for(k = l;k <= mid;k++){
			temp[i] = numberSequence[k];
			i++;
		}
	}

	for(k = low;k <= high;k++){
		numberSequence[k] = temp[k];
	}

	free(temp);
}
