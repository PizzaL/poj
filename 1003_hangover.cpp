#include <iostream>

using namespace std;

int getCards(const double length)
{
	int res = 1;
	double cardLength = 0.5;
	while (cardLength < length)
	{
		++res;
		cardLength+=1.0/(res+1);
	}
	return res;
}

int main()
{
	double length;
	while (cin >> length)
	{
		if (length == 0.0)
			break;
		cout << getCards(length) << " card(s)" << endl;
	}
	return 0;
}