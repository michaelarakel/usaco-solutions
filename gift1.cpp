/*
ID: misha101
LANG: C++11
TASK: gift1
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int n;
	cin >> n;
	vector <string> names(n);
	vector <int> gifts(n);
	vector <int> money(n);

	for (int i = 0; i < n; ++i)
		cin >> names[i];

	string curr_name;
	while (cin >> curr_name)
	{
		if (cin.fail())
			break;
		int pos = find(names.begin(), names.end(), curr_name) - names.begin();
		int money_beginning, gift_num;
		cin >> money_beginning >> gift_num;
		money[pos] += money_beginning;
		if (gift_num != 0)
		{
			gifts[pos] += money_beginning % gift_num;
			int gift_value = money[pos] / gift_num;

			for (int i = 0; i < gift_num; ++i)
			{
				string name;
				cin >> name;
				int gift_pos = find(names.begin(), names.end(), name) - names.begin();
				gifts[gift_pos] += gift_value;
			}
		}
		else
			gifts[pos] += money_beginning;
	}

	for (int i = 0; i < n; ++i)
		cout << names[i] << ' ' << gifts[i] - money[i] << endl;
}