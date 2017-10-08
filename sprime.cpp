/*
ID: misha101
LANG: C++11
TASK: sprime
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

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

void rec(int curr_depth, int num, int depth)
{
	if (curr_depth > depth)
		return;
	if (!is_prime(num))
		return;
	if (curr_depth == depth)
	{
		ans.push_back(num);
		return;
	}

	for (int i = 1; i <= 9; ++i)
	{
		num = num * 10 + i;
		rec(curr_depth + 1, num, depth);
		num /= 10;
	}
}

int main()
{
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
	int n;
	cin >> n;
	int pr[4] = { 2, 3, 5, 7 };
	for (int i = 0; i < 4; ++i)
		rec(1, pr[i], n);

	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << endl;
}