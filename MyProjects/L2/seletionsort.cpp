#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<stdio.h>
#include<climits>

void display(int L[], int len);

int main()
{
  const unsigned int length = sizeof(unsort)/4;
  int Loc;
  for (size_t i = 0; i < length; i++) // fix the variable
  {
    int Smallest = INT_MAX;
    for (size_t j = i; j < length; j++) // search the rest except unsort[i]
    {
      if (Smallest > unsort[j]) // if unsort[j] has smallest value record it
      {
        Smallest = unsort[j];
        Loc = j; //location
      }
    }
    unsort[Loc]=unsort[i];
    unsort[i]=Smallest;
  }
  display(unsort, length);
  return 0;
}

void display(int L[], int len)
{
  for (size_t k = 0; k < len; k++)
  {
    printf("%d ",L[k]);
  }
  printf("\n");
}