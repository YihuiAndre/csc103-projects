#include<iostream>
#include<vector>
#include<string>
using namespace std;

string swap(string A, int a){
	char s = A[a];
	A[a] = A[0];
	A[0] = s;
	return A;
}

vector<string> perms(string s){
	if (s.length() < 2){
		vector<string> F;
		F.push_back(s);
		return F; //base case
	}
	string P; //store output
	char C = s[0]; //first character
	vector<string> S = perms(s.substr(1)); //IS
	size_t len = S.size(); //set the length
	for (size_t k = 0; k < S.size(); k++)
	{
		S[k] = C + S[k]; //add the first char first
		
	}
	for (size_t i = 0; i < len; i++){
		for (size_t k = 0; k < s.length()-1; k++){
			P = swap(S[i], k+1); //
			S.push_back(P);
		}
	}
	
	return S;
}

void display(vector<string> S){
	for (size_t i = 0; i < S.size(); i++){
		cout << S[i] << " ";
	}
	cout << "\n";
}

void test(){
	string a;
	vector<string> R;
	while (cin >> a){
		R = perms(a);
		display(R);
		R = {};
	}
}

int main()
{
	test();
}

