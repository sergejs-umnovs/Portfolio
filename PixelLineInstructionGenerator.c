#include <stdio.h>
#include <math.h>
#include <conio.h>
#define PI 3.141592

// 
// ��������� ��� ��������� ���������� �� ��������� ���������� ��������
// ����� ���� ��� ��� ������������� � Minecraft

int main() {
    float angle, tg, count = 0;																	// ��� ����������� ����������
    int i, width;																				// 
	printf("Enter angle between ground and line (in degrees) and line horizontal width : ");	// 
    scanf("%f %d", &angle, &width);																// ����
    angle = angle * PI/180;																		// �������������� �������� � �������
    tg = tanf(angle);																			// 
    for (i = 1; i <= width; i++){																// ����, � ������� ������������ ����������
        count += tg;																			// ��������� ������� ���� � ���������� ���������� ������
        printf("%d block is %d blocks in height\n", i, (int)floor(count));						// ������� ������ ���������� � ����� ������ ������
        count = count - floor(count);															// ��������	����� ����� �� ���������� ���������� ������
    }
	getch();																					// ������ ��������� �� "�����"
    return 0;
}