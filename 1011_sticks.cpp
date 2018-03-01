#include <iostream>
#include <map>
#include <vector>

using namespace std;
int runningCount = 0;
ostream& operator<<(ostream& out, const map<int, int>& myMap)
{
	out <<"[";
	typedef map<int, int>::const_iterator TIT;
	for (TIT it = myMap.begin(); it != myMap.end(); ++it)
		out << "(" << it->first << "," << it->second << "), ";
	out << "]";
	return out;
}

const int MAX_NUM_STICK = 64;
bool construct (int currLen, int len, map<int, int> sticks, map<int, int> combo)
{
	++runningCount;
	cout << "\tcurrLen=" << currLen << endl
		 << "\tcombo=" << combo << endl
		 << "\tsticks=[" << sticks << endl;
	if ( sticks.size() == 0 )
	{
		if ( currLen == 0)
		{
			return true;
		}
		else
		{ 
			return false;
		}
	}
	else if ( currLen == 0)
	{
		int num = MAX_NUM_STICK;
		for (map<int, int>::const_iterator it=combo.begin(); it!=combo.end(); ++it)
		{
			if (sticks.find(it->first) == sticks.end() || sticks[it->first] < it->second)
			{
				num = 0;
				break;
			} else
				num = min(num, sticks[it->first]/it->second);
		}
		if (num < MAX_NUM_STICK && num > 0)
		{
			for (map<int, int>::const_iterator it=combo.begin(); it!=combo.end(); ++it)
			{
				sticks[it->first] -= it->second*num;
				if (sticks[it->first] == 0)
					sticks.erase(it->first);
			}
		}
		return construct(len, len, sticks, map<int, int>() );
	} else
	{
		typedef map<int, int>::reverse_iterator MIT;
		MIT it = sticks.rbegin();	
		while ( it!=sticks.rend() && it->first > currLen)
		{	// only need to search the longest!
			++it;
		}
		if ( it != sticks.rend() && (currLen == it->first || currLen >= it->first + sticks.begin()->first) )
		{
			if (combo.find(it->first) != combo.end() )
				++combo[it->first];
			else 
				combo[it->first]=1;
			map<int, int> newSticks = sticks;
			if (--newSticks[it->first] == 0)
				newSticks.erase(it->first);
			return construct(currLen - it->first, len, newSticks, combo);
		}
		return false;
	}
}

int cal(int total, int maxNum, map<int, int>& sticks)
{
	for (int i=maxNum+1; i < total; ++i)
	{
		if (total%i == 0)
		{
			if ( construct(i, i, sticks, map<int, int>() ) )
			 	return i;
		}
	}
	return total;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n==0)
			break;
		map<int, int> sticks;
		sticks.clear();
		int total = 0;
		int maxNum = 0;
		for (size_t i=0;i<n;++i)
		{
			int value;
			cin >> value;
			total+=value;
			maxNum = max(maxNum, value);
			if (sticks.find(value) != sticks.end())
				++sticks[value];
			else
				sticks[value]=1;
		}
		runningCount = 0;
		cout << cal(total, maxNum, sticks) << endl
		 	 << " runningCount=" << runningCount << endl;
	}
	return 0;
}