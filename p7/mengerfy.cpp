/* implementation of mengerfy. */
#include "mengerfy.h"
#include <cstdlib>   /* for rand() */
#include <time.h>    /* for time() */
#include <cstdio>

int countDiff(const double x, const double y, const double z){ 
	//count how many difference in x, y, z
	//for example, if x != 0 and y == 0 and z != 0, then it will return 2
	int numDiff = 0;
	if (x) numDiff++;
	if (y) numDiff++;
	if (z) numDiff++;
	return numDiff;
}

deque<cube> subdivide(const cube& M,const int* mode,const bool random){ 
	//divide a single cube into 27 cube
	deque<cube>R; //result
	int numDiff; //just use it to get the number of difference values;
	bool Detest = false; //just test whatever the subcube should be keep for next generation
	double cr = (2*M.r)/6 , cz, cx, cy; 
	for (int z = -1; z < 2; z++){
		cz = M.z+(4*z*M.r)/6;
		for (int x = -1; x < 2; x++){
			cx = M.x+(4*x*M.r)/6;
			for (int y = -1; y < 2; y++){
				cy = M.y+(4*y*M.r)/6;
				if (random && rand() % 2 + 0) R.push_back(cube(cx,cy,cz,cr)); 
				//random case
				else{
					double diffZ = M.z - cz, diffX = M.x - cx, diffY = M.y - cy;
					numDiff = countDiff(diffX, diffY, diffZ);
					if (mode[0] && numDiff == 0) Detest = true; //mode 0
					else if (mode[1] && numDiff == 1) Detest = true; //mode 1
					else if (mode[2] && numDiff == 2) Detest = true; //mode 2
					else if (mode[3] && numDiff == 3) Detest = true; //mode 3
				}
				if (Detest){
					R.push_back(cube(cx,cy,cz,cr));
					Detest = false;
				}
			}	
		}
	}
	return R;
}

//modula can be represent by bitstring?????
void mengerfy(deque<cube>& M, int mode, int d, bool random)
{
	/* TODO: write me.  Feel free to add "helper" functions
	 * to this file if needed. */
	int* bitstringMode = new int[4], tmp = mode;
	//convert mode into bitstring and make it easier control
	for (int k = 0; k < 4; k++){
		bitstringMode[k] = tmp % 2;
		tmp /= 2;
	}
	for (int i = 0; i < d; i++){ //iterator on d
		size_t size = M.size();
		for (size_t t = 0; t < size; t ++){ //iterator on size of M
			deque<cube> R = subdivide(M.front(),bitstringMode,random);
			M.pop_front();
			for (size_t k = 0; k < R.size(); k++){
				M.push_back(R[k]);
			}
		}
	}

}



