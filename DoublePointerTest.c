#include <stdio.h>
// 
// Программа для понимания указателей - обычных и двойных
// 

int main() {
	int var = 9; // the value pointed to
	int *ptr1 = &var; // the pointer to var
	printf("%d - \"ptr1\" pointing to \"var\" firstly\n",*ptr1);
	printf("%x - adress of \"var\"\n%x - adress of \"var\" stored in \"ptr1\"\n", &var, ptr1);
	printf("%x - adress of \"*ptr1\" in memory\n\n", &ptr1);
	
	int *ptr2 = ptr1; // ptr1 is already an adress
	printf("%d - \"*ptr2\" pointing to \"ptr1\"\n", *ptr2);
	printf("%x - check if adress pointed to is the same as var has\n", ptr2); // it is
	printf("%x - adress of \"*ptr2\" in memory\n\n", &ptr2);
	
	*ptr2 = 23; // it is possible to change the variable pointed to through pointer to pointer's value (that is an adress)
	printf("%d - trying to change value of \"var\" through pointer to pointer's value\n\n", *ptr2);
	
	int *test = ptr2; // pointing to what *ptr2 has, that is pointing to what *ptr1 has, that is pointing to var that is equal to 9
	printf("%d - value of pointed to by \"*test\", %x - adress of pointed to by \"*test\"\n", *test, test);
	printf("%x - adress of \"*test\" pointer in memory\n\n\n", &test);
	
	
	int newVar = 8; // set a new variable
	int *newPtr = &newVar; // point to it
	printf("%d - value of \"newVar\" pointed to by \"*newPtr\",\n", *newPtr);
	printf("%x - memory adress of pointer outputted using \"&\",\n%x - adress value kept in pointer outputted without \"&\"\n",&newPtr,newPtr);
	printf("%d - size of int \"newVar\", %d - size of \"*newPtr\", all are int\n\n", sizeof(newVar), sizeof(newPtr));
}
