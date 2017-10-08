/*
ID: misha101
LANG: C++11
TASK: checker
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int counter;

void sol(int Qnum, vector < vector <char> >& v, int n, vector <char>& col, vector <char>& diag1, vector <char>& diag2, vector <int>& col_ord)
{
	if (Qnum == n)
	{
		counter++;
		if (counter <= 3)
		{
			for (int i = 0; i < col_ord.size(); ++i)
			{
				cout << col_ord[i] + 1;
				if (i != col_ord.size() - 1)
					cout << ' ';
			}
			cout << endl;
		}
		return;
	}
	int i = Qnum;
	for (int j = 0; j < n; j++)
	{
		int diag1Def = i - j + n - 1, diag2Def = (n - 1 - i) - j + n - 1;
		if (v[i][j] != '*' && col[j] && diag1[diag1Def] && diag2[diag2Def])
		{
			v[i][j] = 'Q';
			col_ord.push_back(j);
			col[j] = diag1[diag1Def] = diag2[diag2Def] = false;
			sol(Qnum + 1, v, n, col, diag1, diag2, col_ord);
			v[i][j] = '.';
			col[j] = diag1[diag1Def] = diag2[diag2Def] = true;
			col_ord.pop_back();
		}
	}
	return;
}

void nextit(int n, int itnum)
{
	vector <char> col(n, true), d1(2 * n - 1, true), d2(2 * n - 1, true);
	vector < vector <char> > field(n, vector <char>(n, '.'));
	int Qnum = 0;
	vector <int> v;
	sol(Qnum, field, n, col, d1, d2, v);
	cout << counter << endl;
}

int main()
{
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);
	int n, itnum = 1;
	cin >> n;
	while (n != 0)
	{
		nextit(n, itnum);
		n = 0;
		itnum++;
	}
}