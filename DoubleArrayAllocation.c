#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define arrayLength 4 // ���. ����� �������
#define arrayWidth 7 // ���. ������ �������

// 
// ��������� ��� �������� ��������� ������������ �������� 
// 

int main() {
	
	int *pt = (int *) malloc(arrayLength * arrayWidth * sizeof(int)); 
	//�����   ��������������, ���� ��������������� ������ ��� ������ ��� ������, ����������� � ������ ������ 112 ����
	int i, j, c; // ��������� ����������
	srand(time(0)); // ��������� ��� ��� �������
	for (i = 0; i < arrayWidth; i++) // ��� �� ������ �������
		for (j = 0; j < arrayLength; j++) //��� �� ����� �������
			*(pt + i*arrayWidth + j)= rand()%100 + 1; //����� ��������� �������� �� 0 �� 99, �� � ����� � ��� ����� �� 1 �� 100

	for (i = 0; i < arrayWidth; i++) {
		for (j = 0; j < arrayLength; j++)
			printf("%d\n", *(pt + i*arrayWidth + j)); //������� ��, ��� � ��� ����
		printf("\n");  
    }
	free(pt);
	return 0;
}