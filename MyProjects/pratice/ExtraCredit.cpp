
#include<iostream>
using namespace std;

void func(int n, int b = 2)
{
	int remain;
	while (n > 0)
	{
		remain = n / b;
		if (remain%b!=0 && n%b!=0)
		{
			n++;
			remain = n/b;
			cout << -1 << " ";
		}
		else
		{
			cout << n%b << " ";
		}
		n = remain;
	}
	cout << "\n";
}

void Other_func(int n, int b = 2)
{
	if (n == 0 || n == 1) cout << n << " ";
	else {
		if ((n/b)%b != 0 && n%b != 0)
		{
			n++;
			cout << -1 << " ";
		}
		else cout << n%b << " ";
		Other_func(n/b);
	}
}


int main()
{
	int n;
	while (cin >> n)
	{
		cout << "This is from func with while loop" << "\n";
		func(n);
		cout << "This is from Other_func with recursion" << "\n";
		Other_func(n);
		cout << "\n";
	}
}
