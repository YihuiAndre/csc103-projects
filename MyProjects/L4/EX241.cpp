//Write a C++ function to \grow" an array, while preserving its contents.
#include<iostream>
using namespace std;

void grow(int*& A, int oldsize, int newsize);

int main()
{
	int* A = new int[3];
	A[0] = 2;
	A[1] = 3;
	cout << A << " " << *&A << endl;
	grow(A,3,9);
	cout << A << endl;
	cout << A[0] << " " << A[1] << endl;
	cout << "__________________" << endl;
	int n, index=0; //input and index
	int oldSize = 3;
	int *C= new int[oldSize];
	while (cin >> n)
	{
		if (index == oldSize)
		{
			grow(C,oldSize,oldSize*2);
			oldSize *= 2;
		}
		C[index] = n;
	}
	return 0;
}

void grow(int *&A, int oldsize, int newsize)
{
	int* B = new int[newsize];
	cout << "B: " << B << endl;
	for (int i = 0; i < oldsize; i++)
	{
		B[i] = A[i];
	}
	delete[] A;
	A = B;
	cout << B << " " << A << endl;
}

