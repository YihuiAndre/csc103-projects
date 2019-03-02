#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int f(vector<int> c,int x);

int main()
{
	vector<int> v = {1,3,3,1};
	int num = 1;
	cout << f(v,num) << endl;
	return 0;
}


int f(vector<int> c,int x)
{
	int sum = 0;
	for (size_t i = 0; i < c.size(); i++)
	{
		sum += c[i]*pow(x,i);
	}
	return sum;
}
