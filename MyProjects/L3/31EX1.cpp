#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& k, int s);

int main(){
	vector<int> g;
	g.push_back(12);
	g.push_back(13);
	g.push_back(111);
	cout << search(g, 13) << endl;
	return 0;
}

bool search(vector<int>& k, int s)
{
    for (size_t a = 0; a < k.size(); a++)
    {
        if (k[a] == s) return 1;
    }
    return 0;
}
