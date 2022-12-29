#include <bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
const ll MAX_N = 4e5 + 10, INF = 1e15;
ll n, m, xy[2][MAX_N];
struct node
{
    ll sum, maf, maz, mif, miz;
    bool tool;
} seg[2][4 * MAX_N];
void print(node p)
{
    cout << p.sum << " " << p.maf << " " << p.maz << " " << p.mif << " " << p.miz << " " << p.tool << "\n";
}
node mergee(node chap, node rast)
{
    node u;
    u.tool = (chap.tool + rast.tool) % 2;

    u.sum = rast.sum - chap.sum;
    if (!rast.tool)
    {
        u.sum += 2 * chap.sum;
    }

    u.maf = chap.maf;
    if (chap.tool)
    {
        u.maf = max(u.maf, rast.maz + chap.sum);
    }
    else
    {
        u.maf = max(u.maf, rast.maf - chap.sum);
    }

    u.maz = chap.maz;
    if (chap.tool)
    {
        u.maz = max(u.maz, rast.maf - chap.sum);
    }
    else
    {
        u.maz = max(u.maz, rast.maz + chap.sum);
    }

    u.mif = chap.mif;
    if (chap.tool)
    {
        u.mif = min(u.mif, rast.miz + chap.sum);
    }
    else
    {
        u.mif = min(u.mif, rast.mif - chap.sum);
    }

    u.miz = chap.miz;
    if (chap.tool)
    {
        u.miz = min(u.miz, rast.mif - chap.sum);
    }
    else
    {
        u.miz = min(u.miz, rast.miz + chap.sum);
    }
    return u;
}
void build(int id, int b, int e, int cor)
{
    if (e - b == 1)
    {
        seg[cor][id] = {2 * xy[cor][b], 2 * xy[cor][b], -INF, 2 * xy[cor][b], INF, 1};
        return;
    }
    ll mid = (e + b) / 2;
    build(id * 2, b, mid, cor);
    build(id * 2 + 1, mid, e, cor);
    seg[cor][id] = mergee(seg[cor][id * 2], seg[cor][id * 2 + 1]);
}
void upd(int id, int b, int e, int cor, int p, int val, bool boo)
{
    if (p >= e || p < b)
    {
        return;
    }
    if (e - b == 1)
    {
        if (boo)
        {
            seg[cor][id] = {2 * val, 2 * val, -INF, 2 * val, INF, 1};
        }
        else
        {
            seg[cor][id] = {2 * xy[cor][p] - val, val, 2 * xy[cor][p] - val, val, 2 * xy[cor][p] - val, 0};
        }
        return;
    }
    ll mid = (b + e) / 2;
    upd(id * 2, b, mid, cor, p, val, boo);
    upd(id * 2 + 1, mid, e, cor, p, val, boo);
    seg[cor][id] = mergee(seg[cor][id * 2], seg[cor][id * 2 + 1]);
}
node get(int id, int b, int e, int cor, int l, int r)
{
    if (l >= e || b >= r)
    {
        return {0, -INF, -INF, INF, INF, 0};
    }
    if (l <= b && e <= r)
    {
        return seg[cor][id];
    }
    ll mid = (b + e) / 2;
    node chap = get(id * 2, b, mid, cor, l, r), rast = get(id * 2 + 1, mid, e, cor, l, r);
    return mergee(chap, rast);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> xy[0][i] >> xy[1][i];
    }
    build(1, 1, n + 1, 0);
    build(1, 1, n + 1, 1);
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll noe, xx, yy, a, b;
        cin >> noe;
        if (noe == 1)
        {
            cin >> a >> xx >> yy;
            xy[0][a] = xx;
            xy[1][a] = yy;
            upd(1, 1, n + 1, 0, a, xx, 1);
            upd(1, 1, n + 1, 1, a, yy, 1);
        }
        else
        {
            cin >> xx >> yy >> a >> b;
            upd(1, 1, n + 1, 0, a, xx, 0);
            upd(1, 1, n + 1, 1, a, yy, 0);
            ll maax, miix, maay, miiy;
            node gx = get(1, 1, n + 1, 0, a, b + 1), gy = get(1, 1, n + 1, 1, a, b + 1);
            maax = max(gx.maf, gx.maz);
            miix = min(gx.mif, gx.miz);
            maay = max(gy.maf, gy.maz);
            miiy = min(gy.mif, gy.miz);
            upd(1, 1, n + 1, 0, a, xy[0][a], 1);
            upd(1, 1, n + 1, 1, a, xy[1][a], 1);
            cout << miix << " " << miiy << " " << maax << " " << maay << "\n";
        }
    }
}
