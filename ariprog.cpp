/*
ID: misha101
LANG: C++11
TASK: ariprog
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

const int maxn = 125000;
bool bucket[maxn + 1];

using namespace std;

int main()
{
	freopen("ariprog.in", "r", stdin);
	freopen("ariprog.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= m; ++i)
	for (int j = i; j <= m; ++j)
		bucket[i * i + j * j] = 1;
	vector <int> v;
	for (int i = 0; i <= maxn; ++i)
	if (bucket[i])
		v.push_back(i);
	int counter = 0;
	bool found_ans = 0;
	int upper_bound = m * m;
	if (n >= 15)
		upper_bound = 10000;
	for (int b = 1; b <= upper_bound; ++b)
	{
		for (int i = 0; i < v.size(); ++i)
		{
			int a = v[i];
			bool found = true;
			for (int len = 0; len < n; ++len)
			{
				if (a + len * b > v.back() || !bucket[a + len * b])
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				printf("%d %d\n", a, b);
				found_ans = 1;
				++counter;
			}
			if (counter >= 10000)
				break;
		}
		if (counter >= 10000)
			break;
	}
	if (!found_ans)
		cout << "NONE" << endl;
	return 0;
}