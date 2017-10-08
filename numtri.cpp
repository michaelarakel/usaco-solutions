/*
ID: misha101
LANG: C++11
TASK: numtri
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
	int n;
	cin >> n;
	vector < vector <long long> > v(n, vector <long long>(n));

	for (int i = 0; i < n; ++i)
	for (int j = 0; j <= i; ++j)
		cin >> v[i][j];

	for (int i = 1; i < v.size(); ++i)
	for (int j = 0; j < v[i].size(); ++j)
	{
		long long temp = v[i - 1][j];
		if (j)
			temp = max(temp, v[i - 1][j - 1]);
		v[i][j] += temp;
	}

	cout << *(max_element(v[v.size() - 1].begin(), v[v.size() - 1].end())) << endl;
}