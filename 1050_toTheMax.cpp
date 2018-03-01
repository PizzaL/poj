#include <iostream>

using namespace std;

int map[100][100];

int findMax(int n)
{
	int result[100][100];
	for (size_t i=0; i<n; ++i)
	{
		for (size_t j=0; j<n; j++)
		{
			result[i][j]=result
		}
	}
	for (size_t i=0; i<n; ++i)
	{
		for (size_t j=0; j<n; ++j)
		{

			if (i-1 >= 0)
				result[i][j] = max(result[i][j], result[i-1][j]);
			if (j-1 >=0)
				result[i][j] = max(result[i][j], result[i][j-1]);
		}
	}


}

int main()
{
	int n;

	cin >> n;
	for (size_t i=0; i<n*n; ++i)
		cin >> map[i/n][i%n];
	cout << findMax(n);
	return 0;
}