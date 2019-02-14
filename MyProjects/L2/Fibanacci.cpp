#include<iostream>
using std::cout;
using std::cin;
using std::endl;


int main()
{
  int n=3; //user input
  int LHS=0; //left hand side of fibonacci sequence
  int RHS=1; //right hand side of fibonacci sequence
  //cin >> n; //input the nth term
  for (int i = 0; i < n; i++)
  {
    RHS = LHS + RHS;
    LHS = RHS - LHS;
  }
  cout << "The fibanacci number is " << RHS << endl;
  return 0;
}