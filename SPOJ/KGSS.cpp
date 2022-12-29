#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
struct segment
{
    int m1, m2;
} seg[4 * MAX_N];
int n, q, a[MAX_N];
segment merg(segment a, segment b)
{
    segment x;
    int s[4];
    s[0] = a.m1;
    s[1] = a.m2;
    s[2] = b.m1;
    s[3] = b.m2;
    sort(s, s + 4);
    x.m1 = s[3];
    x.m2 = s[2];
    return x;
}
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id].m1 = a[b];
        seg[id].m2 = 0;
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = merg(seg[id * 2], seg[id * 2 + 1]);
}
void upd(int id, int b, int e, int p, int v)
{
    if (p < b || p >= e)
    {
        return;
    }
    if (e - b == 1)
    {
        seg[id].m1 = v;
        return;
    }
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, p, v);
    upd(id * 2 + 1, mid, e, p, v);
    seg[id] = merg(seg[id * 2], seg[id * 2 + 1]);
}
segment get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return {0, 0};
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    int mid = (b + e) / 2;
    return merg(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
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
    cin >> q;
    while (q--)
    {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'U')
        {
            upd(1, 1, n + 1, l, r);
        }
        else
        {
            segment x = get(1, 1, n + 1, l, r + 1);
            cout << x.m1 + x.m2 << "\n";
        }
    }
}
