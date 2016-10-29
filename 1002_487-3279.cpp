#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, string> buildNumberMap() {
	map<char, string> numberMap;
	numberMap['-']="";
	numberMap['0']="0";
	numberMap['1']="1"; 
	numberMap['2']="2"; numberMap['A']="2"; numberMap['B']="2"; numberMap['C']="2";
	numberMap['3']="3"; numberMap['D']="3"; numberMap['E']="3"; numberMap['F']="3";
	numberMap['4']="4"; numberMap['G']="4";numberMap['H']="4";numberMap['I']="4";
	numberMap['5']="5";numberMap['J']="5";numberMap['K']="5";numberMap['L']="5";
	numberMap['6']="6";numberMap['M']="6";numberMap['N']="6";numberMap['O']="6";
	numberMap['7']="7";numberMap['P']="7";numberMap['R']="7";numberMap['S']="7";
	numberMap['8']="8";numberMap['T']="8";numberMap['U']="8";numberMap['V']="8";
	numberMap['9']="9";numberMap['W']="9";numberMap['X']="9";numberMap['Y']="9";
	return numberMap;
}

string getRealPhoneNum( const string& phoneNum
					  , map<char, string>& numberMap)
{
	string realNum;
	for (size_t i=0; i<phoneNum.length(); ++i)
	{
		realNum+=numberMap[phoneNum[i]];
		if (realNum.length() == 3)
		{
			realNum+="-";
		}
	}
	return realNum;
}

int main() {
	int n;
	cin >> n;
	map<string, int> phoneMap;
	map<char, string> numberMap = buildNumberMap();
	for (size_t i=0; i<n; ++i)
	{
		string phoneNum;
		cin >> phoneNum;
		string realPhoneNum = getRealPhoneNum( phoneNum, numberMap);
		if ( phoneMap.find(realPhoneNum)== phoneMap.end() )
		{
			phoneMap[realPhoneNum] = 0;
		}
		++phoneMap[realPhoneNum];
	}

	typedef map<string, int>::const_iterator MCI;
	bool hasDupicates = false;
	for ( MCI ci=phoneMap.begin(); ci != phoneMap.end(); ++ci)
	{
		if (ci->second > 1) {
			hasDupicates = true;
			cout << ci->first << " " << ci->second << endl;
		}
	}
	if (!hasDupicates)
		cout << "No duplicates." << endl;
	return 0;
}