#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arrayLength 4 // define array length
#define arrayWidth 7 // define array width

// 
// Programs, which explains dynamically allocated two-dimensional arrays
// 

int main() {
	
	int *pt = (int *) malloc(arrayLength * arrayWidth * sizeof(int)); 
	//must explicitly typecast0, in this case, we allocate 112 bytes
	int i, j, c; // declare variables
	srand(time(0)); // set the random number seed
	for (i = 0; i < arrayWidth; i++) 
		for (j = 0; j < arrayLength; j++) 
			*(pt + i*arrayWidth + j)= rand()%100 + 1; // fill the two-dimensional array with data

	for (i = 0; i < arrayWidth; i++) {
		for (j = 0; j < arrayLength; j++)
			printf("%d\n", *(pt + i*arrayWidth + j)); //print everything in the array
		printf("\n");  
    }
	free(pt); // free the memory
	return 0;
}
