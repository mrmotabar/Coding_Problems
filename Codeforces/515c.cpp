#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a[100], ans;
int main()
{
	a[2].push_back(2);
	a[3].push_back(3);
	a[4].push_back(3);
	a[4].push_back(2);
	a[4].push_back(2);
	a[5].push_back(5);
	a[6].push_back(3);
	a[6].push_back(5);
	a[7].push_back(7);
	a[8].push_back(7);
	a[8].push_back(2);
	a[8].push_back(2);
	a[8].push_back(2);
	a[9].push_back(7);
	a[9].push_back(2);
	a[9].push_back(3);
	a[9].push_back(3);
	int n;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		int p = int(s[i]) - int('0');
		for (int j = 0; j < a[p].size(); j++)
		{
			ans.push_back(a[p][j]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
}
