#include <iostream>
#include <vector>

using namespace std;

struct Number
{
	vector<int> number;
	int decimal;
	
	Number()
		: number(vector<int>(1,1))
		, decimal(0)
	{}
};

ostream& operator<<( ostream& out, const Number& num)
{
	int start=0;
	while (num.number[start++]==0)
		;
	if (num.number.size() > num.decimal)
	{
		for (int i = num.number.size(); i!=num.decimal; --i)
		{
			out << num.number[i-1];
		}
		if (num.decimal-start >= 0)
		{
			out << ".";
			for (int i=num.decimal; i!=start-1; --i)
			{
				out << num.number[i-1];
			}
		}
	} else {
		out << ".";
		for (size_t i=0; i<num.decimal-num.number.size(); ++i){
			out <<"0";
		}
		for (size_t i=num.number.size(); i != start-1; --i)
		{
			out<<num.number[i-1];
		}
	}
	return out;
}

void multi( Number& number
			, const int num
			, const int digit)
{
	number.decimal += digit;
	int c  = 0;
	for (size_t i = 0; i !=number.number.size(); ++i)
	{
		int curr = number.number[i]*num+c;
		number.number[i] = curr % 10;
		c=curr/10;
	}
	while (c != 0)
	{
		number.number.push_back(c%10);
		c/=10;
	}
}

int main()
{
	double r;
	int n; 
	while (cin >> r >> n)
	{
		Number res;
		int num, digit;
		if (r < 10)
		{
			num= r*10000;
			digit = 4;
		} else {
			num = r*1000;
			digit = 3;
		}
		for (size_t i=0; i<n; ++i)
		{
			multi(res, num, digit);
		}
		cout << res << endl;
	}
	return 0;
}