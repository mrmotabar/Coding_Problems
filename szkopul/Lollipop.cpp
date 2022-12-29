/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
int n, m, k, a[MAX_N], parsh[MAX_N];
vector<int> ye;
char c;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		if (c == 'T')
		{
			a[i] = 2;
		}
		else
		{
			a[i] = 1;
			ye.pb(i);
		}
		parsh[i] = parsh[i - 1] + a[i];
	}
	while (m--)
	{
		scanf("%d", &k);
		if (k > parsh[n])
		{
			printf("NIE\n");
			continue;
		}
		int ind = lower_bound(parsh + 1, parsh + n + 1, k) - parsh;
		if (ye.size() == 0)
		{
			if (k % 2 == 1)
			{
				printf("NIE\n");
			}
			else
			{
				printf("1 %d\n", k / 2);
			}
		}
		else
		{
			if (parsh[ind] == k)
			{
				printf("1 %d\n", ind);
			}
			else
			{
				int doye = lower_bound(ye.begin(), ye.end(), ind) - ye.begin();
				if (ye[0] < ind)
				{
					if (doye == ye.size() && ind + ye[0] - 1 <= n)
					{
						// cout<<ye[0]+1<<" "<<ind+ye[0]-1<<endl;
						printf("%d %d\n", ye[0] + 1, ind + ye[0] - 1);
					}
					else if (ye[0] <= ye[doye] - ind && ind + ye[0] - 1 <= n && doye != ye.size())
					{
						printf("%d %d\n", ye[0] + 1, ind + ye[0] - 1);
					}
					else if (ye[0] > ye[doye] - ind && doye != ye.size())
					{
						// cout<<1+ye[doye]-ind<<" "<<ye[doye]<<endl;
						printf("%d %d\n", ye[doye] + 1 - ind, ye[doye]);
					}
					else
					{
						// cout<<"NIE"<<endl;
						printf("NIE\n");
					}
				}
				else
				{
					// cout<<1+ye[0]-ind<<" "<<ye[0]<<endl;
					printf("%d %d\n", ye[0] + 1 - ind, ye[0]);
				}
			}
		}
	}
}
