#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
string s;
int z[MAX_N], sort_z[MAX_N];
vector<pair<int, int>> ans;
void read_input()
{
	cin >> s;
}
void write_output()
{
	cout << ans.size() << endl;
	for (pair<int, int> i : ans)
	{
		cout << i.first << " " << i.second << endl;
	}
}
void fill_z()
{
	int l = 0, r = 0, n = s.size();
	z[0] = n;
	for (int i = 1; i < n; i++)
	{
		if (i > r)
		{
			l = i;
			r = i;
			while (r < n && s[r - l] == s[r])
			{
				r++;
			}
			z[i] = r - l;
			r--;
		}
		else
		{
			int k = i - l;
			if (z[k] < r - i + 1)
			{
				z[i] = z[k];
			}
			else
			{
				l = i;
				while (r < n && s[r - l] == s[r])
				{
					r++;
				}
				z[i] = r - l;
				r--;
			}
		}
	}
}
void solve()
{
	fill_z();
	for (int i = 0; i < s.size(); i++)
	{
		sort_z[i] = z[i];
	}
	sort(sort_z, sort_z + s.size());
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (i + z[i] == s.size())
		{
			int cnt = lower_bound(sort_z, sort_z + s.size(), z[i]) - sort_z;
			cnt = s.size() - cnt;
			ans.push_back({z[i], cnt});
		}
	}
}
int main()
{
	read_input();
	solve();
	write_output();
}
