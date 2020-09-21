#include <conio.h>
#include <stdio.h>
#include <windows.h>

// 
// Program, which prints a colored text picture. Works only in Windows.
// 
// Make a text file named "sprite.txt" in the same directory as the program, copy and paste
// RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1-RGI1RGI111RGI1RGI111RGI1RGI1-RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1RGI1-11RGI1RGI1RGI1RGI1RGI1RGI111-RGI1RGI1111111RGI1RGI1c 
// into the text file. The program should print a colored picture in the console window
// I know, the picture code is barely readable, but the program needs this code to print an image

int main() {
	DWORD color = 0; // WinAPI DWORD size is equal to int size								- 
	FILE *fp = fopen("sprite.txt", "r"); // open the picture file
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // we need a window handle to color a "pixel"
	for (;;) { // make an infinite loop
		switch(fgetc(fp)) {
		
		case 'R':
		color |= BACKGROUND_RED; // if the next symbol is 'R', then add red to a color variable
		//printf("%d\n", color);
		break;
		
		case 'G':
		color |= BACKGROUND_GREEN; // if the next symbol is 'G', then add green to a color variable
		//printf("%d\n", color);
		break;
		
		case 'B':
		color |= BACKGROUND_BLUE; // if the next symbol is 'B', then add blue to a color variable
		//printf("%d\n", color);
		break;
		
		case 'I':
		color |= BACKGROUND_INTENSITY; // if the next symbol is 'I', then make the color bright
		//printf("%d\n", color);
		break;
		
		case '1':
		SetConsoleTextAttribute(handle, color); // if the next symbol is '1', then print the colored pixel
		printf("%c",' '); // WinAPI has two types of symbol colors, one of them defines the text color, and the second defines the background color
				// we just need to print ' ' to add a "pixel" to the picture on the screen
		color = 0; // reset the color variable, to make it black
		break;
		
		case '-': // if the next symbol is 'I', then make a new line in the console screen
		printf("\n");
		break;
		
		case 'c': // if the next symbol is 'I', then it means that there's no more data in the file and the cycle should be broken
		break;
		}
		
	}
	getch();
	return 0;
}
