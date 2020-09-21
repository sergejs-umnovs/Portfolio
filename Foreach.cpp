#include <iostream>


// Program, which explains foreach loop

using namespace std;

struct container {
	int num1,num2;
};


int main() {
	cout << "int var array printing..." << endl;
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	for(int point : arr) { //outputting via int variable
		cout << point << endl;
	}
	
	cout << "auto with var array printing..." << endl;
	float arrf[10] = {1.2,2.3,3.4,4.5,5.6,6.7,7.8,8.9,9.1,10.2};
	for(auto point : arrf) {
		cout << point << endl;
	}
	
	cout << "auto reference float array printing..." << endl;
	float arrf2[5] = {1.2,3.4,5.6,7.8,9.0};
	for(auto &point : arrf2) {
		cout << point << endl;
	}
	
	cout << "reference struct array printing..." << endl;
	struct container ARR[4] = {{1,2},{3,5},{123,6},{34,6}};
	for(struct container &point : ARR) {
		cout << point.num1 << endl;
		cout << point.num2 << endl;
	}
	
	return 0;
}
