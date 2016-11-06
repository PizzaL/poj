#include <iostream>

using namespace std;

void cal(int i, int a, int b, int c, int d)
{
	cout << "Case " << i << ": the next triple peak occurs in "
		 << (a * 5544 + b * 14421 + c * 1288 + 21252 - d-1) % 21252 + 1
		 << " days." << endl;
}

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int i =1;
	while (a!= -1)
	{
		cal(i, a, b, c, d);
		cin >> a >> b >> c >> d;
		++i;
	}
	return 0;
}