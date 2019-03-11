#include<iostream>
using namespace std;

int main() {
	long *p1, *p2, x1 = 3, x2 = 2;
	p1 = &x1;
	p2 = &x2;
	cout << x1 << " " << *p1 << " "
	<< x2 << " " << *p2 << endl;
	p1 = p2;
	cout << x1 << " " << *p1 << " "
	<< x2 << " " << *p2 << endl;
	x2++;
	cout << x1 << " " << *p1 << " "
	<< x2 << " " << *p2 << endl;
	p2 = &x1;
	x1 = 10;
	x2 = 23;
	cout << x1 << " " << *p1 << " "
	<< x2 << " " << *p2 << endl;
	return 0;
}


