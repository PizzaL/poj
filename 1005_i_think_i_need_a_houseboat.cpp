#include <iostream>

using namespace std;

const double pi=3.1415926;

void judge(int i, double x, double y)
{
	int year = 1;
	while (x*x+y*y>100*year/pi)
		++year;
	cout << "Property " <<i+1<<": This property will begin eroding in year "<<year<<"."<<endl;
}

int main()
{
	int n;
	cin >>n;
	double x,y;
	for (size_t i=0;i!=n;++i)
	{
		cin >>x>>y;
		judge(i, x,y);
	}
	cout <<"END OF OUTPUT." << endl;
	return 0;
}