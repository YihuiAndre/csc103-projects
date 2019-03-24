/*
 * CSc103 Project 4: Syntax highlighting, part one.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours:4 
 */

#include "fsm.h"
using namespace cppfsm;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// make sure this function returns the old state.  See the header
// file for details.
int cppfsm::updateState(int& state, char c) {
	// TODO:  write this function.
	int oldState = state;
	switch (state)
	{
		case 0: if (c == '"') state = 3;
				else if (c == '/') state = 4;
				else if (INSET(c,ident_st)) state = 1;
				else if (INSET(c,num)) state = 6;
				break;

		case 1: if (c == '/') state = 4;
				else if (c == '"') state = 3;
				else if (INSET(c,iddelim)) state = 0;
				break;

		case 2: break;

		case 3: if (c == '"') state = 0;
				else if (c == '\\') state = 5;
				break;

		case 4: if (c == '/') state = 2;
				else if (c == '"') state = 3;
				else if (INSET(c,num)) state = 6;
				else if (INSET(c,ident_st)) state = 1;
				break;

		case 5: if (INSET(c,escseq)) state = 3;
				else state = 7;
				break;

		case 6: if (c == '/') state = 4;
				else if (INSET(c,iddelim)) state = 0;
				else if (INSET(c,num));
				else state = 7;
				break;
	}
	return oldState;
}

