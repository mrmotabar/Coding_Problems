#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;
const int MAX_N = 1e6 + 10;
int n, q, a[MAX_N], last[MAX_N], ans[MAX_N], seg[4 * MAX_N];
pair<pii, int> qu[MAX_N];
void upd(int id, int b, int e, int p, int v)
{
    if (p < b || p >= e)
    {
        return;
    }
    if (e - b == 1)
    {
        seg[id] += v;
        return;
    }
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, p, v);
    upd(id * 2 + 1, mid, e, p, v);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return 0;
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    int mid = (b + e) / 2;
    return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> qu[i].F.S >> qu[i].F.F;
        qu[i].S = i;
    }
    sort(qu, qu + q);
    int ind = 0;
    for (int i = 1; i <= n; i++)
    {
        upd(1, 1, n + 1, last[a[i]], -1);
        last[a[i]] = i;
        upd(1, 1, n + 1, last[a[i]], 1);
        while (qu[ind].F.F == i)
        {
            ans[qu[ind].S] = get(1, 1, n + 1, qu[ind].F.S, i + 1);
            ind++;
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << "\n";
    }
}
