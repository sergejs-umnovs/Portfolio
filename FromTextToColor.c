#include <conio.h>
#include <stdio.h>
#include <windows.h>

// 
// ��������� ��� ������ �� ����� �������� �����������, �������� ������ � ������� windows
// 
// �������� ���� � ��������� "sprite.txt" � ��� �� �����, ��� ��������� ���������������� ���������, ���������� � ��������
// RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1-RGI1RGI111RGI1RGI111RGI1RGI1-RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1-11RGI1RGI1RGI1RGI1RGI1RGI111-RGI1RGI1111111RGI1RGI1c 
// � ���� ����. ��� ������� � ��� ������ ������������ ��������
// � ����, ��� ����� ������������, �� � ��� ��� �����

int main() {
	DWORD color = 0; //										- WinAPI ������ int ��� �������� �����								- 
	FILE *fp = fopen("sprite.txt", "r"); //					- ��������� ����
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // 	- ����� �������� ������, ����� �������� �������
	for (;;) { //											- ������ ����������� ����
		switch(fgetc(fp)) {	//								- ����������� ��� ������� � ������� switch
		
		case 'R':
		color |= BACKGROUND_RED; //							- ���� ��������� ������ - 'R', �� ����������� ������� � ���������� �����
		//printf("%d\n", color);
		break;
		
		case 'G':
		color |= BACKGROUND_GREEN; //						- ���� ��������� ������ - 'G', �� ����������� ������ � ���������� �����
		//printf("%d\n", color);
		break;
		
		case 'B':
		color |= BACKGROUND_BLUE; //						- ���� ��������� ������ - 'B', �� ����������� ����� � ���������� �����
		//printf("%d\n", color);
		break;
		
		case 'I':
		color |= BACKGROUND_INTENSITY; //					- ���� ��������� ������ - 'I', �� ������ ���� �������
		//printf("%d\n", color);
		break;
		
		case '1':
		SetConsoleTextAttribute(handle, color); //			- ���� ��������� ������ - '1', �� ������� ������� ������
		printf("%c",' '); /*								- � WinAPI ���� 2 ���� ������ ��������, ���� �� ������� �������� �� ���� ������� ����, � ������ - �� ����
		//printf("%d\n", color);							��������. ����� ���������� ������ ���, ����� ������� ������ ' '*/
		color = 0; //										- ���������� ����, ����� ��� ������
		break;
		
		case '-': //										- ���� ��������� ������ - '-', �� ��������� �� ��������� ������ � ���������
		printf("\n");
		break;
		
		case 'c': //										- ���� ��������� ������ - '�', �� ��� ������, ��� ���� ���������� � ������� �������� ����
		break;
		}
		
	}
	getch();
	return 0;
}