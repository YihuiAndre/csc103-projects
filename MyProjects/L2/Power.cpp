#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void display(int a[2][2]);

int main ()
{
  int n;
	int result[2][2];
	while(cin >> n){
		int a[2][2] = {{0,1},{1,1}}, b[2][2] = {{0,1},{1,1}};
		for (int s = 0; s < n; s++)
		{
			for (int i=0; i<2; i++) //first row
			{
				for (int k=0; k<2; k++)
				{
					result[i][k]=a[i][0]*b[0][k]+a[i][1]*b[1][k];
				}
			}
			for (int l=0; l<2; l++) //first row
			{
				for (int d=0; d<2; d++)
				{
				a[l][d]=result[l][d];
				}
			}
		}
		display(a);
	}

  return 0;
}

void display(int a[2][2])
{
	for (int i=0; i<2; i++)
	{
		for (int k=0; k<2; k++)
		{
			cout << a[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
