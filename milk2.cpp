/*
ID: misha101
LANG: C++11
TASK: milk2
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("milk2.in");
	ofstream cout("milk2.out");
	int n;
	cin >> n;
	vector < pair <int, int> > v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());

	vector < pair <int, int> > segments;
	for (int i = 0; i < n; )
	{
		pair <int, int> curr = v[i];
		int j;
		for (j = i + 1; j < n; ++j)
		{
			if (v[j].first <= curr.second)
				curr.second = max(curr.second, v[j].second);
			else
				break;
		}
		i = j;
		segments.push_back(curr);
	}

	int max_work = 0, max_lazy = 0;
	for (int i = 0; i < segments.size(); ++i)
		max_work = max(max_work, segments[i].second - segments[i].first);
	for (int i = 1; i < segments.size(); ++i)
		max_lazy = max(max_lazy, segments[i].first - segments[i - 1].second);

	cout << max_work << ' ' << max_lazy << endl;
}