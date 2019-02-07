#include<iostream>
#include<climits>
using std::cout; using std::cin;

int main()
{
  int Smallest=INT_MAX;
  int SecondSmallest=INT_MAX;
  int temp;
  while (cin >> temp)
  {
    if (temp < Smallest)
    {
      if (Smallest != INT_MAX)
      {
        SecondSmallest = Smallest;
      }
      Smallest = temp;
    }
    else if (temp < SecondSmallest && Smallest != temp)
    {
      SecondSmallest = temp;
    }
  }
  cout << "The Smallest Number is " << Smallest << "\n" << "The Second Smallest Number is " << SecondSmallest << "\n";
  return 0;
}
