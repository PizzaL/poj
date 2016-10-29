#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double res=0;
	for (size_t i=0;i!=12;++i)
	{
		double month;
		cin >> month;
		res+=month;
	}
	cout <<"$"<<fixed<<setprecision(2)<<res/12<<endl;
	return 0;
}