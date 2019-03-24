#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> V;
	while(cin >> n)
	{
		if (n%2==0) cout << n << " ";
		else V.push_back(n);
	}
	cout << endl;
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}
	cout << endl;d

	return 0;
}

