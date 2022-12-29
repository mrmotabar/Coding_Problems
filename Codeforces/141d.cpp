#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
typedef pair<ll, ll> pll;
const int MAX_N = 2e5 + 10000;
ll n, l;
ll x[MAX_N], d[MAX_N], t[MAX_N], p[MAX_N], dp[MAX_N];
pll plast[MAX_N];
vector<ll> com, ans;
vector<pair<pll, ll>> adj[MAX_N];
set<pll> st;
void pp(int v)
{
    if (plast[v].S > 0)
    {
        ans.pb(plast[v].S);
    }
    if (v == 0)
    {
        return;
    }
    pp(plast[v].F);
}
void dijk(int v)
{
    memset(dp, 127, sizeof dp);
    dp[v] = 0;
    st.insert({dp[v], v});
    while (st.size())
    {
        auto x = *st.begin();
        st.erase(st.begin());
        for (auto u : adj[x.S])
        {
            if (x.F + u.F.S < dp[u.F.F])
            {
                st.erase({dp[u.F.F], u.F.F});
                dp[u.F.F] = x.F + u.F.S;
                st.insert({dp[u.F.F], u.F.F});
                plast[u.F.F] = {x.S, u.S};
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    com.pb(0);
    com.pb(l);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> d[i] >> t[i] >> p[i];
        if (x[i] - p[i] >= 0 && t[i] < d[i])
        {
            com.pb(x[i] - p[i]);
            com.pb(x[i] + d[i]);
        }
    }
    sort(com.begin(), com.end());
    com.resize(unique(com.begin(), com.end()) - com.begin());
    for (int i = 0; i + 1 < com.size(); i++)
    {
        adj[i].pb({{i + 1, com[i + 1] - com[i]}, 0});
        adj[i + 1].pb({{i, com[i + 1] - com[i]}, 0});
    }
    for (int i = 0; i < n; i++)
    {
        if (x[i] - p[i] >= 0 && t[i] < d[i])
        {
            int ind1 = lower_bound(com.begin(), com.end(), x[i] - p[i]) - com.begin();
            int ind2 = lower_bound(com.begin(), com.end(), x[i] + d[i]) - com.begin();
            adj[ind1].pb({{ind2, t[i] + p[i]}, i + 1});
        }
    }
    dijk(0);
    pp(com.size() - 1);
    cout << dp[com.size() - 1] << endl;
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}
