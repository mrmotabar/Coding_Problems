#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e6 + 10;
int n, w, h;
int dp[MAX_N], akh[MAX_N], andakh[MAX_N], par[MAX_N], ans, indans;
vector<pair<pair<int, int>, int>> env;
void pp(int i)
{
    if (par[i] == -1)
    {
        cout << env[i].S << " ";
        return;
    }
    pp(par[i]);
    cout << env[i].S << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a > w && b > h)
        {
            env.pb({{a, b}, i + 1});
        }
    }
    sort(env.begin(), env.end());
    memset(akh, 63, sizeof akh);
    memset(andakh, -1, sizeof andakh);
    akh[0] = 0;
    for (int i = 0; i < env.size(); i++)
    {
        int ind = lower_bound(akh, akh + env.size(), env[i].F.S) - akh - 1;
        while (env[andakh[ind]].F.F == env[i].F.F)
        {
            ind--;
        }
        dp[i] = ind + 1;
        par[i] = andakh[ind];
        if (env[i].F.S < akh[ind + 1])
        {
            akh[ind + 1] = env[i].F.S;
            andakh[ind + 1] = i;
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            indans = i;
        }
    }
    cout << ans << endl;
    if (ans > 0)
    {
        pp(indans);
    }
}
