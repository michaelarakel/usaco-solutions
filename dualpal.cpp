/*
ID: misha101
LANG: C++11
TASK: dualpal
*/

#include <fstream>
#include <vector>

using namespace std;

vector <char> inbase(int a, int b)
{
	vector <char> ans;
	while (a > 0)
	{
		int mod = a % b;
		ans.push_back(mod + '0');
		a /= b;
	}
	return ans;
}

bool is_palindrome(const vector <char>& v)
{
	for (int i = 0; i <= v.size() / 2; ++i)
	if (v[i] != v[v.size() - 1 - i])
		return false;
	return true;
}

int main()
{
	ifstream cin("dualpal.in");
	ofstream cout("dualpal.out");
	int n, s;
	cin >> n >> s;
	int counter = 0;
	for (int i = s + 1; counter < n; ++i)
	{
		int curr_counter = 0;
		for (int base = 2; base <= 10; ++base)
		if (is_palindrome(inbase(i, base)))
		{
			++curr_counter;
			if (curr_counter == 2)
				break;
		}
		if (curr_counter == 2)
		{
			cout << i << endl;
			++counter;
		}
	}
}