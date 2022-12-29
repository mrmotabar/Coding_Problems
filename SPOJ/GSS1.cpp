#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX_N = 1e5 + 10, INF = 1e10;
struct segment
{
    ll ans, suf, pre, sum;
} seg[4 * MAX_N];
ll n, m, a[MAX_N];
segment merge(segment x, segment y)
{
    segment ret = {0, 0, 0, 0};
    ret.sum = x.sum + y.sum;
    ret.pre = max(y.pre, y.sum + x.pre);
    ret.suf = max(x.suf, x.sum + y.suf);
    ret.ans = max(max(x.ans, y.ans), x.pre + y.suf);
    return ret;
}
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id] = {a[b], a[b], a[b], a[b]};
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = merge(seg[id * 2], seg[id * 2 + 1]);
}
segment get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return {-INF, -INF, -INF, -INF};
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    int mid = (b + e) / 2;
    return merge(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
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
    build(1, 1, n + 1);
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << get(1, 1, n + 1, x, y + 1).ans << "\n";
    }
}
