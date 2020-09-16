#include <iostream>

//Программа для понимания меток. Работает в С и С++


using namespace std;

int main() {
	int a = 4;
	loop: // label. can be anywhere
		if (a != 40) {
			a+=4;
			goto loop; // goto label "loop"
		} else cout << "Got it!\n";
	cout << a << "\n";
	return 0;
}
