/*
ID: misha101
LANG: C++11
TASK: palsquare
*/

#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream cin("palsquare.in");
ofstream cout("palsquare.out");

vector <char> inbase(int a, int b)
{
	vector <char> ans;
	while (a > 0)
	{
		int mod = a % b;
		if (mod < 10)
			ans.push_back(mod + '0');
		else
			ans.push_back(mod - 10 + 'A');
		a /= b;
	}
	return ans;
}

bool is_palindrom(const vector <char>& v)
{
	for (int i = 0; i <= v.size() / 2; ++i)
	if (v[i] != v[v.size() - 1 - i])
		return false;
	return true;
}

void print(const vector <char>& v)
{
	for (int i = v.size() - 1; i >= 0; --i)
		cout << v[i];
}

int main()
{
	int base;
	cin >> base;

	for (int i = 1; i <= 300; ++i)
	{
		vector <char> v = inbase(i * i, base);
		if (is_palindrom(v))
		{
			print(inbase(i, base));
			cout << ' ';
			print(v);
			cout << endl;
		}
	}
}