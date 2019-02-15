#include<iostream>
using namespace std;

int fib(int x);

int main()
{
  int n;
  while (cin >> n)
  {
    cout << fib(n) << endl;
  }
}

int fib(int x)
{
  if (x == 0 || x == 1)
  {
    return 1;
  }
  else
  {
    return fib(x-1) + fib(x-2);
  }
}