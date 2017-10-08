/*
ID: misha101
LANG: C++11
TASK: crypt1
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool check(int n, const vector <int>& v, bool length_four)
{
	bool satisfies = 1;
	ostringstream oss;
	oss << n;
	string temp(oss.str());
	if ((length_four)&& (temp.size() != 4))
		return false;
	if (!length_four && temp.size() != 3)
		return false;
	for (int i = 0; i < temp.size(); ++i)
	if (find(v.begin(), v.end(), temp[i] - '0') == v.end())
		return false;
	return true;
}

int main()
{
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
	int n;
	cin >> n;
	vector <int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int counter = 0;
	for (int a = 0; a < n; ++a)
	for (int b = 0; b < n; ++b)
	for (int c = 0; c < n; ++c)
	{
		int num = v[a] + 10 * v[b] + 100 * v[c];
		for (int d = 0; d < n; ++d)
		{
			int first = num * v[d];
			if (!check(first, v, false))
				continue;
			for (int e = 0; e < n; ++e)
			{
				int second = num * v[e];
				if (!check(second, v, false))
					continue;
				int res = first + second * 10;
				if (check(res, v, true))
				{
					//cout << num << ' ' << v[d] << v[e] << endl << first << endl << second << endl << res << endl << endl;
					++counter;
				}
			}
		}
	}
	cout << counter << endl;
}