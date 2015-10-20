#include <stdio.h>
#include <stdlib.h>

void build_max_heap(int *a);
void max_heapify(int *a, int i);
int parent(int *a, int i);
int left(int *a, int i);
int right(int *a, int i);

#define HEAP_SIZE 7

// Input: a[]: An array representing a heap, i: an array index
// Output: Index in a[] of the parent of i 
int parent(int *a, int i) {
	if(i == 0) { return NULL; }
	return (i/2); 
}

// Input: a[]: An array representing a heap, i: an array index
// Output: Index in a[] of the right child of i
int right(int *a, int i) {
	if((2*i)+1 <= HEAP_SIZE)
	{
		return (2*i)+1;
	}
	else
		return NULL;
}

// Input: a[]: An array representing a heap, i: an array index
// Output: Index in a[] of the left child of i
int left(int *a, int i) {
	if((2*i) <= HEAP_SIZE)
	{
		return (2*i);
	}
	else
		return NULL;
}

// Input: a[]: An unsorted array 
// Output: a[] modified such that it represents a heap 
void build_max_heap(int *a) {
	int i;
	for(i=(HEAP_SIZE/2); i>0; i--)
	{
		max_heapify(a, i);
	}
}

// Input: a[]: an array where the left and right children of i are heaps (but i is not necessarily), i: an array index
// Output: a[] modified such that index i is the root of a heap
void max_heapify(int *a, int i) {
	int largest=0;
	int l = left(a, i);
	int r = right(a, i);
	if(l == NULL)
	{
		largest = i;
	}
	else
	{
		if( (l <= HEAP_SIZE) && (*(a+l) > *(a+i)) ) 
			{ largest = l; }
		else 
			{ largest = i; }
	}
	
	if(r != NULL)
	{
		if( (r <= HEAP_SIZE) && (*(a+r) < *(a+largest)) )
			{ largest = r; }
	}

	if( largest != i )
	{
		//exchange A[i] & A[largest]
		int tmp = *(a+i); 
		*(a+i) = *(a+largest);
		*(a+largest) = tmp; 

		//max_heapify again to verify heap property
		max_heapify(a, largest);
	}
}
	
int main(int argc, char **argv) {
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	build_max_heap(a);
	int i;
	for(i=0; i<HEAP_SIZE; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	return EXIT_SUCCESS;
}
