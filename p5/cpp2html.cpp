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
 * #hours: 1
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
void lookKeyword(string word, int& syntaxE, int state);

int main() {
	// TODO: write the main program.
	// It may be helpful to break this down and write
	// a function that processes a single line, which
	// you repeatedly call from main().
	string str; //input sentence
	while(getline(cin,str))
	{
		cout << updataLine(str);
	}
	return 0;
}

string updataLine(string str)
{
	int state = 0, syntaxE = 8;
	string newStr; //word is the word that we reading
    string htmlC;
    set<int> A; //check if there is repitite value
	for (size_t c = 0;c < str.length(); c++)
	{
        htmlC = translateHTMLReserved(str[c]);
		cppfsm::updateState(state, str[c]);
        switch (state){
            case start:
                break;
            case scanid:
                break;
            case comment:
                break;
            case strlit:
                if (syntaxE != hlstrlit)
                {
                    syntaxE = hlstrlit;
                    newStr += hlspans[hlstrlit];
                }
                break;
            case readfs:
                break;
            case scannum:
                if (syntaxE != hlnumeric)
                {
                    syntaxE = hlnumeric;
                    newStr += hlspans[hlnumeric];
                }
                break;
            case error:
                break;
        }

        switch (syntaxE){
            case hlstatement:
                break;
            case hlcomment:
                break;
            case hlstrlit:
                cout << str[c] << state <<" ";
                if (state != strlit)
                {
                    newStr += spanend;
                    syntaxE = 8;
                }
                else newStr += htmlC;
                break;
            case hlpreproc:
                break;
            case hltype:
                break;
            case hlnumeric:
                if (state != scannum)
                {
                    newStr += spanend;
                    syntaxE = 8;
                    break;
                }
                newStr += htmlC;
                break;
            case hlescseq:
                break;
            case hlerror:
                break;
            default:
                newStr += str[c];
        }
        /*
        switch (syntaxE){
            case start:
                break;
            case scanid:
                break;
            case comment:
                break;
            case strlit:
                break;
            case readfs:
                break;
            case scannum:
                newStr += hlspans[hlnumeric];
                break;
            case error:
                break;
        }
         */
	}
	return newStr;
}

void lookKeyword(string word, int& syntaxE, int state)
{
	map<string,short>::iterator it;
	it = hlmap.find(word);
	if (it != hlmap.end())
	{
		syntaxE = hlmap[word];
	}
	syntaxE = 8;
}



