#include <stdio.h>
#include <conio.h>

// 
// Program, which prints numbers in binary in a for loop
// 

void printBin(unsigned int number) { // don't need to return anything
	unsigned int temp = number >> 24; // a variable to store binary shift result. Get the most significant byte value of the function argument
	printf("%d%d%d%d%d%d%d%d ", (temp & 128) == 128, (temp & 64) == 64, (temp & 32) == 32, (temp & 16) == 16, (temp & 8) == 8, (temp & 4) == 4, (temp & 2) == 2, temp & 1);
	temp = number >> 16; // get second most significant byte of the function argument
	printf("%d%d%d%d%d%d%d%d ", (temp & 128) == 128, (temp & 64) == 64, (temp & 32) == 32, (temp & 16) == 16, (temp & 8) == 8, (temp & 4) == 4, (temp & 2) == 2, temp & 1);
	temp = number >> 8; // get third most significant byte of the function argument
	printf("%d%d%d%d%d%d%d%d ", (temp & 128) == 128, (temp & 64) == 64, (temp & 32) == 32, (temp & 16) == 16, (temp & 8) == 8, (temp & 4) == 4, (temp & 2) == 2, temp & 1);
	temp = number; // get least significant byte of the function argument
	printf("%d%d%d%d%d%d%d%d\n", (temp & 128) == 128, (temp & 64) == 64, (temp & 32) == 32, (temp & 16) == 16, (temp & 8) == 8, (temp & 4) == 4, (temp & 2) == 2, temp & 1);
} // printing functions work with least significant byte of the variable

int main() {
	for (int i = 0; i <= 65536; ++i) // print i value in binary via the function in a for loop
		printBin(i);
	getch(); // pause the program to see the result
	return 0;
}
