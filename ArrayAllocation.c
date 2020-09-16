#include <stdio.h>
#include <stdlib.h>
#define SIZE 14

//
// Программа, нацеленная на изучение функции malloc и динамических массивов
//


int main() {
	int array[SIZE] = {}; //									- генерируем статический массив
	int *array2 = (int*)malloc(SIZE * sizeof(int)); //			- генерируем динамический массив
	printf("size of normal array %d\n",sizeof(array)); //		- выводим размер статического массива
	printf("size of generated array %d\n\n",sizeof(array2));//	- выводим размер указателя на выделенную память
	for(int i = 0; i < SIZE; i++) { //							- заполняем статический массив и динамический массив
		array[i] = i;
		*(array2+i) = 2*i;
	}
	printf("Contents of normal array:\n");
	for(int i = 0; i < SIZE; i++) { //							- выводим данные статического массива, в данном случае должен выдать: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
		printf("%d ",array[i]);
	}
	printf("\nContents of generated array:\n"); 
	for(int i = 0; i < SIZE; i++) { //							- выводим данные динамического массива, в данном случае должен выдать: 0 2 4 6 8 10 12 14 16 18 20 22 24 26
		printf("%d ",*(array2+i));
	}
	free(array2); //											- освобождаем выделенную память 
	
	return 0;
}