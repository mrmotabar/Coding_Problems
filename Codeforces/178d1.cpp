/*mohammadreza motabar*/
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define F first
#define S second
int a[20 + 10], q[80], n;
int mark[80 + 10], f[20];
inline bool check(int x)
{
	if (mark[a[x]] > 1)
	{
		return 0;
	}
	return 1;
}
inline void bt(int x)
{
	for (int i = 1; i <= n * n; i++)
	{
		a[x] = i;
		mark[a[x]]++;
		if (check(x))
		{
			if (x == n * n)
			{
				fill(f, f + 20, 0);
				int gh1 = 0, gh2 = 0;
				if (n == 3)
				{
					gh1 = q[a[1]] + q[a[5]] + q[a[9]];
					gh2 = q[a[7]] + q[a[5]] + q[a[3]];
				}
				if (n == 2)
				{
					gh1 = q[a[1]] + q[a[4]];
					gh2 = q[a[2]] + q[a[3]];
				}
				int y = 1;
				for (int l = 1; l <= n; l++)
				{
					for (int p = 1; p <= n; p++)
					{
						f[y] += q[a[(l - 1) * n + p]];
					}
					y++;
				}
				for (int l = 1; l <= n; l++)
				{
					for (int p = 1; p <= n; p++)
					{
						f[y] += q[a[(p - 1) * n + l]];
					}
					y++;
				}
				bool e = 1;
				for (int l = 1; l < y; l++)
				{
					if (f[l] != f[1])
					{
						e = 0;
					}
				}
				if (gh1 == gh2 && gh1 == f[1] && e)
				{
					cout << f[1] << endl;
					for (int l = 1; l <= n; l++)
					{
						for (int p = 1; p <= n; p++)
						{
							cout << q[a[(l - 1) * n + p]] << " ";
						}
						cout << endl;
					}
					exit(0);
				}
				mark[a[x]]--;
				a[x] = 0;
				return;
			}
			bt(x + 1);
		}
		mark[a[x]]--;
		a[x] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n * n; i++)
		cin >> q[i];
	if (n == 1)
	{
		cout << q[1] << endl;
		cout << q[1];
		return 0;
	}
	bt(1);
}
