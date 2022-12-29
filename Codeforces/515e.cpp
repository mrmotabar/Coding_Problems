/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
struct node
{
    ll ans, suf, pre, fas;
} seg[4 * MAX_N];
ll n, m, d[MAX_N], h[MAX_N];
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id].ans = 0;
        seg[id].suf = 2 * h[b];
        seg[id].pre = 2 * h[b];
        seg[id].fas = 0;
        return;
    }
    int mid = (e + b) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id].ans = max(max(seg[id * 2].ans, seg[id * 2 + 1].ans), seg[id * 2].pre + seg[id * 2 + 1].suf + d[mid - 1]);
    seg[id].suf = max(seg[id * 2].suf, seg[id * 2].fas + seg[id * 2 + 1].suf + d[mid - 1]);
    seg[id].pre = max(seg[id * 2 + 1].pre, seg[id * 2 + 1].fas + seg[id * 2].pre + d[mid - 1]);
    seg[id].fas = seg[id * 2].fas + d[mid - 1] + seg[id * 2 + 1].fas;
}
node get(int id, int b, int e, int l, int r)
{
    if (l >= e || b >= r)
        return {-INF, -INF, -INF, -INF};
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    node x = get(id * 2, b, mid, l, r);
    node y = get(id * 2 + 1, mid, e, l, r);
    ll a1 = max(max(x.ans, y.ans), x.pre + y.suf + d[mid - 1]);
    ll a2 = max(x.suf, x.fas + y.suf + d[mid - 1]);
    ll a3 = max(y.pre, y.fas + x.pre + d[mid - 1]);
    ll a4 = x.fas + d[mid - 1] + y.fas;
    return {a1, a2, a3, a4};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    build(1, 1, n + 1);
    int l, r;
    while (m--)
    {
        cin >> l >> r;
        if (l <= r)
        {
            if (l == 1 && r == n)
                cout << 0 << endl;
            else if (l == 1)
                cout << get(1, 1, n + 1, r + 1, n + 1).ans << endl;
            else if (r == n)
                cout << get(1, 1, n + 1, 1, l).ans << endl;
            else
            {
                node x = get(1, 1, n + 1, 1, l);
                node y = get(1, 1, n + 1, r + 1, n + 1);
                cout << max(max(x.ans, y.ans), y.pre + x.suf + d[n]) << endl;
            }
        }
        else
        {
            cout << get(1, 1, n + 1, r + 1, l).ans << endl;
        }
    }
}
