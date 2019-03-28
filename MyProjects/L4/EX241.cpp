//Write a C++ function to \grow" an array, while preserving its contents.
#include<iostream>
using namespace std;

void grow(int*& A, int oldsize, int newsize);

int main()
{
	int* A = new int[3];
	cout << &A << endl;
	grow(A,3,9);
	cout << &A << endl;
	delete[] A;
	return 0;
}

void grow(int*& A, int oldsize, int newsize)
{
	int* B = new int[newsize];
	cout << B << endl;
	for (int i = 0; i < oldsize; i++)
	{
		B[i] = *A;
		cout << *A << " ";
		A++;
	}
	&A = B;
	cout << &A << endl;
	cout << *A << endl;
}

