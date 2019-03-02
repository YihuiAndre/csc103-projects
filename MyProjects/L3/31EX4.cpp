#include<iostream>
#include<vector>
using namespace std;

vector<int> unique(vector<int> k);
void display(vector<int>& k);

int main()
{
	vector<int> g = {1,2,2,3,3,3,4,5,6,7,7,7};
	display(g);
	vector<int> e = unique(g);
	display(e);
	return 0;
}

vector<int> unique(vector<int> k)
{
    vector<int> n;
    for (size_t a = 0; a < k.size(); a++)
    {
        if (k[a] != k[a+1]) n.push_back(k[a]); 
    }
    return n;
}

void display(vector<int>& k)
{
    for (size_t a = 0; a < k.size(); a++)
    {
        cout << k[a] << " ";
    }
    cout << endl;
}
