/*
ID: misha101
LANG: C++11
TASK: skidesign
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> v(n);
	int bucket[200];
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		++bucket[v[i]];
	}

	long long best_cost = 1000 * 1000 * 1000 * 1ll * 1000 * 1000 * 1000;
	long long cost;
	for (int i = 0; i < 200; ++i)
	{
		cost = 0;
		for (int j = 0; j < i; ++j)
			cost += bucket[j] * (i - j) * (i - j);
		for (int j = 199; j > i + 17; --j)
			cost += bucket[j] * (j - i) * (j - i);
		best_cost = min(best_cost, cost);
	}
	cout << best_cost << endl;
}