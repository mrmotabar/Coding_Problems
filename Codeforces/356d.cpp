#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
const int MAX_N = 1e5;
int n, s, par[MAX_N];
pair<int, int> a[MAX_N], ans[MAX_N];
bitset<MAX_N> dp, kom;
bool mark[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].F;
        a[i].S = i;
    }
    sort(a + 1, a + n + 1);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        kom = dp;
        dp |= (dp << a[i].F);
        kom ^= dp;
        for (int j = kom._Find_first(); j <= s; j = kom._Find_next(j))
        {
            par[j] = i;
        }
    }
    if (a[n].F > s || dp[s - a[n].F] == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int x = s - a[n].F;
    while (x > 0)
    {
        mark[par[x]] = 1;
        x = x - a[par[x]].F;
    }
    int ind = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 1)
        {
            ans[a[i].S] = {a[i].F, 0};
            // cout<<a[i].F<<endl;
        }
        else
        {
            if (ind == 0)
            {
                ans[a[i].S] = {a[i].F, 0};
            }
            else
            {
                ans[a[i].S] = {a[i].F - a[ind].F, a[ind].S};
            }
            ind = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i].F << " ";
        if (ans[i].S == 0)
        {
            cout << ans[i].S << endl;
        }
        else
        {
            cout << 1 << " " << ans[i].S << endl;
        }
    }
}
