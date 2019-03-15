#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void sort(vector<int> &n);
void swap(int& a, int& b);

int main()
{
	vector<int> v = {9,8,7,6,5,4,3,2,1};
	int n, small = INT_MAX, S_small;
	while(cin >> n)
	{
		if (small > n)
		{
			S_small = small;
			small = n;
		}
		else if (S_small > n && n != small)
		{
			S_small = n;
		}
	}
	cout << S_small << endl;
	sort(v);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

void sort(vector<int> &n)
{
	for (size_t i = 0; i < n.size()-1; i++)
	{
		size_t sIndex = i;
		for (size_t k = i; k < n.size(); k++)
		{
			if (n[sIndex] > n[k])
			{
				sIndex = k;
			}
		}
		swap(n[sIndex], n[i]);
	}
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

