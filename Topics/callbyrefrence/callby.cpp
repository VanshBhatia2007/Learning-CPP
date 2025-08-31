#include <iostream>
using namespace std;

int update(int x) {
	x = 2;
    return x;
}

int main() {

	int a = 1;

	cout << "Before update: " << a << endl;

	 int b= update(a);

	cout << "After update: " << b << endl;

	return 0;
}