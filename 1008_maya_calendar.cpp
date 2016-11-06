#include <iostream>
#include <map>

using namespace std;

map<string, int> Haab;
map<int, string> Tzolkin;

void constructNameMap()
{
	Haab["pop"] = 0;
	Haab["no"] = 1;
	Haab["zip"] = 2;
	Haab["zotz"] = 3;
	Haab["tzec"] = 4;
	Haab["xul"] = 5;
	Haab["yoxkin"] = 6;
	Haab["mol"] = 7;
	Haab["chen"] = 8;
	Haab["yax"] = 9;
	Haab["zac"] = 10;
	Haab["ceh"] = 11;
	Haab["mac"]  =12;
	Haab["kankin"] = 13;
	Haab["muan"] = 14;
	Haab["pax"] = 15;
	Haab["koyab"] = 16;
	Haab["cumhu"] = 17;
	Haab["uayet"] = 18;

	Tzolkin[1] = "imix";
	Tzolkin[2] = "ik";
	Tzolkin[3] = "akbal";
	Tzolkin[4] = "kan";
	Tzolkin[5] = "chicchan";
	Tzolkin[6] = "cimi";
	Tzolkin[7] = "manik";
	Tzolkin[8] = "lamat";
	Tzolkin[9] = "muluk";
	Tzolkin[10] = "ok";
	Tzolkin[11] = "chuen";
	Tzolkin[12] = "eb";
	Tzolkin[13] = "ben";
	Tzolkin[14] = "ix";
	Tzolkin[15] = "mem";
	Tzolkin[16] ="cib";
	Tzolkin[17] = "caban";
	Tzolkin[18] = "eznab";
	Tzolkin[19] = "canac";
	Tzolkin[0] = "ahau";
}

int main()
{
	constructNameMap();
	int n;
	cin >> n;
	cout << n << endl;
	for (size_t i =0;i<n;++i)
	{
		int day;
		char dot;
		string month;
		int year;
		cin >> day >> dot >> month >> year;
		int date = 1+day+20*Haab[month]+year*365;
		// cout << "date=" << date <<endl;
		cout << (date-1)%13+1 <<" "<< Tzolkin[date%20] <<" "<< (date-1)/260 << endl;
	}
	return 0;
}