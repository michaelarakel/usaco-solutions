/*
ID: misha101
LANG: C++11
TASK: namenum
*/

//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set <string> name_dict;
bool found_ans = 0;
char mapping[8][3] = { { 'A', 'B', 'C' }, { 'D', 'E', 'F' }, { 'G', 'H', 'I' }, { 'J', 'K', 'L' }, { 'M', 'N', 'O' }, { 'P', 'R', 'S' }, { 'T', 'U', 'V' }, { 'W', 'X', 'Y' } };

ifstream cin("namenum.in");
ofstream cout("namenum.out");

void rec(const string& base, string& curr)
{
	if (curr.size() == base.size())
	{
		if (name_dict.find(curr) != name_dict.end())
		{
			found_ans = true;
			cout << curr << endl;
		}
		return;
	}

	for (int j = 0; j < 3; ++j)
	{
		curr.push_back(mapping[(base[curr.size()] - '2')][j]);
		rec(base, curr);
		curr.pop_back();
	}
}

int main()
{
	ifstream read_names("dict.txt");
	string name;
	int max = 0;
	while (read_names >> name)
		name_dict.insert(name);

	string s;
	cin >> s;

	if (s.find('1') != string::npos ||
		s.find('0') != string::npos)
	{
		cout << "NONE" << endl;
		return 0;
	}

	string t;
	rec(s, t);
	if (!found_ans)
		cout << "NONE" << endl;

	return 0;
}