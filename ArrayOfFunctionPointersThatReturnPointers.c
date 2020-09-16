#include <stdio.h>

// 
// Программа для понимания массивов указателей на функции, которые возвращают указатель на значение
// 

int *sayHi() {
	static int iarr[9] = {1,2,3,4,5,6,7,8,9};
	printf("Hi!\n");
	return iarr;
}
int *sayHello() {
	static int iarr[9] = {1,2,3,4,5,6,7,8,9};
	printf("Hello!\n");
	return iarr;
}
int *sayGoodEvening() {
	static int iarr[9] = {1,2,3,4,5,6,7,8,9};
	printf("Good Evening\n");
	return iarr;
}

int main() {
	int *(*arr[3])() = {sayHi, sayHello, sayGoodEvening};
	for (int i = 0; i < 3; i++)
		printf("%d\n",(*arr[i])()[7]);
	return 0;
}