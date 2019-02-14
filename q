[1;35mdiff --git a/p1/hello.cpp b/p1/hello.cpp[m
[1;35mindex eff6218..ca72a62 100644[m
[1;35m--- a/p1/hello.cpp[m
[1;35m+++ b/p1/hello.cpp[m
[36m@@ -9,5 +9,21 @@[m
  * References:[m
  *[m
  */[m
[32m+[m[32m#include <iostream>[m
[32m+[m[32musing std::cout;[m
[32m+[m[32musing std::cin;[m
[32m+[m[32m#include <string>[m
[32m+[m[32musing std::string;[m
 [m
[32m+[m[32mint main()[m
[32m+[m[32m{[m
[32m+[m[32m cout << "Enter your name:\n";[m
[32m+[m[32m string name;[m
[32m+[m[32m getline(cin,name);[m
[32m+[m[32m string relative;[m
[32m+[m[32m cout << "Enter a relative:\n";[m
[32m+[m[32m getline(cin,relative);[m
[32m+[m[32m cout << "Hello. My name is " << name << ". You killed my " << relative << ". Prepare to die.\n";[m
[32m+[m[32m return 0;[m
[32m+[m[32m}[m
 [m
