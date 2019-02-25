#include<iostream>
#include<vector>
using namespace std;

vector<int> even(vector<int> k);
void display(vector<int>& k);

int main()
{
	vector<int> g = {1,3,5,2,7,8,12};
	display(g);
	vector<int> e = even(g);
	display(e);
	return 0;
}

vector<int> even(vector<int> k)
{
    vector<int> n;
    for (size_t a = 0; a < k.size(); a++)
    {
        if (k[a] % 2 == 0) n.push_back(k[a]); 
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
