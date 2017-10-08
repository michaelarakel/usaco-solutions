/*
ID: misha101
LANG: C++11
TASK: milk
*/

#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ifstream cin("milk.in");
	ofstream cout("milk.out");

	int n, desired_amount;
	cin >> desired_amount >> n;

	vector < pair <int, int> > sellers(n);

	for (int i = 0; i < n; ++i)
		cin >> sellers[i].first >> sellers[i].second;
	sort(sellers.begin(), sellers.end());

	int price = 0;
	int current_amount = 0;

	for (int i = 0; i < n; ++i)
	{
		if (current_amount >= desired_amount)
			break;

		if (current_amount + sellers[i].second <= desired_amount)
		{
			 current_amount += sellers[i].second;
			 price += sellers[i].first * sellers[i].second;
		}
		else
		{
			price += (desired_amount - current_amount) * sellers[i].first;
			current_amount = desired_amount;
		}
	}

	cout << price << endl;
}