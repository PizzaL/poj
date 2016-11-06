#include <iostream>
#include <set>
#include <stdlib.h>

using namespace std;

struct Pixel
{
	int value;
	int num;
};

int getValue(int pos, int n, Pixel pixels[])
{
	for (size_t i=0; i<n; ++i)
	{
		if (pos < pixels[i].num)
			return pixels[i].value;
		else
			pos -= pixels[i].num;
	}
	return 0;
}

int getNewValue( int width, int row, int pos, int n, Pixel pixels[])
{
	int res = 0;
	int currValue = getValue(pos, n, pixels);
	// cout << "currValue="<<currValue << " ";
	for (int i=-1; i<2; ++i)
		for (int j=-1; j<2; ++j)
		{
			int currRow = pos/width+i;
			int currCol = pos%width+j;
			if (currRow >= 0 && currCol >= 0 && currRow < row && currCol < width)
			{
				int neighbor = getValue(currRow*width+currCol, n, pixels);
				// cout << "("<<currRow<<","<<currCol<<")=" << neighbor << " ";
				res = max( abs(currValue - neighbor), res);
			}
		}
	// cout << endl;
	return res;
}

void cal(int width, int row, int n, Pixel pixels[])
{
	cout << width << endl;
	int index = 0;
	set<int> checkPoints;
	// IMPORTANT
	// A  A A A A A
	// A  A A A A A
	//(A) A B B B B
	// (A) is a start!!!
	// so width*row should also be considered as a start!!!
	for (size_t k=0; k<=n; ++k)
	{
		for (int i=-1; i<2; ++i)
			for (int j=-1; j<2; ++j)
			{
				int currRow = index/width+i;
				int currCol = index%width+j;
				if (currRow >= 0 && currCol >= 0 && currRow < row && currCol < width)
				{
					checkPoints.insert(currRow*width+currCol);
				}
			}
		if (k == n)
			break;
		index+=pixels[k].num;
	}

	typedef set<int>::const_iterator SIT;
	// for (SIT it = checkPoints.begin(); it!= checkPoints.end(); ++it)
	// 	cout << *it << " ";
	int currPos = 0;
	int currValue = getNewValue(width, row, 0, n, pixels);
	for (SIT it = checkPoints.begin(); it!= checkPoints.end(); ++it)
	{
		int newPos = *it;
		int newValue = getNewValue(width, row, newPos, n, pixels);
		// cout << "newPos="<< newPos << "newValue=" << newValue << endl;
		if (newValue!=currValue){
			cout << currValue << " " << newPos-currPos << endl;
			currValue = newValue;
			currPos = newPos;
		}
	}
	cout << currValue << " " << width*row-currPos << endl;
}

int main()
{
	int width;
	cin >> width;
	while (width !=0)
	{
		Pixel pixels[1000+5];
		int i=0;
		int total = 0;
		cin >> pixels[i].value >> pixels[i].num;
		while (pixels[i].value !=0 || pixels[i].num != 0)
		{
			total+=pixels[i].num;
			++i;
			cin >> pixels[i].value >> pixels[i].num;
		}
		cal(width, total/width, i, pixels);
		cout << "0 0"<< endl;
		cin >> width;
	}
	cout << 0 << endl;
	return 0;
}