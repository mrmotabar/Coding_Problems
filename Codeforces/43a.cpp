#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string, int> mp;
int main()
{
	int n;
	cin >> n;
	string a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		mp[a]++;
	}
	int max = 0;
	string ans;
	for (pair<string, int> u : mp)
	{
		if (u.second > max)
		{
			max = u.second;
			ans = u.first;
		}
	}
	cout << ans;
}
