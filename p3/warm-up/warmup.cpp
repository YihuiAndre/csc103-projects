#include <vector>
using std::vector;
#include <iostream>
using std::cout;

void display(vector<vector<bool>> V);
//display the matrix on the console
bool detect(const int row, const int col);
//return the bool value in the specific row and col dead or live
size_t detectN(const int row, const int col);
//return how many neighbors near the specific location

vector<vector<bool> > T_world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

vector<vector<bool>> world = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

vector<size_t> Row = {world.size()-1,0,1,2,3,4,5,6,7,8,9,0};
vector<size_t> Col = {world[0].size()-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,0};
//each element in Row and Col corresponding to different index in world

vector<vector<bool> > newWorld = world;

int main()
{
	/* NOTE: the vector 'world' above corresponds to the contents
	 * of ../res/tests/0.  TODO: apply the rules to the vector,
	 * write the result to standard output, and compare with the
	 * contents of ../res/tests/1.*/
	//cout << world[7][15] << " " << detect(7,15) << " ";
	//cout << world[6][14] << " " << detect(6,14) << " ";
	//cout << world[1][19] << " " << detect(1,19) << " ";
	size_t n;
	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t r = 0; r < world.size(); r++)
		{
			for (size_t c = 0; c < world[r].size(); c++)
			{
				newWorld[r][c] = detect(r,c);	
			}
		}
		world = newWorld;
	}
	display(world);
	return 0;
}


void display(vector<vector<bool>> V)
{
	for (size_t i = 0; i < V.size(); i++)
	{
		for (size_t k = 0; k < V[i].size(); k++)
		{
			if (V[i][k]) cout << '0' << " ";
			else cout << '.' << " ";
		}
		cout << "\n";
	}
}

bool detect(const int row, const int col)
{
	size_t neighbors = detectN(row,col);
	if (world[row][col])//when the cell is living
	{
		if (neighbors == 3 || neighbors == 2) return true;
		return false;
	}
	else //when the cell is die
	{
		if (neighbors == 3) return true;
		return false;
	}
}


size_t detectN(const int row, const int col)
{
	int neighbors = 0;
	//size_t last_row = world.size()-1, last_col = world[0].size()-1;
	for (int r = row - 1; r < row + 2; r++) //row-1 row row+1
	{
		for (int c = col - 1; c < col + 2; c++) //col-1 col col+1
		{
			neighbors += world[Row[r+1]][Col[c+1]];

			/*
			if (r == -1 || c == -1 || r == int(world.size()) || c == int(world[0].size()))
			//examine if the location is out of bound, if true execute follow statement
			{
				if ((c != -1 && c != int(world[0].size()))){
				//condition: if location has out of bound in row but not col
					if (r == -1) neighbors += world[last_row][c];
					// if row has upper out of bound
					else neighbors += world[0][c];
					// if row has bottom out of bound
				}
				else if ((r != -1 && r != int(world.size()))){
				//condition: if location has out of bound in col but not row
					if (c == -1) neighbors += world[r][last_col];
					else neighbors += world[r][0];
				}
				//the following statment is only working for when both row and col are out of bound, mean when the location is in corner;
				else if (r == -1){
					if (c == -1) neighbors += world[last_row][last_col];
					else neighbors += world[last_row][0];
				}
				else{
					if (c == -1) neighbors += world[0][last_col];
					else neighbors += world[0][0];
				}
			}
			//if both row and col are not excess in within their coundary
			else neighbors += world[r][c];
			*/
		}
	}
	//last: since we count the location itself, we need to deduct the number from it
	return neighbors - world[row][col];
}
//error 16;
