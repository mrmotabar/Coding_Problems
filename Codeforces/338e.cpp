#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 2e5;
int n, len, h, a[MAX_N], b[MAX_N], ans;
int seg[4 * MAX_N], lazy[4 * MAX_N];
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id] = -b;
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
void shift(int id)
{
    seg[id * 2] += lazy[id];
    lazy[id * 2] += lazy[id];
    seg[id * 2 + 1] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
    lazy[id] = 0;
}
void add(int id, int b, int e, int l, int r, int x)
{
    if (l >= e || b >= r)
    {
        return;
    }
    if (l <= b && e <= r)
    {
        seg[id] += x;
        lazy[id] += x;
        return;
    }
    shift(id);
    int mid = (b + e) / 2;
    add(id * 2, b, mid, l, r, x);
    add(id * 2 + 1, mid, e, l, r, x);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> len >> h;
    for (int i = 1; i <= len; i++)
    {
        cin >> b[i];
    }
    sort(b + 1, b + len + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, len + 1);
    for (int i = 1; i <= len; i++)
    {
        int ind = lower_bound(b + 1, b + len + 1, h - a[i]) - b;
        add(1, 1, len + 1, ind, len + 1, 1);
    }
    if (seg[1] >= 0)
    {
        ans++;
    }
    for (int i = len + 1; i <= n; i++)
    {
        int inda = lower_bound(b + 1, b + len + 1, h - a[i]) - b;
        int indm = lower_bound(b + 1, b + len + 1, h - a[i - len]) - b;
        add(1, 1, len + 1, inda, len + 1, 1);
        add(1, 1, len + 1, indm, len + 1, -1);
        if (seg[1] >= 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
}
