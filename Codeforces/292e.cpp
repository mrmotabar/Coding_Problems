/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m, a[MAX_N], b[MAX_N];
pair<int, int> seg[4 * MAX_N];
void upd(int id, int b, int e, int x, int y, int k, int ind)
{
    if (e <= y || y + k - 1 <= b)
        return;
    if (y <= b && e <= y + k - 1)
    {
        seg[id].first = b - y + x;
        seg[id].second = ind;
        return;
    }
    int mid = (e + b) / 2;
    upd(id * 2, b, mid, x, y, k, ind);
    upd(id * 2 + 1, mid, e, x, y, k, ind);
}
pair<int, int> get(int id, int b, int e, int x)
{
    if (x < b || x >= e)
    {
        return {0, 0};
    }
    if (e - b == 1)
    {
        return seg[id];
    }
    int mid = (e + b) / 2;
    pair<int, int> c;
    if (x < mid)
    {
        c = get(id * 2, b, mid, x);
    }
    else
    {
        c = get(id * 2 + 1, mid, e, x);
    }
    if (c.second > seg[id].second)
    {
        return c;
    }
    return {x - b + seg[id].first, seg[id].second};
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    int t, x, y, k, ind = 1;
    while (m--)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x >> y >> k;
            upd(1, 1, n + 1, x, y, k + 1, ind);
            ind++;
        }
        else
        {
            cin >> x;
            pair<int, int> ans = get(1, 1, n + 1, x);
            if (ans.second == 0)
            {
                cout << b[x] << endl;
            }
            else
            {
                cout << a[ans.first] << endl;
            }
        }
    }
}
