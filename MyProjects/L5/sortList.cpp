#include<iostream>
using namespace std;

void merge(int* A, int* B, size_t nA, size_t nB, int* S)
{
	size_t iA = 0;
	/* index of smallest unplaced item from A */
	size_t iB = 0;
	/* index of smallest unplaced item from B */
	size_t iS = 0;
	/* location to add next element into S */
	while (iA < nA && iB < nB) {
		/* both stacks have unplaced elements */
		if (A[iA] < B[iB]) S[iS++] = A[iA++];
		else S[iS++] = B[iB++];
	}
	/* either A or B has run out of elements.  add whatever is left: */
	while (iA < nA) S[iS++] = A[iA++];
	while (iB < nB) S[iS++] = B[iB++];
}

void mergeSort(int* A, size_t n, int* aux)
{
	if (n < 2) return;
	/* already sorted; nothing to do. */
	/* time for recursive magic: use our own function to
	* sort smaller sub-arrays: */
	mergeSort(A,n/2,aux);
	/* sort left sub-array */
	mergeSort(A+n/2,n-n/2,aux);
	/* sort right sub-array */
	/* merge results back into aux: */
	merge(A,A+n/2,n/2,n-n/2,aux);
	/* finally, copy from aux back into A: */
	for (size_t i = 0; i < n; i++)
		A[i] = aux[i];
}

/*
void merge(int* A, int* B, size_t nA, size_t nB, int* S)
{
	size_t a = 0;
	size_t b = 0;
	for (size_t s = 0; a<nA && b<nB; s++)
	{
		if (A[a] < B[b] && a<nA) S[s] = A[a++];
		else S[s] = B[b++];
	}
}
*/
/*
void sort(int* L, size_t x, int* A)
{
	if (x < 2) return;
	sort(L,x/2,A);
	sort(L+x/2,x-x/2,A);
	merge(L,L+x/2,x/2,x-x/2,A);
}
*/
int main()
{
	int A[8] = {5,2,3,7,2,1,4,6};
	int* B = new int[8];
	mergeSort(A, 8, B);
	for (int i = 0; i < 8; i++)
	{
		cout << A[i] << " ";
	}
	int D[3] = {1,2,3};
	for (int* i = D.begin(); i != i.end(); i++)
	{
		cout << *i << endl;
		break;
	}
	cout << "\n";
}



