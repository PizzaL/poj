#include <iostream>
#include <queue>
#include <cstdlib>
#include <map>

using namespace std;

struct Pixel
{
	int value;
	int num;
};

int getCurrValue(int r, int c, int width, int n, Pixel pixels[], map<int, int> oldValueMap)
{
	int index = r*width+c;
	if (oldValueMap.find(index) != oldValueMap.end() )
		return oldValueMap[index];
	if (r < 0 || c >= width || c<0)
		return -1;
	int i=0;

	while (i < n)
	{
		if (index >= pixels[i].num)
		{
			index -= pixels[i++].num;
		} else 
		{
			oldValueMap[index] = pixels[i].value;
			return pixels[i].value;
		}
	}
	oldValueMap[index] = -1;
	return -1;
}

int getNewValue(int r, int c, int width, int n, Pixel pixels[], map<int, int> oldValueMap)
{
	int res = 0;
	int curr = getCurrValue(r, c, width, n, pixels, oldValueMap);
	for (int i = -1; i<2; ++i)
		for (int j = -1; j<2; ++j)
			if (i !=0 || j!=0)
			{
				int neighbor = getCurrValue(r+i, c+j, width, n, pixels, oldValueMap);
				// cout << "(" << r+i<<" "<<c+j<<")"<<neighbor << " ";
				if (neighbor>-1)
					res = max(res, abs( curr -  neighbor) ) ;
			}
	return res;
}

struct Segment{
	int startPos;
	int endPos;
	Segment(int startPos, int endPos)
	  : startPos(startPos)
	  , endPos(endPos)
	{
	}
};

void cal(int width, Pixel pixels[], int n)
{	
	cout << width << endl;
	int index=0;
	queue<Segment> posQueue;
	int startPos = 0;
	int endPos = 0;
	for (size_t i=0;i<n;++i)
	{
		if ( index > endPos+1 ) {
			posQueue.push( Segment(startPos, endPos) );
			startPos = index;
		}
		endPos = index+min(width+1, pixels[i].num);
		if (pixels[i].num > width) {
			int newStart = index+max(pixels[i].num-width-1, width+1);
			if ( newStart > endPos+1 ) {
				posQueue.push( Segment(startPos, endPos) );
				startPos = newStart;
			}
			endPos = index + pixels[i].num;
		}
		index += pixels[i].num;
	}
	posQueue.push(Segment(startPos, endPos));
	int value = 0;
	int num = 0;
	int lastPos = -1;
	map<int, int> oldValueMap;
	while (!posQueue.empty())
	{
		Segment currSeg = posQueue.front();
		for ( size_t currPos = currSeg.startPos; currPos!=currSeg.endPos; ++currPos)
		{
			// cout << "currPos=" << currPos << " ";
			int newValue = getNewValue(currPos/width, currPos%width, width, n, pixels, oldValueMap);
			// cout << "newValue=" << newValue << endl;
			if (currPos > lastPos+1)
			{	// gap
				if (value == 0)
					num += currPos-lastPos;
				else {
					cout << value <<" "<< num << endl
						<< 0 << currPos - lastPos << endl;
					value = newValue;
					num = 1;
				}
			} else {
				if ( newValue == value)
					++num;
				else
				{
					if (lastPos != -1)	// skip the first
						cout << value << " " << num << endl;
					value = newValue;
					num = 1;
				}
			}
			lastPos = currPos;
		}
		posQueue.pop();
	}
	cout << value << " "<<num << endl
	 	 << "0 0" << endl;
}

int main()
{
	int width;
	cin >> width;
	Pixel pixels[1000+5];
	while (width !=0 )
	{
		int i=0;
		cin >> pixels[i].value >>pixels[i].num;
		while (pixels[i].num!=0)
		{
			++i;
			cin >> pixels[i].value >> pixels[i].num;
		}
		cal(width, pixels, i);
		cin >> width;
	}
	cout << "0" << endl;
	return 0;
}