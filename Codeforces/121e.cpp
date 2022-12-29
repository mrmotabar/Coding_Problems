#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
#define ll long long
#define pb push_back
#define F first
#define S second
typedef pair<int, pair<int, int>> ppii;
int n, m, a[MAX_N], naz[MAX_N];
ppii seg[4 * MAX_N];
int lazy[4 * MAX_N];
vector<int> lucky;
void plu(int x, int t)
{
    if (t == 5)
    {
        return;
    }
    lucky.pb(x);
    plu(x * 10 + 4, t + 1);
    plu(x * 10 + 7, t + 1);
}
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id] = {lucky[naz[b]] - a[b], {1, b}};
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    if (seg[id * 2].F < seg[id * 2 + 1].F)
    {
        seg[id] = seg[id * 2];
    }
    else if (seg[id * 2].F > seg[id * 2 + 1].F)
    {
        seg[id] = seg[id * 2 + 1];
    }
    else
    {
        seg[id].F = seg[id * 2].F;
        seg[id].S.F = seg[id * 2].S.F + seg[id * 2 + 1].S.F;
        seg[id].S.S = seg[id * 2].S.S;
    }
}
void shift(int id, int b, int e)
{
    seg[id * 2].F -= lazy[id];
    lazy[id * 2] += lazy[id];
    seg[id * 2 + 1].F -= lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}
void merge(int id)
{
    if (seg[id * 2].F < seg[id * 2 + 1].F)
    {
        seg[id] = seg[id * 2];
    }
    else if (seg[id * 2].F > seg[id * 2 + 1].F)
    {
        seg[id] = seg[id * 2 + 1];
    }
    else
    {
        seg[id].F = seg[id * 2].F;
        seg[id].S.F = seg[id * 2].S.F + seg[id * 2 + 1].S.F;
        seg[id].S.S = seg[id * 2].S.S;
    }
}
void upd(int id, int b, int e, int l, int r, int d)
{
    if (b >= r || l >= e)
    {
        return;
    }
    if (l <= b && e <= r)
    {
        seg[id].F -= d;
        lazy[id] += d;
        return;
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, l, r, d);
    upd(id * 2 + 1, mid, e, l, r, d);
    merge(id);
}
void upd2(int id, int b, int e, int p)
{
    if (p >= e || p < b)
    {
        return;
    }
    if (e - b == 1)
    {
        naz[b]++;
        seg[id].F = lucky[naz[b]] - (lucky[naz[b] - 1] + (-1 * seg[id].F));
        seg[id].S.F = 1;
        seg[id].S.S = b;
        return;
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    upd2(id * 2, b, mid, p);
    upd2(id * 2 + 1, mid, e, p);
    merge(id);
}
ppii get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return {1e5, {1, 1}};
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    ppii x = get(id * 2, b, mid, l, r), y = get(id * 2 + 1, mid, e, l, r);
    if (x.F < y.F)
    {
        return x;
    }
    else if (x.F > y.F)
    {
        return y;
    }
    else
    {
        return {x.F, {x.S.F + y.S.F, x.S.S}};
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    plu(0, 0);
    lucky[0] = 44444;
    sort(lucky.begin(), lucky.end());
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        naz[i] = lower_bound(lucky.begin(), lucky.end(), a[i]) - lucky.begin();
    }
    build(1, 1, n + 1);
    for (int i = 0; i < m; i++)
    {
        string s;
        int l, r, d;
        cin >> s;
        if (s == "add")
        {
            cin >> l >> r >> d;
            upd(1, 1, n + 1, l, r + 1, d);
            while (seg[1].F < 0)
            {
                upd2(1, 1, n + 1, seg[1].S.S);
            }
        }
        else
        {
            cin >> l >> r;
            ppii x = get(1, 1, n + 1, l, r + 1);
            if (x.F > 0)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << x.S.F << "\n";
            }
        }
    }
}
