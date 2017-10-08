/*
ID: misha101
LANG: C++11
TASK: barn1
*/

#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main()
{
	ifstream cin("barn1.in");
	ofstream cout("barn1.out");
	int m, s, n;
	cin >> m >> s >> n;
	vector <int> cows(n);
	for (int i = 0; i < n; ++i)
		cin >> cows[i];
	sort(cows.begin(), cows.end());

	vector <int> differences;
	for (int i = 0; i < n - 1; ++i)
		differences.push_back(cows[i + 1] - cows[i]);
	sort(differences.rbegin(), differences.rend());
	int ans = cows[n - 1] - cows[0] + 1;
	for (int i = 0; i < m - 1 && i < n - 1; ++i)
		ans -= differences[i] - 1;

	cout << ans << endl;
}