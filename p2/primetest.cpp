/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: readme.html,
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include<cmath>
using std::sqrt;

int main()
{
 unsigned long n; //user input
 unsigned long init=5; //Beginning value
 while (cin >> n)
 {
  if (n == 2) cout << 1 << endl;
  //if integer is 0 or 1, return 1
  else if (n % 2 == 0 || n % 3 == 0 || n == 1) cout << 0 << endl;
  //if integer is 1 or divisible by 2 or 3 , return 0
  else if (n % long(sqrt(n)) == 0) cout << 0 << endl;
  //if integer can be squrt root, return 0
  else{
   while (init <= n)
   {
    if (n == init || n - 1 == init) {
     cout << 1 << endl;
    //since the different between number will be 0 or 1, if so reutnr 0
     break;
    }
    else if (n % init == 0){
     cout << 0 << endl;
     //if the intege can be divisible, return 0
     break;
    }
    init += 2; //number have to be odd
   }
   init = 5; //regenerate the number
  }
 }
 return 0;
}

//487 1753