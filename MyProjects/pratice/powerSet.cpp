#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> powerSet(vector<int>& S)
{
	vector<vector<int>> res;
	if (S.size() == 0){
		res.push_back(vector<int> ());
		return res;
	}
	int tmp = S.back();
	S.pop_back();
	res = powerSet(S);
	size_t psize = res.size();
	for (size_t t = 0; t < psize; t++){
		vector<int> V = res[t];
		V.push_back(tmp);
		res.push_back(V);
	}
	S.push_back(tmp);
	return res;
}

void display(vector<vector<int>> V)
{
	for (size_t t = 0; t < V.size(); t++){
		for (size_t i = 0; i < V[t].size(); i++){
			cout << V[t][i] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	vector<int> S = {1,2,3};
	vector<vector<int>> V = powerSet(S);
	display(V);
	return 0;
}
