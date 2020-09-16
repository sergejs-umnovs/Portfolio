#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arrayLength 4 // опр. длину массива
#define arrayWidth 7 // опр. ширину массива

// 
// Программа для изучения двумерных динамических массивов 
// 

int main() {
	
	int *pt = (int *) malloc(arrayLength * arrayWidth * sizeof(int)); 
	//после   резервирования, надо отформатировать память под нужный тип данных, резервируем в данном случае 112 байт
	int i, j, c; // объявляем переменные
	srand(time(0)); // добавляем сид для рандома
	for (i = 0; i < arrayWidth; i++) // идём по ширине массива
		for (j = 0; j < arrayLength; j++) //идём по длине массива
			*(pt + i*arrayWidth + j)= rand()%100 + 1; //задаём рандомные значения от 0 до 99, но в итоге у нас будет от 1 до 100

	for (i = 0; i < arrayWidth; i++) {
		for (j = 0; j < arrayLength; j++)
			printf("%d\n", *(pt + i*arrayWidth + j)); //выводим всё, что у нас есть
		printf("\n");  
    }
	free(pt);
	return 0;
}