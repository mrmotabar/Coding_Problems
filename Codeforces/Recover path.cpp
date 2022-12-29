/*mohammadreza motabar*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m, k, sar, tah, ted;
bool bgoo[MAX_N];
vector<pair<pii, int>> adj[MAX_N];
vector<int> goo;
set<pii> s;
int dp[MAX_N], tegoo[MAX_N];
pii par[MAX_N];
void pt(int v)
{
    if (v == sar)
    {
        return;
    }
    pt(par[v].F);
    ted++;
}
void pp(int v)
{
    if (v == sar)
    {
        return;
    }
    pp(par[v].F);
    cout << par[v].S << "  ";
}
int dis(int v)
{
    memset(dp, 127, sizeof dp);
    dp[v] = 0;
    tegoo[v] = bgoo[v];
    int ret = v;
    s.insert({dp[v], v});
    while (s.size())
    {
        auto x = *s.begin();
        if (bgoo[x.S])
        {
            if (x.F > dp[ret])
            {
                ret = x.S;
            }
        }
        s.erase(s.begin());
        for (auto u : adj[x.S])
        {
            if (dp[x.S] + u.F.S < dp[u.F.F])
            {
                tegoo[u.F.F] = tegoo[x.S] + bgoo[u.F.F];
                s.erase({dp[u.F.F], u.F.F});
                dp[u.F.F] = dp[x.S] + u.F.S;
                s.insert({dp[u.F.F], u.F.F});
                par[u.F.F] = {x.S, u.S};
            }
            else if (dp[x.S] + u.F.S == dp[u.F.F] && tegoo[x.S] + bgoo[u.F.F] > tegoo[u.F.F])
            {
                tegoo[u.F.F] = tegoo[x.S] + bgoo[u.F.F];
                par[u.F.F] = {x.S, u.S};
            }
        }
    }
    return ret;
}
int main()
{
    freopen("recover.in", "r", stdin);
    freopen("recover.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({{b, c}, i});
        adj[b].pb({{a, c}, i});
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        goo.pb(a);
        bgoo[a] = 1;
    }
    sar = dis(goo[0]);
    tah = dis(sar);
    // cout<<sar<<"  "<<tah<<endl;
    pt(tah);
    cout << ted << endl;
    pp(tah);
}
