#include<iostream>
#include<vector>
using namespace std;

void reverse(vector<int>& k);
void display(vector<int>& k); //display the list

int main()
{
	vector<int> g;
	g.push_back(12);
	g.push_back(13);
	g.push_back(11);
	display(g);
	reverse(g);
	display(g);
	return 0;
}

void reverse(vector<int>& k)
{
    int s; // temper interger use for switch the value
    for (size_t a = 0; a < k.size()/2; a++)
    {
        s = k[a];
        k[a] = k[k.size()-(1+a)];
        k[k.size()-(1+a)] = s;
    }
}

void display(vector<int>& k)
{
    for (size_t a = 0; a < k.size(); a++)
    {
        cout << k[a] << " ";
    }
    cout << endl;
}
