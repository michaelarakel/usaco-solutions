/*
ID: misha101
LANG: C++11
TASK: transform
*/

#include <fstream>
#include <vector>

using namespace std;

void reflect(vector < vector <char> >& v)
{
	for (int i = 0; i < v.size(); ++i)
	for (int j = 0; j < v[i].size()/2; ++j)
		swap(v[i][j], v[i][v[i].size() - j - 1]);
}

void transpone(vector < vector <char> >& v)
{
	for (int i = 0; i < v.size(); ++i)
	for (int j = i + 1; j < v[i].size(); ++j)
		swap(v[i][j], v[j][i]);
}

void rotate(vector < vector <char> >& v)
{
	transpone(v);
	reflect(v);
}

int main()
{
	ifstream cin("transform.in");
	ofstream cout("transform.out");
	int n;
	cin >> n;
	vector < vector <char> > before(n, vector <char>(n)),
		after = before;

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		cin >> after[i][j];

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		cin >> before[i][j];

	for (int i = 1; i <= 3; ++i)
	{
		rotate(before);
		if (before == after)
		{
			cout << i << endl;
			return 0;
		}
	}
	rotate(before);//360 degree spin

	reflect(before);
	if (before == after)
	{
		cout << 4 << endl;
		return 0;
	}

	for (int i = 1; i <= 3; ++i)
	{
		rotate(before);
		if (before == after)
		{
			cout << 5 << endl;
			return 0;
		}
	}
	rotate(before);
	reflect(before);

	if (after == before)
	{
		cout << 6 << endl;
		return 0;
	}

	cout << 7 << endl;
	return 0;
}