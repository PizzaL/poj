#include <iostream>

using namespace std;

const int 
void getNextDay(int p, int e, int i, int d, int count)

int mian()
{
	int p, e, i, d,count=1;
	while (cin >>p>>e>>i>>d)
	{
		if (p==-1)
			break;
		getNextDay(p, e, i, d, count);
	}
	return 0;
}