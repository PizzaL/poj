#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct DNA {
	string sequence;
	int sortedness;
};

bool operator<(const DNA& lhs, const DNA& rhs)
{
	return  lhs.sortedness <= rhs.sortedness;
}

int sortedness(string str)
{
	int res =0;
	for (size_t i=0;i<str.length()-1;++i)
		for (size_t j=i+1; j<str.length(); ++j)
			if (str[j]<str[i])
				++res;
	return res;
}

int main()
{
	int n, m;
	vector<DNA> dnas;
	cin >> n >> m;
	for (size_t i=0;i<m;++i)
	{
		DNA dna;
		cin >> dna.sequence;
		dna.sortedness = sortedness( dna.sequence );
		dnas.push_back(dna);
	}
	stable_sort(dnas.begin(), dnas.end());
	for (size_t i=0;i!=dnas.size(); ++i)
	{
		cout << dnas[i].sequence << endl;
	}
	return 0;
}