#include <stdio.h>
#include <stdlib.h>

void build_max_heap(int *a, int n);
void max_heapify(int *a, int i, int n);
int parent(int *a, int i);
int left(int *a, int i);
int right(int *a, int i);

#define HEAP_SIZE 6

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

void build_max_heap(int *a, int n) {
	int i;
	for(i=(n/2); i>0; i--)
	{
		max_heapify(a, i, n);
	}
}

//untested, built from psuedocode 
//makes a heap out of the subtree
void max_heapify(int *a, int i, int n) {
	int largest=0;
		

	if((left <= n) && (*(a+left) > *(a+i)))
	{
		largest = left;
	}
	else
	{
		largest = i;
	}
	if((right <= n) && (*(a+right) > *(a+largest)))
	{
		largest = right;
	}
	if(largest != i)
	{
		int temp = *(a+i); 
		*(a+i) = *(a+largest);
		*(a+largest) = temp;
		max_heapify(a, largest, n);
	}
}

int main(int argc, char **argv) {
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	int n = 7;
	build_max_heap(a, n);
	build_max_heap(a, n);
	int i;
	for(i=0; i<n; i++)
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	return EXIT_SUCCESS;
}
