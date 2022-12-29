#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<char, int> a;
string h;
int main()
{
	int k;
	string s;
	cin >> k >> s;
	for (int i = 0; i < s.size(); i++)
	{
		a[s[i]]++;
	}
	for (pair<char, int> u : a)
	{
		for (int j = 0; j < u.second / k; j++)
		{
			h += u.first;
		}
		if (u.second % k != 0)
		{
			cout << -1;
			return 0;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << h;
	}
}
