/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
#define F first
#define S second
int n, q, ans;
vector<pair<pair<int, int>, int>> s;
int a[100], b[100];
inline int al(char x)
{
	return int(x) - int('a') + 1;
}
inline bool check()
{
	for (int i = 1; i <= n; i++)
	{
		b[i] = a[i];
	}
	int f = 0;
	while (1)
	{
		bool c = 1;
		for (auto u : s)
		{
			if (u.first.first == b[1] && u.first.second == b[2])
			{
				if (f == n - 1)
				{
					break;
				}
				b[2] = u.second;
				f++;
				for (int j = 1; j < n; j++)
				{
					b[j] = b[j + 1];
					// cout<<b[j]<<" ";
				}
				// cout<<endl;
				c = 0;
			}
		}
		if (f == n - 1)
		{
			if (b[1] == 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		if (c)
		{
			return 0;
		}
	}
}
inline void bt(int x)
{
	for (int i = 1; i <= 6; i++)
	{
		a[x] = i;
		if (x == n + 1)
		{
			//	for(int k=1;k<=n;k++){
			//		cout<<a[k]<<" ";
			//	}
			//	cout<<endl;
			if (check())
			{
				ans++;
			}
			a[x] = 0;
			return;
		}
		bt(x + 1);
	}
}
int main()
{
	cin >> n >> q;
	char x, y, z;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y >> z;
		s.push_back({{al(x), al(y)}, al(z)});
	}
	bt(1);
	cout << ans;
	//	for(int i=1;i<=n;i++){
	//		cin>>a[i];
	//	}
	//	cout<<check();
}
