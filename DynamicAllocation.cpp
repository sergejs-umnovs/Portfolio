#include <iostream>

// Программа для понимания того, как происходит выделение динамической памяти в С++
using namespace std;

int main() {
	int **arrOfArrs = new int*[4]; // arr of pointers
	for(int i = 0; i < 4; i++) { // loop to
		*(arrOfArrs+i) = new int[4] {1+4*i,2+4*i,3+4*i,4+4*i}; // create arrs and fill them
	}
	
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cout << *(*(arrOfArrs+i)+j) << endl; // print 'em
	return 0;
}
