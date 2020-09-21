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
* Console "screensaver" in Matrix style
* 
*/
#define SCREEN_SIZE 320*84 
#define SCREEN_WIDTH 320 
#define SCREEN_HEIGTH 84 
#define DROPRATE 1000 //define in ppm
#define DROPSIZE 15 //drop length

COORD size = {SCREEN_WIDTH, SCREEN_HEIGTH}; // info for window creation
SMALL_RECT rekt = {0,0,SCREEN_WIDTH - 1,SCREEN_HEIGTH - 1};

char screen[SCREEN_SIZE] = {0}; //output buffer
byte drops[SCREEN_SIZE] = {0}; // drop length buffer

int main() {
	srand(0);
	DWORD charsWritten;
	HWND handle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, 0, CONSOLE_TEXTMODE_BUFFER, 0); // make a console window
	SetConsoleActiveScreenBuffer(handle); // make an allocated handle active
	SetConsoleTitle("MATRIX"); // change the window title
	SetConsoleScreenBufferSize(handle, size); // set console screen buffer size in characters
	SetConsoleWindowInfo(handle, 1, &rekt); // set window size in characters
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // make all printable symbols green
	byte temp; // temporary variable
	while (1) {
		for (int i = 0; i < SCREEN_WIDTH; i++) { // the first cycle defines the drop length
			if (rand()%1000000 <= DROPRATE) {
				drops[i] = rand()%DROPSIZE;
			}
		}
		
		for (int i = 0; i < SCREEN_SIZE; i++) { // the second cycle sets a character to print
			if (drops[i] > 0) 
				screen[i] = 33 + rand()%94;
			else
				screen[i] = ' ';
		}
		
		for (int i = SCREEN_SIZE - 1; i > SCREEN_WIDTH - 1; i--) { // the third cycle copies and assigns values of drops to a lower row
			temp = drops[i-SCREEN_WIDTH];
			drops[i] = temp;
		}
		
		for (int i = 0; i < SCREEN_WIDTH; i++) { // the fourth cycle decrements all the values, which are > 0 in the first row
			if (drops[i] > 0) drops[i] -= 1;
		}
		
		WriteConsole(handle, screen, SCREEN_SIZE, &charsWritten, 0); // print image
		Sleep(50); //çàäåðæêà
	}
	return 0;
}
