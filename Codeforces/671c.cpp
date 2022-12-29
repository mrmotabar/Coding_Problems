#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 2e5 + 10;
int n, a[MAX_N], ans;
pair<int, int> seg[4 * MAX_N];
pair<pair<int, int>, pair<int, int>> jay[MAX_N];
vector<int> magh[MAX_N];
void build(int id, int b, int e)
{
    if (e - b == 1)
    {
        seg[id] = {b, b};
        return 0;
    }
    int mid = (b + e) / 2;
    build(id * 2, b, mid);
    build(id * 2 + 1, mid, e);
    seg[id] = {seg[id * 2].F + seg[id * 2 + 1].F, min(seg[id * 2].S, seg[id * 2 + 1].S)};
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tir(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 2e5; i++)
    {
        for (int j = i; j <= 2e5; j += i)
        {
            magh[j].pb(i);
        }
    }
    memset(jay, 63, sizeof jay);
    for (int i = 1; i <= n; i++)
    {
        for (u : magh[a[i]])
        {
            jay[u].F.F = min(jay[u].F.F, i);
            jay[u].F.S = min(jay[u].F.S, i);
            jay[u].S.F = min(jay[u].S.F, i);
            jay[u].S.S = min(jay[u].S.F, i);
        }
    }
    build(1, 1, n + 1);
    for (int i = 2e5; i >= 1; i--)
    {

        ans += seg[1].F;
    }
    cout << ans << endl;
}
