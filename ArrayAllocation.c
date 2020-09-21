#include <stdio.h>
#include <stdlib.h>
#define SIZE 14


//
// Program dedicated to learning dynamically allocated arrays and how malloc function works
//

int main() {
	int array[SIZE] = {}; //					- declare and initialize an array
	int *array2 = (int*)malloc(SIZE * sizeof(int)); //		- dynamically allocate array
	printf("size of normal array %d\n",sizeof(array)); //		- print first array length
	printf("size of generated array %d\n\n",sizeof(array2));//	- print dynamically allocated pointer size
	for(int i = 0; i < SIZE; i++) { //				- fill both arrays
		array[i] = i;
		*(array2+i) = 2*i;
	}
	printf("Contents of normal array:\n");
	for(int i = 0; i < SIZE; i++) { //				- print first array data, must print: 1 2 3 4 5 6 7 8 9 10 11 12 13
		printf("%d ",array[i]);
	}
	printf("\nContents of generated array:\n"); 
	for(int i = 0; i < SIZE; i++) { //				- print dynamically allocated array data, must print: 0 2 4 6 8 10 12 14 16 18 20 22 24 26
		printf("%d ",*(array2+i));
	}
	free(array2); //						- deallocate dynamically allocated array
	
	return 0;
}
