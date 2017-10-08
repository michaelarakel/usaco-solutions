/*
ID: misha101
LANG: C++11
TASK: pprime
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <deque>

using namespace std;

int start, finish;
vector <int> ans;

bool is_prime(int n)
{
	if (n == 2)
		return true;
	if (!(n & 1))
		return false;
	for (int i = 3; i * 1ll * i <= n; i += 2)
	if (n % i == 0)
		return false;
	return true;
}

bool is_palindrome(int n)
{
	ostringstream oss;
	oss << n;
	string s(oss.str());
	for (int i = 0; i <= s.size() / 2; ++i)
	if (s[i] != s[s.size() - i - 1])
		return false;
	return true;
}

int get_num(deque <int> d, int yes)
{
	ostringstream oss;
	for (auto it : d)
		oss << it;
	for (int i = d.size() - 1 - yes; i >= 0; --i)
		oss << d[i];
	istringstream iss(oss.str());
	int res;
	iss >> res;
	return res;
}

void find_pprime(int length, deque <int>& d, int yes)
{
	if (!length)
	{
		int num = get_num(d, yes);
		if (num >= start && num <= finish &&
			is_palindrome(num) && is_prime(num))
			ans.push_back(num);
		return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		d.push_back(i);
		find_pprime(length - 1, d, yes);
		d.pop_back();
	}
}

int main()
{
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	cin >> start >> finish;
	int lengths[9] = { 0, 0, 0, 1, 1, 2, 2, 3, 3 };
	for (int i = 1; i <= 8; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			deque <int> d;
			d.push_back(j);
			find_pprime(lengths[i], d, i & 1);
			d.pop_back();
		}
	}


	sort(ans.begin(), ans.end());
	for (auto it : ans)
		cout << it << endl;
}