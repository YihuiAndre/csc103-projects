/*
 * CSc103 Project 5: Syntax highlighting, part two.
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
 * #hours: 7
 */

#include "fsm.h"
using namespace cppfsm;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;
#include <map>
using std::map;
#include <initializer_list> // for setting up maps without constructors.

// enumeration for our highlighting tags:
enum {
	hlstatement,  // used for "if,else,for,while" etc...
	hlcomment,    // for comments
	hlstrlit,     // for string literals
	hlpreproc,    // for preprocessor directives (e.g., #include)
	hltype,       // for datatypes and similar (e.g. int, char, double)
	hlnumeric,    // for numeric literals (e.g. 1234)
	hlescseq,     // for escape sequences
	hlerror,      // for parse errors, like a bad numeric or invalid escape
	hlident       // for other identifiers.  Probably won't use this. 8
};

// usually global variables are a bad thing, but for simplicity,
// we'll make an exception here.
// initialize our map with the keywords from our list:
map<string, short> hlmap = {
#include "res/keywords.txt"
};
// note: the above is not a very standard use of #include...

// map of highlighting spans:
map<int, string> hlspans = {
	{hlstatement, "<span class='statement'>"},
	{hlcomment, "<span class='comment'>"},
	{hlstrlit, "<span class='strlit'>"},
	{hlpreproc, "<span class='preproc'>"},
	{hltype, "<span class='type'>"},
	{hlnumeric, "<span class='numeric'>"},
	{hlescseq, "<span class='escseq'>"},
	{hlerror, "<span class='error'>"}
};
// note: initializing maps as above requires the -std=c++0x compiler flag,
// as well as #include<initializer_list>.  Very convenient though.
// to save some typing, store a variable for the end of these tags:
string spanend = "</span>";

string translateHTMLReserved(char c) {
	switch (c) {
		case '"':
			return "&quot;";
		case '\'':
			return "&apos;";
		case '&':
			return "&amp;";
		case '<':
			return "&lt;";
		case '>':
			return "&gt;";
		case '\t': // make tabs 4 spaces instead.
			return "&nbsp;&nbsp;&nbsp;&nbsp;";
		default:
			char s[2] = {c,0};
			return s;
	}
}

string updataLine(string str);
bool lookKeyword(string word);

int main() {
	// TODO: write the main program.
	// It may be helpful to break this down and write
	// a function that processes a single line, which
	// you repeatedly call from main().
	string str; //input sentence
	while(getline(cin,str))
	{
		cout << updataLine(str + '\n'); //this can rewrite the line as CSS format
	}
	return 0;
}

string updataLine(string str)
{
	int state = 0, syntaxE = 8; //syntaxE is syntax element Eg: hlstrlit
	string newStr, word; //word is the word that we reading
    string htmlC;
	for (size_t c = 0;c < str.length(); c++)
	{
        htmlC = translateHTMLReserved(str[c]); //html char
		cppfsm::updateState(state, str[c]); //update the state
        switch (state){ //each represent different state
            case start: //0
				if (syntaxE == hlstrlit) newStr += hlspans[syntaxE] + word + htmlC +spanend;
				//when the word is end by "
				else if (syntaxE != hlident) newStr += hlspans[syntaxE] + word + spanend + htmlC;
				//anything except for 1, 0 and 2 state
				else 
				{
					if (lookKeyword(word)) newStr += hlspans[hlmap[word]] + word + spanend + htmlC;
					//find the keyword
					else newStr += word + htmlC;
					//if the keyword not found, just add it
				}
				word.clear();
				syntaxE = hlident;
                break;
            case scanid:
                break;
            case comment:
				syntaxE = hlcomment;
                break;
            case strlit:
				if (syntaxE == hlescseq) //special case
				{
					newStr += hlspans[syntaxE] + word + htmlC + spanend;
					word.clear();
				}
				else word += htmlC; //this is becase when word is \n, then n can't be add
				syntaxE = hlstrlit;
                break;
            case readfs:
				if (syntaxE == hlnumeric) //special case
				{
					newStr += hlspans[syntaxE] + word + spanend;
					word.clear();
				}
				syntaxE = hlcomment;
                break;
            case scannum:
				if (syntaxE == hlcomment) //special case
				{
					newStr += word;
					word.clear();
				}
				syntaxE = hlnumeric;
                break;
			case readesc:
				newStr += hlspans[syntaxE] + word + spanend; //end the string eariler
				word.clear();
				syntaxE = hlescseq;
				break;
            case error:
				if (syntaxE != hlerror && syntaxE != hlescseq) //end the word berfore error
				{
					newStr += hlspans[syntaxE] + word + spanend;
					word.clear();
				}
				syntaxE = hlerror;
                break;
        }
		if (state != start && state != strlit) word += htmlC;


	}
	return newStr;
}

bool lookKeyword(string word)
{
	map<string,short>::iterator it;
	it = hlmap.find(word);
	if (it != hlmap.end())
	{
		return true;
	}
	return false;
}



