/*
 * CSc103 Project 3: Game of Life
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
 * #hours:9 
 */
#include <iostream>

#include <cstdio>
#include <stdlib.h> // for exit();
#include <getopt.h> // to parse long arguments.
#include <unistd.h> // sleep
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::cout;

static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Text-based version of Conway's game of life.\n\n"
"   --seed,-s     FILE     read start state from FILE.\n"
"   --world,-w    FILE     store current world in FILE.\n"
"   --fast-fw,-f  NUM      evolve system for NUM generations and quit.\n"
"   --help,-h              show this message and exit.\n";

size_t max_gen = 0; /* if > 0, fast forward to this generation. */
string wfilename =  "/tmp/gol-world-current"; /* write state here */
FILE* fworld = 0; /* handle to file wfilename. */
string initfilename = "/tmp/gol-world-current"; /* read initial state from here. */

/* NOTE: you don't have to write these functions -- this is just how
 * I chose to organize my code. */
size_t nbrCount(size_t i, size_t j, const vector<vector<bool> >& g);
void update(); //transform old version into new one
int initFromFile(const string& fname); /* read initial state into vectors. */
void mainLoop(); //updata status, write status, sleep, repeat
void dumpState(FILE* f);//write the state to a file

/* NOTE: you can use a *boolean* as an index into the following array
 * to translate from bool to the right characters: */
char text[3] = ".O";
vector<vector<bool>> world;
vector<vector<bool>> cWorld; //copy of the world

int main(int argc, char *argv[]) {
	// define long options
	static struct option long_opts[] = {
		{"seed",    required_argument, 0, 's'},
		{"world",   required_argument, 0, 'w'},
		{"fast-fw", required_argument, 0, 'f'},
		{"help",    no_argument,       0, 'h'},
		{0,0,0,0}
	};
	// process options:
	char c;
	int opt_index = 0;
	while ((c = getopt_long(argc, argv, "hs:w:f:", long_opts, &opt_index)) != -1) {
		switch (c) {
			case 'h':
				printf(usage,argv[0]);
				return 0;
			case 's':
				initfilename = optarg;
				break;
			case 'w':
				wfilename = optarg;
				break;
			case 'f':
				max_gen = atoi(optarg);
				break;
			case '?':
				printf(usage,argv[0]);
				return 1;
		}
	}
	/* NOTE: at this point wfilename initfilename and max_gen
	 * are all set according to the command line: */	
	if (wfilename == "-") wfilename = "stdout"; //change?
	printf("input file:  %s\n",initfilename.c_str());
	printf("output file: %s\n",wfilename.c_str());
	printf("fast forward to generation: %lu\n",max_gen);
	/* TODO: comment out 3 lines above once you see what's in them. */
	/* NOTE: if wfilename == "-" you should write to stdout, not a file
	 * named "-"! */

	/* If you wrote the initFromFile function, call it here: */
	initFromFile(initfilename);
	mainLoop();
	return 0;
}

void mainLoop() {
	/* TODO: write this */
	/* update, write, sleep */	
	cWorld = world;
	fworld = fopen(wfilename.c_str(), "wb");
	if (max_gen == 0) {
		/* make one generation update per second */
		update();
		dumpState(fworld);
	} else {
		/* go through generations as fast as you can until
		 * max_gen is reached... */
		for (size_t k = 0; k < max_gen; k++)
		{
			update();
			sleep(1);
		}
			dumpState(fworld);
	}
}


size_t nbrCount(size_t i, size_t j, const vector<vector<bool> >& g)
{
	size_t Neighbors = 0;
	for (size_t row = 0; row < 3; row++)
	{
		size_t Rindex = ((i-1+row)+g.size())%(g.size());
		for (size_t col = 0; col < 3; col++)
		{
			size_t Cindex = ((j-1+col)+g[0].size())%(g[0].size());
			Neighbors += g[Rindex][Cindex];
		}
	}
	return Neighbors - g[i][j];
}

int initFromFile(const string& fname) /* read initial state into vectors. */
{
	FILE* f  = fopen(fname.c_str(), "rb");
	if (!f) exit(1);
	char c;
	world.push_back(vector<bool> ());
	size_t row = 0;
	while (fread(&c,1,1,f))
	{
		if (c == '\n'){
			row++;
			world.push_back(vector<bool> ());
		}
		else if (c == '.') world[row].push_back(false);
		else world[row].push_back(true);
	}
	world.pop_back();
	fclose(f);
	return 0;
}

void update() //transform old version into new one
{
	size_t nbr = 0;
	for (size_t r = 0; r < cWorld.size(); r++ ){
		for (size_t c = 0; c < cWorld[0].size(); c++){
			nbr = nbrCount(r,c,world);
			if (world[r][c]){
				if (nbr == 2 || nbr == 3) cWorld[r][c] = true;
				else cWorld[r][c] = false;
			}
			else{
				if (nbr == 3) cWorld[r][c] = true;
			}
		}
		nbr = 0;
	}
	world = cWorld;
}

void dumpState(FILE* f) //write the state to a file
{
	if (!f) exit(1);
	char c;
	for (size_t row = 0; row < world.size(); row++)
	{
		for (size_t col = 0; col < world[0].size(); col++)
		{
			c = text[world[row][col]];
			fwrite(&c,1,1,f);
		}
		c = '\n';
		if (row != world.size()-1) fwrite(&c,1,1,f);
	}

}


