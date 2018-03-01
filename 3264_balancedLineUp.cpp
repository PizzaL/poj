#include <iostream>
#include <vector>

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> cows;
	for (size_t i=0; i<n; ++i)
	{
		int height;
		cin >> height;
		cows.puh_back(height);
	}
	struct Node {
		int maxValue, minValue;
	};

	vector<Node> segTree(2*n, Node());
	buildSegTree(segTree, 0, cows.size()-1, cows);
	for (size_t i=0; i<m; ++i)
	{
		int start, end;
		cin >> start >> end;
		cout << query(segTree, start, end) << endl;
	}
	return 0;
}