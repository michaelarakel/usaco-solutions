/*
ID: misha101
LANG: C++11
TASK: packrec
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int l, w, a, b, best = 10000000;
vector<vector<int> > rect;
set<pair<int, int> > ans;

#define L(i) rect[perm[i]][rotate[i]>0]
#define W(i) rect[perm[i]][1- (rotate[i]>0)]
#define add(a, b) ans.insert(make_pair(min(a, b), max(a, b)))
#define candidate(a, b)  if(a*b <= best){ best = a*b; add(a, b); }

int main() 
{
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);

	for (int i = 0; i < 4; i++) {
		cin >> l >> w;
		vector<int> rec;
		rec.push_back(l), rec.push_back(w), rect.push_back(rec);
	}

	for (int o = 0; o < 16; o++) {
		int rotate[4] = { o & 1, o & 2, o & 4, o & 8 }, perm[4] = { 0, 1, 2, 3 };
		do {
			a = W(0) + W(1) + W(2) + W(3), b = max(max(L(0), L(1)), max(L(2), L(3)));
			candidate(a, b);
			a = max(W(0) + W(1) + W(2), W(3)), b = L(3) + max(L(0), max(L(1), L(2)));
			candidate(a, b);
			a = W(3) + max(W(0) + W(1), W(2)), b = max(L(3), L(2) + max(L(0), L(1)));
			candidate(a, b);
			a = W(0) + max(W(1), W(2)) + W(3), b = max(L(0), max(L(1) + L(2), L(3)));
			candidate(a, b);
			a = max(W(0), W(1)) + W(2) + W(3), b = max(L(0) + L(1), max(L(2), L(3)));
			candidate(a, b);
			a = max(W(0) + W(1), W(2) + W(3)), b = max(L(0) + L(3), L(1) + L(2));
			if (a < W(0) + W(2) && b < L(0) + L(2)) a = W(0) + W(2);
			if (a < W(1) + W(3) && b < L(1) + L(3)) a = W(1) + W(3);
			candidate(a, b);
		} while (next_permutation(perm, perm + 4));
	}
	cout << best << endl;
	for (set<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); it++)
	if (it->first* it->second == best)
		cout << it->first << " " << it->second << endl;

}
