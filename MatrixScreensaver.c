#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

/*
* MATRIX
* 
* By me in 2020
* 
* 08.06.2020
* 
* ���������� "�����������" � ����� �������
* ��� ������ ������ � WinAPI
*/
#define SCREEN_SIZE 320*84 
#define SCREEN_WIDTH 320 
#define SCREEN_HEIGTH 84 
#define DROPRATE 1000 //define in ppm
#define DROPSIZE 15 //drop length

COORD size = {SCREEN_WIDTH, SCREEN_HEIGTH}; // ���������� ��� �������� ����

SMALL_RECT rekt = {0,0,SCREEN_WIDTH - 1,SCREEN_HEIGTH - 1};

char screen[SCREEN_SIZE] = {0}; //����� ������ 
byte drops[SCREEN_SIZE] = {0}; // ����� ����

int main() {
	srand(0);
	DWORD charsWritten;
	HWND handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, 0, CONSOLE_TEXTMODE_BUFFER, 0); // ������ �������
	SetConsoleActiveScreenBuffer(handle); // ������ ���������� ������� ��������
	SetConsoleTitle("MATRIX"); // �������� ��������� ����
	SetConsoleScreenBufferSize(handle, size); // ����� ������ ��������� ������ � ��������
	SetConsoleWindowInfo(handle, 1, &rekt); // ����� ������ ���� � ��������
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // ������ ��� ��������� ������� �������
	byte temp;
	while (1) {
		for (int i = 0; i < SCREEN_WIDTH; i++) { //������ ���� ����� ����� ������
			if (rand()%1000000 <= DROPRATE) {
				drops[i] = rand()%DROPSIZE;
			}
		}
		
		for (int i = 0; i < SCREEN_SIZE; i++) { // ������ ���� ����� ������ ��� ������ ������
			if (drops[i] > 0) 
				screen[i] = 33 + rand()%94;
			else
				screen[i] = ' ';
		}
		
		for (int i = SCREEN_SIZE - 1; i > SCREEN_WIDTH - 1; i--) { // ������ ���� �������� � ����������� �������� ������ �� ������ ����
			temp = drops[i-SCREEN_WIDTH];
			drops[i] = temp;
		}
		
		for (int i = 0; i < SCREEN_WIDTH; i++) { // �������� ���� ��������� ��� �������� � ������ ������, ������� > 0
			if (drops[i] > 0) drops[i] -= 1;
		}
		
		WriteConsole(handle, screen, SCREEN_SIZE, &charsWritten, 0); // ����� �����������
		Sleep(50); //��������
	}
	return 0;
}