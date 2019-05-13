#include<iostream>
#include<vector>
#include<string>
using namespace std;

void swap(char& a, char& b){
	char tmp = a;
	a = b;
	b = tmp;
}

vector<string> perms(string s){
	vector<string> p;
	if (s.length() < 2){
		p.push_back(s);
		return p; //base case
	}
	for (size_t i = 0; i < s.length(); i++){
		swap(s[0],s[i]);
		vector<string> T = perms(s.substr(1));
		for (size_t i = 0; i < T.size(); i++){
			p.push_back(s[0] + T[i]);
		}
	}
	
	return p;
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
	}
}

int main(){
	test();
	return 0;
}
