/*
ID: misha101
LANG: C++11
TASK: beads
*/

#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("beads.in");
	ofstream cout("beads.out");
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += s;

	vector <int> lengths;
	vector <char> check;
	int i = 0;
	while (i < s.size())
	{
		char curr = s[i];
		int j = i - 1;
		int curr_len = 0;
		bool had_w = 0;
		while (j >= 0 && s[j] == 'w')
		{
			had_w = 1;
			++curr_len;
			--j;
		}
		while (curr == s[i] || s[i] == 'w')
		{
			++curr_len;
			++i;
			if (i == s.size())
				break;
		}
		lengths.push_back(curr_len);
		check.push_back(had_w);
	}

	if (lengths.size() == 1)
	{
		cout << n << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < lengths.size() - 1; ++i)
		ans = max(ans, lengths[i] + lengths[i + 1] - check[i + 1]);
	if (ans > n)
		ans = n;
	cout << ans << endl;
	return 0;
}
