#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pushb push_back
#define popb pop_back
using namespace std;
const int MAX_N = 3e5 + 10;
int n, a[MAX_N], big[MAX_N], small[MAX_N], mi[MAX_N], ma[MAX_N], ans, lazy[4 * MAX_N];
vector<int> stkb, stks;
struct node
{
    int mi, tmi;
} seg[4 * MAX_N];
node merg(node l, node r)
{
    if (l.mi == r.mi)
    {
        return {l.mi, l.tmi + r.tmi};
    }
    return l.mi < r.mi ? l : r;
}
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id].mi = ma[b] - mi[b] - b + 1;
        seg[id].tmi = 1;
        return;
    }
    int mid = (e + b) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = merg(seg[id * 2], seg[id * 2 + 1]);
}
void upd(int id, int b, int e, int l, int r, int val)
{
    if (l >= e || b >= r)
    {
        return;
    }
    if (l <= b && e <= r)
    {
        lazy[id] += val;
        return;
    }
    int mid = (b + e) / 2;
    upd(id * 2, b, mid, l, r, val);
    upd(id * 2 + 1, mid, e, l, r, val);
    seg[id] = merg({seg[id * 2].mi + lazy[id * 2], seg[id * 2].tmi}, {seg[id * 2 + 1].mi + lazy[id * 2 + 1], seg[id * 2 + 1].tmi});
}
node get(int id, int b, int e, int l, int r)
{
    if (l >= e || b >= r)
    {
        return {1ll << 62, 0};
    }
    if (l <= b && e <= r)
    {
        return seg[id];
    }
    int mid = (b + e) / 2;
    node chap = get(id * 2, b, mid, l, r);
    node rast = get(id * 2 + 1, mid, e, l, r);
    node ret = merg({chap.mi + lazy[id * 2], chap.tmi}, {rast.mi + lazy[id * 2 + 1], rast.tmi});
    return ret;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int r, c;
        cin >> r >> c;
        a[r] = c;
    }
    mi[1] = a[1];
    ma[1] = a[1];
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            mi[i] = min(mi[i - 1], a[i]);
            ma[i] = max(ma[i - 1], a[i]);
        }
        while (stkb.size() && a[i] > a[stkb.back()])
        {
            big[stkb.back()] = i - 1;
            stkb.popb();
        }
        stkb.pushb(i);
        while (stks.size() && a[i] < a[stks.back()])
        {
            small[stks.back()] = i - 1;
            stks.popb();
        }
        stks.pushb(i);
    }
    while (stkb.size())
    {
        big[stkb.back()] = n;
        stkb.popb();
    }
    while (stks.size())
    {
        small[stks.back()] = n;
        stks.popb();
    }
    build(1, 1, n + 1);
    node x = get(1, 1, n + 1, 1, n + 1);
    if (x.mi == 0)
    {
        ans += x.tmi;
    }
    for (int i = 2; i <= n; i++)
    {
        upd(1, 1, n + 1, i, n + 1, 1);
        int ind = i;
        while (ind <= big[i - 1])
        {
            upd(1, 1, n + 1, ind, big[ind] + 1, a[ind] - a[i - 1]);
            ind = big[ind] + 1;
        }
        ind = i;
        while (ind <= small[i - 1])
        {
            upd(1, 1, n + 1, ind, small[ind] + 1, a[i - 1] - a[ind]);
            ind = small[ind] + 1;
        }
        x = get(1, 1, n + 1, i, n + 1);
        if (x.mi == 0)
        {
            ans += x.tmi;
        }
    }
    cout << ans;
}
