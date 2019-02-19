#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iostream>

int main ()
{
  int Row;
  cin >> Row;
  int Col = 2*Row-1; //n th term
  int result[Row][Col];
  int LHS, RHS;
  for (int r = 0; r < Row; r++)
  {
    for (int i = 0; i < Col; i++)
    {
      result[r][i] = 0;
    }
  }

  for (int r = 0; r < Row; r++)
  {
    for (int c = 0; c < Col; c++)
    {
      if ((r == 0 && c == Col/2) || (r == Row - 1 && (c == 0 || c == Col - 1) )) result[r][c] = 1;
      else if (r != 0 && (c != 0 || c != Col - 1))
        {
          LHS = result[r-1][c-1], RHS = result[r-1][c+1];
          if (LHS != 0 && RHS != 0 && c != Col-1)
            {
              result[r][c] = result[r-1][c-1] + result[r-1][c+1];
            }
          else if ((LHS != 0 || RHS != 0) && c-1 != -1 ) result[r][c] = 1;
        }
    }
  }

  for (int r = 0; r < Row; r++)
  {
    for (int c = 0; c < Col; c++)
    {
      if (result[r][c] == 0) cout << " ";
      else cout << result[r][c];
    }
    cout << endl;
  }
}





