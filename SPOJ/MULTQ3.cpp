#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
int n, q, lazy[4 * MAX_N];
struct segment
{
    int r0, r1, r2;
} seg[4 * MAX_N];
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id].r0 = 1;
        return;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id].r0 = e - b;
}
void add(int id)
{
    int x = seg[id].r2;
    seg[id].r2 = seg[id].r1;
    seg[id].r1 = seg[id].r0;
    seg[id].r0 = x;
    lazy[id]++;
}
void shift(int id, int b, int e)
{
    lazy[id] %= 3;
    if (lazy[id] == 0)
    {
    }
    else if (lazy[id] == 1)
    {
        add(id * 2);
        add(id * 2 + 1);
    }
    else
    {
        add(id * 2);
        add(id * 2);
        add(id * 2 + 1);
        add(id * 2 + 1);
    }
    lazy[id] = 0;
}
void upd(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return;
    }
    if (l <= b && e <= r)
    {
        add(id);
        return;
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, l, r);
    upd(id * 2 + 1, mid, e, l, r);
    seg[id].r0 = seg[id * 2].r0 + seg[id * 2 + 1].r0;
    seg[id].r1 = seg[id * 2].r1 + seg[id * 2 + 1].r1;
    seg[id].r2 = seg[id * 2].r2 + seg[id * 2 + 1].r2;
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
    {
        return 0;
    }
    if (l <= b && e <= r)
    {
        return seg[id].r0;
    }
    shift(id, b, e);
    int mid = (b + e) / 2;
    return get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    build(1, 0, n);
    while (q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        if (a == 0)
        {
            upd(1, 0, n, l, r + 1);
        }
        else
        {
            cout << get(1, 0, n, l, r + 1) << "\n";
        }
    }
}
