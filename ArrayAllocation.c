#include <stdio.h>
#include <stdlib.h>
#define SIZE 14

//
// ���������, ���������� �� �������� ������� malloc � ������������ ��������
//


int main() {
	int array[SIZE] = {}; //									- ���������� ����������� ������
	int *array2 = (int*)malloc(SIZE * sizeof(int)); //			- ���������� ������������ ������
	printf("size of normal array %d\n",sizeof(array)); //		- ������� ������ ������������ �������
	printf("size of generated array %d\n\n",sizeof(array2));//	- ������� ������ ��������� �� ���������� ������
	for(int i = 0; i < SIZE; i++) { //							- ��������� ����������� ������ � ������������ ������
		array[i] = i;
		*(array2+i) = 2*i;
	}
	printf("Contents of normal array:\n");
	for(int i = 0; i < SIZE; i++) { //							- ������� ������ ������������ �������, � ������ ������ ������ ������: 0 1 2 3 4 5 6 7 8 9 10 11 12 13
		printf("%d ",array[i]);
	}
	printf("\nContents of generated array:\n"); 
	for(int i = 0; i < SIZE; i++) { //							- ������� ������ ������������� �������, � ������ ������ ������ ������: 0 2 4 6 8 10 12 14 16 18 20 22 24 26
		printf("%d ",*(array2+i));
	}
	free(array2); //											- ����������� ���������� ������ 
	
	return 0;
}