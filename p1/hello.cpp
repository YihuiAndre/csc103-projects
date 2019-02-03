/*
 * CSc103 Project 1: (hello_world++)
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 */
#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;

int main()
{
 cout << "Enter your name:\n";
 string name;
 getline(cin,name);
 string relative;
 cout << "Enter a relative:\n";
 getline(cin,relative);
 cout << "Hello. My name is " << name << ". You killed my " << relative << ". Prepare to die.\n";
 return 0;
}

