#include<iostream>
#include<vector>
#include<limits.h>
#include<string>
using namespace std;

bool isP (const string& str);
void reverse (string& s);
void swap (char& a, char& b);

int main()
{
	string s = "ABCCBA2";
	cout << isP(s) << endl;
	reverse(s);
	cout << s  << endl;
}

bool isP (const string& str)
{
	for (size_t i = 0; i < str.length()/2; i++)
	{
		if (str[i] != str[str.length()-i-1]) return false;
	}
	return true;
}

void reverse (string& s)
{
	for (size_t i = 0; i < s.length()/2; i++)
	{
		swap(s[i],s[s.length()-1-i]);
	}
}

void swap (char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

