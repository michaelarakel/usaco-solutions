/*
ID: misha101
LANG: C++11
TASK: milk3
*/

#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> possible_states;
int max_a, max_b, max_c;
set < pair < pair < int, int >, int > > s;

void rec(int a, int b, int c)
{
	auto temp = make_pair(make_pair(a, b), c);
	if (s.find(temp) != s.end())
		return;
	s.insert(temp);
	if (a == 0)
		possible_states.push_back(c);

	if (a != 0)
	{
		if (b != max_b)
			if (a + b < max_b)
				rec(0, a + b, c);
			else
				rec(a + b - max_b, max_b, c);
		if (c != max_c)
			if (a + c < max_c)
				rec(0, b, a + c);
			else
				rec(a + c - max_c, b, max_c);
	}
	if (b != 0)
	{
		if (a != max_a)
		if (a + b < max_a)
			rec(a + b, 0, c);
		else
			rec(max_a, a + b - max_a, c);
		if (c != max_c)
		if (b + c < max_c)
			rec(a, 0, b + c);
		else
			rec(a, b + c - max_c, max_c);
	}
	if (c != 0)
	{
		if (a != max_a)
		if (a + c < max_a)
			rec(a + c, b, 0);
		else
			rec(max_a, b, a + c - max_a);
		if (b != max_b)
		if (b + c < max_b)
			rec(a, b + c, 0);
		else
			rec(a, max_b, b + c - max_b);
	}
}

int main()
{
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);

	cin >> max_a >> max_b >> max_c;
	rec(0, 0, max_c);
	sort(possible_states.begin(), possible_states.end());
	possible_states.erase(unique(possible_states.begin(), possible_states.end()), possible_states.end());
	for (int i = 0; i < possible_states.size(); ++i)
	{
		cout << possible_states[i];
		if (i != possible_states.size() - 1)
			cout << ' ';
	}
	cout << endl;
}