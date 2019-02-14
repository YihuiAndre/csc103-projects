#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<climits>

void sort(int x[], int len);

int main()
{
  int min; //determine the smallest
  int unsort[] = {-3,2,-5,2,-1,4};

  int Smallest = INT_MAX;
  int Loc;
  for (int i = 0; i < sizeof(unsort)/4; i++)
  {
    for (int j = i; j < sizeof(unsort)/4; j++)
    {
      if (Smallest > unsort[j])
      {
        Smallest = unsort[j];
        Loc = j;
      }
    }
    unsort[Loc]=unsort[i];
    unsort[i]=Smallest;
    Smallest = INT_MAX;
  }
  for (int k = 0; k < sizeof(unsort)/4; k++)
    {
      cout << unsort[k] << " ";
    }
}
