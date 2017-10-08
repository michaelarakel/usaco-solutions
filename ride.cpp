/*
ID: misha101
LANG: C++11
TASK: ride
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int base = 47;

int num(const string& s)
{
	int res = 1;
	for (int i = 0; i < s.size(); ++i)
		res = (res * (s[i] - 'A' + 1)) % base;
	return res;
}

int main()
{
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);

	string s[2];
	cin >> s[0] >> s[1];
	if (num(s[0]) == num(s[1]))
		cout << "GO";
	else
		cout << "STAY";
	cout << endl;
	return 0;
}