#include <stdio.h>
#include <conio.h>

// 
// Программа вычисления квадратного корня методом брутфорса
// 

int main() {
	printf("Enter number and iteration limit\n");
	int isquare, ilimit;
	int intpart = 1;
	int previntpart = 0;
	int squareistwo = 0;
	int resultisint = 0;
	double part = 2.0;
	double result = 0;
	scanf("%d %d", &isquare, &ilimit);
	int square = isquare;
	//for (int i = 0; i < ilimit; i++) { //separate integer part
	while (isquare - (intpart*intpart - previntpart*previntpart) > 0 && squareistwo != 1) {
		if (isquare - (intpart*intpart - previntpart*previntpart) > 1 && squareistwo != 1) {
			result += 1.0;
			isquare -= intpart*intpart - previntpart*previntpart;
			previntpart = intpart;
			intpart++; 
		}
		if (isquare - (intpart*intpart - previntpart*previntpart) == 0 && squareistwo != 1) {
			printf("Looks like its an integer root\n");
			result += 1.0;
			isquare -= intpart*intpart - previntpart*previntpart;
			resultisint = 1;
		}
		if (isquare - (intpart*intpart - previntpart*previntpart) == 1 && squareistwo != 1) {
			result += 1.0;
			squareistwo = 1;
		}
	}
	for (int i = 0; i < ilimit && resultisint == 0; i++) {
				result += 1/part;
			if (result*result > square) {
				result-=1/part;
				part*=2;
			} else {
				part*=2;
			}
	}
	printf("Square root is %.16lf", result);
	getch();
	return 0;
}