#include<iostream>
using namespace std;

int main()
{
  int grade;
  while (cin >> grade)
  {
    switch(grade/10)
    {
      case 9 || 8:
        cout << "you get a A" << endl;
        break;
      case 5:
        cout << "you get a A" << endl;
        break;
      case 7:
        cout << "you get a B" << endl;
        break;
      case 6:
        cout << "you get a B" << endl;
        break;
      default:
        cout << "I have no idea what you say" << endl;
        break;
    }
  }
  return 0;
}