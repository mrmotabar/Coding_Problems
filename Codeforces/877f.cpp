/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
int n, k, sq, t[MAX_N], a[MAX_N], q, l[MAX_N], r[MAX_N], so[MAX_N];
ll prsh[MAX_N], ans, an[MAX_N];
ll tprsh[MAX_N], inp[MAX_N], inpb[MAX_N], inpg[MAX_N];
vector<ll> mp;
bool cmp(int x, int y)
{
    if (l[x] / sq < l[y] / sq || (l[x] / sq == l[y] / sq && r[x] < r[y]))
    {
        return 1;
    }
    return 0;
}
void add(int v, int op)
{
    if (op == 1)
    {
        ans += tprsh[inpb[v]];
    }
    else
    {
        ans += tprsh[inpg[v]];
    }
    tprsh[inp[v]]++;
}
void del(int v, int op)
{
    tprsh[inp[v]]--;
    if (op == 1)
    {
        ans -= tprsh[inpb[v]];
    }
    else
    {
        ans -= tprsh[inpg[v]];
    }
}
void update(int l2, int r2, int b, int e)
{
    if (l2 < b)
    {
        for (int j = b - 1; j >= l2; j--)
        {
            add(j, 0);
        }
    }
    if (e < r2)
    {
        for (int j = e + 1; j <= r2; j++)
        {
            add(j, 1);
        }
    }
    if (e > r2)
    {
        for (int j = e; j > r2; j--)
        {
            del(j, 1);
        }
    }
    if (b < l2)
    {
        for (int j = b; j < l2; j++)
        {
            del(j, 0);
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    sq = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t[i]);
        if (t[i] == 2)
            t[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        prsh[i] += prsh[i - 1] + a[i] * t[i];
        mp.pb(prsh[i]);
        mp.pb(prsh[i] + k);
        mp.pb(prsh[i] - k);
    }
    mp.pb(0);
    mp.pb(-k);
    mp.pb(+k);
    sort(mp.begin(), mp.end());
    mp.resize(unique(mp.begin(), mp.end()) - mp.begin());
    for (int i = 0; i <= n; i++)
    {
        inp[i] = lower_bound(mp.begin(), mp.end(), prsh[i]) - mp.begin();
        inpb[i] = lower_bound(mp.begin(), mp.end(), prsh[i] - k) - mp.begin();
        inpg[i] = lower_bound(mp.begin(), mp.end(), prsh[i] + k) - mp.begin();
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        so[i] = i;
    }
    sort(so + 1, so + q + 1, cmp);
    ans = 0;
    int b = 0, e = 0;
    tprsh[inp[0]] = 1;
    for (int i = 1; i <= q; i++)
    {
        update(l[so[i]] - 1, r[so[i]], b, e);
        b = l[so[i]] - 1;
        e = r[so[i]];
        an[so[i]] = ans;
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", an[i]);
    }
}
