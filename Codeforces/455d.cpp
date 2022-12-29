/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, sq = 334;
int n, q, a[MAX_N], cnt[sq + 100][MAX_N], lastans;
deque<int> arr[sq + 100];
void upd(int l, int r)
{
	int ind1 = l / sq, ind2 = r / sq;
	int x = arr[ind2][r % sq];
	if (ind1 != ind2)
	{
		for (int i = ind1; i < ind2; i++)
		{
			arr[i + 1].push_front(arr[i][arr[i].size() - 1]);
			cnt[i + 1][arr[i][arr[i].size() - 1]]++;
			cnt[i][arr[i][arr[i].size() - 1]]--;
			arr[i].pop_back();
		}
		arr[ind1].pb(0);
		for (int i = arr[ind1].size() - 1; i > l % sq; i--)
		{
			arr[ind1][i] = arr[ind1][i - 1];
		}
		arr[ind1][l % sq] = x;
		cnt[ind1][x]++;
		cnt[ind2][x]--;
		for (int i = r % sq + 1; i < arr[ind2].size() - 1; i++)
		{
			arr[ind2][i] = arr[ind2][i + 1];
		}
		arr[ind2].pop_back();
	}
	else
	{
		int x = arr[ind1][r % sq];
		for (int i = r % sq; i > l % sq; i--)
		{
			arr[ind1][i] = arr[ind1][i - 1];
		}
		arr[ind1][l % sq] = x;
	}
}
int jav(int l, int r, int k)
{
	int ret = 0;
	int ind1 = l / sq, ind2 = r / sq;
	if (ind1 != ind2)
	{
		for (int i = ind1 + 1; i < ind2; i++)
		{
			ret += cnt[i][k];
		}
		for (int i = l % sq; i < arr[ind1].size(); i++)
		{
			if (arr[ind1][i] == k)
				ret++;
		}
		for (int i = 0; i <= r % sq; i++)
		{
			if (arr[ind2][i] == k)
				ret++;
		}
	}
	else
	{
		for (int i = l % sq; i <= r % sq; i++)
		{
			if (arr[ind1][i] == k)
				ret++;
		}
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		arr[i / sq].pb(a[i]);
		cnt[i / sq][a[i]]++;
	}
	cin >> q;
	while (q--)
	{
		int x, l, r, k;
		cin >> x;
		if (x == 1)
		{
			cin >> l >> r;
			l = ((l + lastans - 1) % n);
			r = ((r + lastans - 1) % n);
			if (l > r)
				swap(l, r);
			upd(l, r);
			// for(int i=0;i<n;i++){
			//	cout<<arr[i][0]<<"  ";
			// }
			// cout<<endl;
		}
		else
		{
			cin >> l >> r >> k;
			l = ((l + lastans - 1) % n);
			r = ((r + lastans - 1) % n);
			k = ((k + lastans - 1) % n) + 1;
			if (l > r)
				swap(l, r);
			lastans = jav(l, r, k);
			cout << lastans << endl;
		}
	}
}
