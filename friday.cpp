/*
ID: misha101
LANG: C++11
TASK: friday
*/

#include <fstream>

using namespace std;

int days[7];
int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool is_leap(int year)
{
	return (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0);
}

int main()
{
	ifstream cin("friday.in");
	ofstream cout("friday.out");
	int years, last, y, left = 0;
	cin >> years;

	for (int curr_year = 1900; curr_year < 1900 + years; ++curr_year)
	{
		if (is_leap(curr_year))
			month[1] = 29;
		else
			month[1] = 28;

		for (y = 0; y < 12; y++)
		{
			++days[(left + 13) % 7];
			left = (month[y] + left) % 7;
		}
	}
	for (int i = 0; i < 7; ++i)
	{
		cout << days[(i + 6) % 7];
		if (i != 6)
			cout << ' ';
	}
	cout << endl;
	return 0;
}