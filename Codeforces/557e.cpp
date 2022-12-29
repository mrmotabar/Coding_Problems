#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 5e3 + 1, MAX_M = 15e6 + 1;
int k, cnt[MAX_M], tri[MAX_M][2 + 1], sz = 1;
;
string s;
bool halfp[MAX_N][MAX_N];
vector<int> path;
void insert(int st, int en)
{
	int v = 0;
	for (int i = st; i < en; i++)
	{
		if (tri[v][s[i] - 'a'] == 0)
		{
			tri[v][s[i] - 'a'] = sz;
			sz++;
		}
		v = tri[v][s[i] - 'a'];
		cnt[v] += halfp[st][i];
	}
}
void dfs(int v, int last)
{
	path.push_back(last);
	k -= cnt[v];
	if (k <= 0)
	{
		for (int i = 1; i < path.size(); i++)
		{
			cout << char(path[i] + int('a'));
		}
		exit(0);
	}
	for (int i = 0; i < 2; i++)
	{
		int u = tri[v][i];
		if (u != 0)
		{
			dfs(u, i);
		}
	}
	path.pop_back();
}
void solve()
{
	for (int j = 0; j < s.size(); j++)
	{
		for (int i = j; i >= 0; i--)
		{
			if (s[i] == s[j])
			{
				halfp[i][j] = (j - i < 5 ? 1 : halfp[i + 2][j - 2]);
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		insert(i, s.size());
	}
	dfs(0, -1);
}
int main()
{
	cin >> s >> k;
	solve();
}
