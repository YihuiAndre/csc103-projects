#include<iostream>
#include<climits>
using std::cout; using std::cin;

int main()
{
  int SmallNum=INT_MAX;
  int temp;
  while (cin >> temp)
  {
    if (temp < SmallNum)
    {
      SmallNum = temp;
    }
  }
  cout << SmallNum << "\n";
  return 0;
}