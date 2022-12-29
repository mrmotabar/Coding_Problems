/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 1e6 + 10, INF = 1e9;
int n, h[MAX_N];
int l[MAX_N], r[MAX_N], dp[MAX_N];
int seg[4 * MAX_N];
void upd(int id, int b, int e, int p)
{
    if (p < b || p >= e)
        return;
    if (e - b == 1)
    {
        seg[id] = r[b];
        return;
    }
    int mid = (e + b) / 2;
    upd(id * 2, b, mid, p);
    upd(id * 2 + 1, mid, e, p);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return 0;
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    return max(get(id * 2, b, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}
void upd2(int id, int b, int e, int p)
{
    if (p < b || p >= e)
        return;
    if (e - b == 1)
    {
        seg[id] = l[b];
        return;
    }
    int mid = (e + b) / 2;
    upd2(id * 2, b, mid, p);
    upd2(id * 2 + 1, mid, e, p);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int get2(int id, int b, int e, int l, int r)
{
    if (b >= r || l >= e)
        return INF;
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    return min(get2(id * 2, b, mid, l, r), get2(id * 2 + 1, mid, e, l, r));
}
void upddp(int id, int b, int e, int p, int val)
{
    if (b > p || e <= p)
        return;
    if (e - b == 1)
    {
        seg[id] = min(seg[id], val);
        return;
    }
    int mid = (b + e) / 2;
    upddp(id * 2, b, mid, p, val);
    upddp(id * 2 + 1, mid, e, p, val);
    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}
int getdp(int id, int b, int e, int l, int r)
{
    if (l >= e || b >= r)
        return INF;
    if (l <= b && e <= r)
        return seg[id];
    int mid = (b + e) / 2;
    return min(getdp(id * 2, b, mid, l, r), getdp(id * 2 + 1, mid, e, l, r));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    r[n] = min(n + h[n] - 1, n);
    upd(1, 1, n + 1, n);
    for (int i = n - 1; i >= 1; i--)
    {
        r[i] = max(min(h[i] + i - 1, n), get(1, 1, n + 1, i, min(n + 1, i + h[i])));
        upd(1, 1, n + 1, i);
    }
    memset(seg, 63, sizeof seg);
    l[1] = max(1 - h[1] + 1, 1);
    upd2(1, 1, n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        l[i] = min(max(i - h[i] + 1, 1), get2(1, 1, n + 1, max(1, i - h[i] + 1), i + 1));
        upd2(1, 1, n + 1, i);
    }
    memset(seg, 63, sizeof seg);
    upddp(1, 1, n + 1, l[n], 0);
    dp[n] = 1;
    upddp(1, 1, n + 1, l[n - 1], 1);
    for (int i = n - 1; i >= 1; i--)
    {
        dp[i] = min(1 + dp[r[i] + 1], getdp(1, 1, n + 1, 1, i + 1) + 1);
        upddp(1, 1, n + 1, l[i - 1], dp[i]);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    cout << dp[1] - 1 << endl;
}
