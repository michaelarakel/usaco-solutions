/*
ID: misha101
LANG: C++11
TASK: clocks
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string movement[9] = { "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI" };
int bucket[9];
int my_clock[9];
int best_bucket[9];
int best_len = 1000 * 1000;

void transformation(int mov_num)
{
	for (int i = 0; i < movement[mov_num].size(); ++i)
		my_clock[movement[mov_num][i] - 'A'] = (my_clock[movement[mov_num][i] - 'A'] + 3) % 12;
}

void rec(int pos)
{
	bool found = true;
	for (int i = 0; i < 9; ++i)
	if (my_clock[i] != 0)
	{
		found = false;
		break;
	}
	if (found)
	{
		int n = 0;
		for (int i = 0; i < 9; ++i)
			n += bucket[i];
		if (n < best_len)
		{
			best_len = n;
			for (int i = 0; i < 9; ++i)
				best_bucket[i] = bucket[i];
		}
		else
		{
			bool better = false;
			for (int i = 0; i < 9; ++i)
			if (bucket[i] < best_bucket[i])
			{
				better = true;
				break;
			}
			if (better)
			{
				for (int i = 0; i < 9; ++i)
					best_bucket[i] = bucket[i];
			}
		}
	}

	if (pos == 9)
		return;

	int temp[9];
	for (int i = 0; i < 9; ++i)
		temp[i] = my_clock[i];

	for (int i = 0; i < 4; ++i)
	{
		bucket[pos] = i;
		for (int j = 0; j < i; ++j)
			transformation(pos);
		rec(pos + 1);
		for (int j = 0; j < 9; ++j)
			my_clock[j] = temp[j];
	}
}

int main()
{
	freopen("clocks.in", "r", stdin);
	freopen("clocks.out", "w", stdout);
	for (int i = 0; i < 9; ++i)
	{
		cin >> my_clock[i];
		my_clock[i] %= 12;
	}

	rec(0);

	for (int i = 0; i < 9; ++i)
	for (int j = 0; j < best_bucket[i]; ++j)
	{
		cout << i + 1;
		--best_len;
		if (best_len != 0)
			cout << ' ';
	}
	cout << endl;
	return 0;
}