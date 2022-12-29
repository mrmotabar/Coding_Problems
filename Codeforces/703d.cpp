/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
ll n, q, a[MAX_N], l[MAX_N], r[MAX_N], so[MAX_N], ind[MAX_N], last[MAX_N], an[MAX_N];
ll seg[4 * MAX_N];
vector<ll> tar;
bool cmp(int i, int j)
{
    if (r[i] < r[j])
        return 1;
    return 0;
}
void upd(int id, int b, int e, int p)
{
    if (p < b || p >= e)
        return;
    if (e - b == 1)
    {
        seg[id] = a[p];
        return;
    }
    int mid = (e + b) / 2;
    upd(id * 2, b, mid, p);
    upd(id * 2 + 1, mid, e, p);
    seg[id] = seg[id * 2] ^ seg[id * 2 + 1];
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || e <= l)
        return 0;
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    int mid = (e + b) / 2;
    return get(id * 2, b, mid, l, r) ^ get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        tar.pb(a[i]);
    }
    sort(tar.begin(), tar.end());
    tar.resize(unique(tar.begin(), tar.end()) - tar.begin());
    for (int i = 1; i <= n; i++)
    {
        ind[i] = lower_bound(tar.begin(), tar.end(), a[i]) - tar.begin();
    }
    scanf("%lld", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%lld%lld", &l[i], &r[i]);
        so[i] = i;
    }
    sort(so + 1, so + q + 1, cmp);
    int indg = 0;
    for (int i = 1; i <= n; i++)
    {
        if (last[ind[i]] != 0)
        {
            upd(1, 1, n + 1, last[ind[i]]);
        }
        last[ind[i]] = i;
        while (r[so[indg + 1]] == i && indg + 1 <= q)
        {
            an[so[indg + 1]] = get(1, 1, n + 1, l[so[indg + 1]], r[so[indg + 1]] + 1);
            indg++;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        printf("%lld\n", an[i]);
    }
}
