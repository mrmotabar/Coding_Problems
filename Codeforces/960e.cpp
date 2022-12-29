#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const ll MAX_N = 2e5 + 10, MOD = 1e9 + 7;
ll n, val[MAX_N], dpdown[2][MAX_N], dpup[2][MAX_N], sz[MAX_N], ans;
vector<int> adj[MAX_N];
void dfsdown(int v, int par = 0)
{
    sz[v] = 1;
    for (int u : adj[v])
    {
        if (u != par)
        {
            dfsdown(u, v);
            sz[v] += sz[u];
            dpdown[0][v] += dpdown[1][u];
            dpdown[0][v] %= MOD;
            dpdown[1][v] += dpdown[0][u];
            dpdown[1][v] %= MOD;
            ans += val[v] * dpdown[0][u] % MOD * (n - sz[u]) % MOD;
            // cout<<v<<" "<<val[v] * dpdown[0][u] % MOD * (n - sz[u]) % MOD<<endl;
            ans += MOD;
            ans %= MOD;
            ans -= val[v] * dpdown[1][u] % MOD * (n - sz[u]) % MOD;
            // cout<<v<<" "<<-1 * val[v] * dpdown[1][u] % MOD * (n - sz[u]) % MOD<<endl;
            ans += MOD;
            ans %= MOD;
        }
    }
    dpdown[1][v]++;
    dpdown[1][v] %= MOD;
    ans += val[v] * (n - sz[v] + 1) % MOD;
    // cout<<v<<" "<<val[v] * (n - sz[v] + 1) % MOD<<endl;
    ans += MOD;
    ans %= MOD;
}
void dfsup(int v, int par = 0)
{
    dpup[1][v]++;
    dpup[1][v] %= MOD;
    ans += val[v] * dpup[1][v] % MOD * sz[v] % MOD;
    ans += MOD;
    ans %= MOD;
    ans -= val[v] * dpup[0][v] % MOD * sz[v] % MOD;
    ans += MOD;
    ans %= MOD;
    for (int u : adj[v])
    {
        if (u != par)
        {
            dpup[0][u] = ((dpup[1][v] + (dpdown[1][v] - 1 + MOD) % MOD) % MOD - dpdown[0][u] + MOD) % MOD;
            dpup[1][u] = ((dpup[0][v] + dpdown[0][v]) % MOD - dpdown[1][u] + MOD) % MOD;
            dfsup(u, v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        ans -= val[i];
        ans += MOD;
        ans %= MOD;
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfsdown(1);
    dfsup(1);
    cout << ans;
}
