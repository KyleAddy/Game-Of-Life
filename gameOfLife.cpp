

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
using namespace std;

const int ARRAY_WIDTH = 10;
const int ARRAY_HEIGHT = 10;

int neighbor(bool array[][ARRAY_WIDTH], int arrayheight, int height, int width);
//sets array1 equeal to array2
void array1Set(bool array1[][ARRAY_WIDTH], bool array2[][ARRAY_WIDTH]);
void array2Set(bool array1[][ARRAY_WIDTH], bool array2[][ARRAY_WIDTH]);
void print(bool array1[][ARRAY_WIDTH], int arrayheight);

int main()
{
	bool array1[ARRAY_HEIGHT][ARRAY_WIDTH] {};
	bool array2[ARRAY_HEIGHT][ARRAY_WIDTH] {};

	array1[0][0] = true;
	array1[0][1] = true;
	array1[0][2] = true;

	array1[1][0] = true;
	array1[1][2] = true;

	array1[2][0] = true;
	array1[2][1] = true;
	array1[2][2] = true;

	print(array1, ARRAY_HEIGHT);
for (int iter = 0; iter < 11; ++iter)
{
	this_thread::sleep_for(1s);
	
	array2Set(array1, array2);
	cout << endl;
	array1Set(array1, array2);
	print(array1, ARRAY_HEIGHT);
	//print(array1, ARRAY_HEIGHT);
}
	return 0;
}

int neighbor(bool array[][ARRAY_WIDTH], int arrayheight, int height, int width)
{
	int numOfNeighbors = 0;

	//top left
	if (height > 0)
	{
		if (width > 0)
		{
			if (array[height - 1][width - 1])
				numOfNeighbors += 1;
		}
	}
	//top mid
	if (height > 0)
	{
		if (array[height - 1][width])
			numOfNeighbors += 1;
	}
	//top right
	if (height > 0)
	{
		if (width < ARRAY_WIDTH - 1)
		{
			if (array[height - 1][width + 1])
				numOfNeighbors += 1;
		}
	}
	//left
	if (width > 0)
	{
		if (array[height][width - 1])
			numOfNeighbors += 1;
	}
	//right
	if (width < ARRAY_WIDTH - 1)
	{
		if (array[height][width + 1])
			numOfNeighbors += 1;
	}
	//bottom left
	if (height < ARRAY_HEIGHT - 1)
	{
		if (width > 0)
		{
			if (array[height + 1][width - 1])
				numOfNeighbors += 1;
		}
	}
	//bottom mid
	if (height < ARRAY_HEIGHT - 1)
	{
		if (array[height + 1][width])
			numOfNeighbors += 1;
	}
	//bottom right
	if (height < ARRAY_HEIGHT - 1)
	{
		if (width < ARRAY_WIDTH - 1)
		{
			if (array[height + 1][width + 1])
				numOfNeighbors += 1;
		}
	}
	return numOfNeighbors;
}

void array2Set(bool array1[][ARRAY_WIDTH], bool array2[][ARRAY_WIDTH])
{
	int height = 0;
	int width = 0;
	int numOfNeighbors = 0;
	for (height = 0; height < ARRAY_HEIGHT; ++height)
	{
		for (width = 0; width < ARRAY_WIDTH; ++width)
		{
			numOfNeighbors = neighbor(array1, ARRAY_HEIGHT, height, width);
			if (numOfNeighbors < 3)
				array2[height][width] = false;
			else
				array2[height][width] = true;
		}
	}
}

void array1Set(bool array1[][ARRAY_WIDTH], bool array2[][ARRAY_WIDTH])
{
	for (int height = 0; height < ARRAY_HEIGHT; ++height)
	{
		for (int width = 0; width < ARRAY_WIDTH; ++width)
		{
			array1[height][width] = array2[height][width];
		}
	}
}

void print(bool array[][ARRAY_WIDTH], int arrayheight)
{
	for (int height = 0; height < ARRAY_HEIGHT; ++height)
	{
		for (int width = 0; width < ARRAY_WIDTH; ++width)
		{
			if (array[height][width])
				cout << setw(5) << "[O]";
			else
				cout << setw(5) << "]X[";
		}
		cout << endl;
	}
}
