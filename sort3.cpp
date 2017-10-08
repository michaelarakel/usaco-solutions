/*
ID: misha101
LANG: C++11
TASK: sort3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int counterOf[4];
int tranpositionCounter[3][3];

int main()
{
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		++counterOf[v[i]];
	}
	for (int i = 1; i < 4; ++i)
		counterOf[i] += counterOf[i - 1];

	for (int i = 0; i < 3; ++i)
	for (int j = counterOf[i]; j < counterOf[i + 1]; ++j)
		++tranpositionCounter[i][v[j] - 1];

	int ans = 0;
	for (int i = 0; i < 3; ++i)
	for (int j = 0; j < i; ++j)
		ans += min(tranpositionCounter[i][j], tranpositionCounter[j][i]);

	ans += 2 * (max(tranpositionCounter[0][1], tranpositionCounter[1][0]) - min(tranpositionCounter[0][1], tranpositionCounter[1][0]));
	cout << ans << endl;
}