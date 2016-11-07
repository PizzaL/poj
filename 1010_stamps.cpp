#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct ResList {
	vector<int> res;
	bool tie;
	ResList()
		: tie(false)
	{}
	ResList(const vector<int>& res, bool tie)
		: res(res), tie(tie)
	{}
};

ostream& operator<<(ostream& out, const vector<int> list)
{
	out << "list=";
	for (size_t i=0; i<list.size(); ++i)
		out << list[i] << " ";
	return out;
}
ostream& operator<<(ostream& out, const ResList& resList)
{
	out << resList.res << endl 
		<< "tie=" << resList.tie;
	return out;
}

void compRes(ResList& resList, const ResList& newResList, int stamps[])
{
	// cout << "CompRes: resList=" << resList << endl
	// 	 << "         newResList=" << newResList << endl;
	if (resList.res.size() == 0) {
		resList = newResList;
		return ;
	}
	set<int> resSet(resList.res.begin(), resList.res.end());
	set<int> newResSet(newResList.res.begin(), newResList.res.end());
	int resLargest = stamps[*resSet.rbegin()];
	int newResLargest = stamps[*newResSet.rbegin()];
	if (newResSet.size() < resSet.size())	// most type
	{
		return ;
	} else if (newResSet.size() == resSet.size())
	{
		if (newResList.res.size() > resList.res.size())	// fewest total
			return ;
		else if ( newResList.res.size() == resList.res.size())
		{
			if ( resLargest > newResLargest)
				return ;
			else if (resLargest == newResLargest)
			{
				// cout << "*****tie*****"<< endl;
				resList.tie = true;
				return ;
			}
		}
	}
	resList = newResList;
}

// resList return index
ResList findPair(int customer, int n, int index, int stamps[], const vector<int> currList)
{
	// cout << "cus=" << customer << "n=" << n << "currList=" << currList << endl;
	if (customer == 0)
	{
		return ResList(currList, false);
	}
	if (n == 0) {
		return ResList();
	}
	ResList resList;
	for (size_t i=0; i<index; ++i)
	{
		vector<int> newList = currList;
		if (customer >= stamps[i] 
		&& (currList.size() == 0 || (currList.size() > 0 && *currList.rbegin() <= i) ) )
		{
			newList.push_back(i);
			ResList newResList = findPair(customer-stamps[i], n-1, index, stamps, newList);
			newList.erase(newList.end()-1);
			if (newResList.res.size() > 0)
				compRes(resList, newResList, stamps);
		}
	}
	return resList;
}

void preProcess(int& index, int stamps[])
{
	if (index == 0)
		return ;
	// sort
	for (int i=0;i<index-1;++i)
		for (int j=i+1; j< index; ++j)
			if (stamps[i]>stamps[j])
			{
				int x = stamps[i];
				stamps[i] = stamps[j];
				stamps[j] =x;
			}
	int newIndex=1;
	int currValue = stamps[0];
	int count = 1;
	for (int i=1; i< index; ++i)
	{
		if (stamps[i] == currValue)
		{
			++count;
			if (count > 5) {
				continue;
			} else {
				stamps[newIndex++]=stamps[i];
			}
		} else {
			stamps[newIndex++] = stamps[i];
			currValue = stamps[i];
			count =1;
		}
	}
	index = newIndex;
	// for (int i = 0; i< index; ++i)
	// 	cout << stamps[i] << " ";
	// cout << endl;
}

void cal(int customer, int index, int stamps[])
{
	preProcess(index, stamps);
	ResList resList = findPair(customer, 4, index, stamps, vector<int>() );
	set<int> resSet(resList.res.begin(), resList.res.end());
	if (resList.res.size() == 0)
		cout << customer << " ---- none " << endl;
	else if ( !resList.tie) 
	{
		cout << customer << " (" << resSet.size() << "):";
		for (size_t i=0;i<resList.res.size(); ++i)
			cout << " " << stamps[resList.res[i]];
		cout << endl;
	} else
	{
		cout << customer << " ("<< resSet.size() << "): tie" << endl;
	}
}

int main()
{
	int stamps[100];
	int index = -1;
	while (cin >> stamps[++index])
	{
		if (stamps[index] == 0)
		{
			int customer;
			while (cin >> customer)
			{
				if (customer == 0){
					index = -1;	// next set
					break;
				}
				cal(customer, index, stamps);
			}
		}
	}
	return 0;
}