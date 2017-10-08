/*
ID: misha101
LANG: C++11
TASK: frac1
*/

#include <iostream>
#include <set>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

struct fraction
{
	fraction(int p = 0, int q = 1) :p(p), q(q)
	{
		normalize();
	}
	int p;
	int q;
	void normalize()
	{
		int g = gcd(p, q);
		p /= g;
		q /= g;
	}

	bool operator < (const fraction& f) const
	{
		return (p * 1. / q) < f.p * 1. / f.q;
	}
};

int main()
{
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
	int n;
	cin >> n;
	set <fraction> s;

	for (int denom = 1; denom <= n; ++denom)
		for (int i = 0; i <= denom; ++i)
			s.insert(fraction(i, denom));

	for (auto it : s)
		cout << it.p << "/" << it.q << endl;
}

