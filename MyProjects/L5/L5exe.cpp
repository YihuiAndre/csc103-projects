#include<iostream>
#include<vector>
#include<string>
using namespace std;

int power(int a,int b){ //b is power
	if (b == 0) return 1;
	return a * power(a,b-1);
}

void reverse(int a){
	if (a < 10){
		cout << a;
		return;
	}
	int base = 10;
	while(a%(base*10) != a)
	{
		base *= 10;
	}
	reverse(a%base);
	cout << a/base;
}

bool search(int* A, size_t n, int x){
	if (n == 0) return false;
	size_t LHS = 0;
	size_t RHS = n;
	size_t middle = (LHS+RHS)/2;
	if (A[middle] == x) return true;
	else if(A[middle] < x) search(A+middle+1, n/2, x);
	else search(A,n/2,x);
}

vector<int> merge(vector<int> A, vector<int> B){
	vector<int> result = {};
	size_t indexA = 0, indexB = 0;
	while(indexA < A.size() && indexB < B.size()){
		if (A[indexA] < B[indexB]) result.push_back(A[indexA++]);
		else result.push_back(B[indexB++]);
	}
	while (indexA < A.size()) result.push_back(A[indexA++]);
	while (indexB < B.size()) result.push_back(B[indexB++]);
	return result;
}

void mergeSort(vector<int>& A){
	if (A.size() <= 1) return;
	vector<int> firstH, secondH, sortL;
	for (int a = 0; a < A.size(); a++){
		if (a < A.size()/2) firstH.push_back(A[a]);
		else secondH.push_back(A[a]);
	}
	mergeSort(firstH);
	mergeSort(secondH);
	sortL = merge(firstH,secondH);
	for (size_t k = 0; k < A.size(); k++){
		A[k] = sortL[k];
	}
	return;
}

void swap(int* a, int* b){
	int tmp = a;
	a = b;
	b = tmp;
}

vector<vector<string>> perms(vector<string> S){
	vector<vector<string>> T;
	if (S.size() <= 1){
		T.push_back(S);
		return T;
	}
	vector<string> tmp;
	vector<vector<string>> P;
	for (size_t i = 0; i < S.size(); i++){
		swap(S[0],S[i]);
		tmp = S;
		P = perms(tmp.pop_back());
		for (size_t k = 0; k < P.size(); k++)
			P[0] += S[0];

	}

}


int main(){
	cout << power(2,3) << endl;
	reverse(1234);
	cout << "\n";
	int A[5] = {1,2,3,4,5};
	cout << search(A,5,100) << "\n";
	vector<int> B = {5,4,3,2,1};
	mergeSort(B);
	return 0;
}
