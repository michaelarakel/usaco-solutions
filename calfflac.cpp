/*
ID: misha101
LANG: C++11
TASK: calfflac
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <deque>
#include <algorithm>
#include <vector>

using namespace std;

unsigned long long bin_pow(unsigned long long a, unsigned long long n, unsigned long long p)
{
	unsigned long long res = 1;
	while (n)
	{
		if (n & 1)
		{
			res = ((res % p) * (a % p)) % p;
			--n;
		}
		else
		{
			a = (a * a) % p;
			n >>= 1;
		}
	}
	return res;
}

struct rolling_hash
{
	rolling_hash() : hash(0), base_pow(1)
	{
	//	base_inverse = 0;// bin_pow(base, p - 2, p);
	}
	void push_back(const char c)
	{
		hash = (hash * base + (c - 'a' + 1));
		base_pow = (base_pow * base);
		//line.push_back(c);
	}
	void push_front(const char c)
	{
		hash = (hash + (c - 'a' + 1) * base_pow);
		base_pow = (base_pow * base);
		//line.push_front(c);
	}
	/*void pop_front()
	{
		base_pow = (base_pow * base_inverse) % p;
		hash = (hash - (base_pow * line.front()) % p);
		line.pop_front();
	}
	void pop_back()
	{
		base_pow = (base_pow * base_inverse) % p;
		hash = ((hash - line.back()) * base_inverse) % p;
		line.pop_back();
	}*/
	bool operator == (const rolling_hash& h)
	{
		//if (line.size() != h.line.size())
		//return false;
		return hash == h.hash;
		/*for (int i = 0; i < line.size(); ++i)
		if (line[i] != h.line[i])
			return false;
		return true;*/
	}
	//static const unsigned long long p = 402653189;
	static const unsigned long long base = 193;
	unsigned long long base_pow;
	//unsigned long long base_inverse;
	unsigned long long hash;
	//deque <char> line;
};

int main()
{
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);
	vector <char> initial_text;
	vector <char> text;
	vector <int> positions;

	char c;
	while ((c = getchar()) != EOF)
	{
		initial_text.push_back(c);
		if (isalpha(c))
		{
			text.push_back(tolower(c));
			positions.push_back(initial_text.size() - 1);
		}
	}

	int best_i = 0, best_j = -1;
	for (int i = 0; i < text.size(); ++i)
	{
		rolling_hash straight;
		rolling_hash reverse;
		for (int j = i; j < text.size(); ++j)
		{
			straight.push_back(text[j]);
			reverse.push_front(text[j]);
			if (straight == reverse && ((j - i) >(best_j - best_i)))
			{
				best_i = i;
				best_j = j;
			}
			if (j - i + 1 == 2000)
				break;
		}
	}

	int counter = 0;
	for (int i = positions[best_i]; i <= positions[best_j]; ++i)
		if (isalpha(initial_text[i]))
			++counter;
	printf("%d\n", counter);
	for (int i = positions[best_i]; i <= positions[best_j]; ++i)
		printf("%c", initial_text[i]);
	cout << endl;
}