#include <bits/stdc++.h>
#define ll long long
#define int long long
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e5 + 10, MOD = 1e9 + 7, MAX_L = 22;
int n, q;
vector<pair<int, int>> adj[MAX_N];
ll sz[MAX_N], dis[MAX_N], fazir[MAX_N], fazir2[MAX_N], fabal[MAX_N], fabal2[MAX_N], lca[MAX_N][MAX_L + 10], fasta1[MAX_N];
void down(int v, int par = 0, int w = 0)
{
    sz[v] = 1;
    dis[v] = dis[par] + 1;
    fasta1[v] = (fasta1[par] + w) % MOD;
    lca[v][0] = par;
    for (int i = 1; i < MAX_L; i++)
    {
        lca[v][i] = lca[lca[v][i - 1]][i - 1];
    }
    for (auto u : adj[v])
    {
        if (u.F != par)
        {
            down(u.F, v, u.S);
            sz[v] += sz[u.F];
            fazir[v] += (((u.S * sz[u.F]) % MOD) + fazir[u.F]) % MOD;
            fazir[v] %= MOD;

            fazir2[v] += ((((u.S * u.S % MOD * sz[u.F] % MOD) + fazir2[u.F]) % MOD) + (2 * u.S % MOD * fazir[u.F] % MOD)) % MOD;
            fazir2[v] %= MOD;
        }
    }
}
void up(int v, int par = 0, int w = 0)
{
    if (v != 1)
    {
        fabal[v] = ((fabal[par] + (w * (n - sz[v]) % MOD)) % MOD) + (((fazir[par] - (((w * sz[v] % MOD) + fazir[v]) % MOD)) + MOD) % MOD);
        fabal[v] %= MOD;

        fabal2[v] = w * w % MOD * (n - sz[v]) % MOD;
        fabal2[v] %= MOD;
        fabal2[v] += fabal2[par];
        fabal2[v] %= MOD;
        fabal2[v] += 2 * w % MOD * fabal[par] % MOD;
        fabal2[v] %= MOD;
        fabal2[v] += (((fazir2[par] - (((w * w % MOD * sz[v] % MOD) + fazir2[v]) % MOD + (2 * w % MOD * fazir[v] % MOD)) % MOD) % MOD) + MOD) % MOD;
        fabal2[v] %= MOD;
        fabal2[v] += 2 * w % MOD * ((((fazir[par] - (((w * sz[v] % MOD) + fazir[v]) % MOD)) % MOD) + MOD) % MOD);
        fabal2[v] %= MOD;
    }
    for (auto u : adj[v])
    {
        if (u.F != par)
        {
            up(u.F, v, u.S);
        }
    }
}
int get_par(int v, int k)
{
    for (int i = 0; i < MAX_L; i++)
    {
        if (k >> i & 1)
        {
            v = lca[v][i];
        }
    }
    return v;
}
int get_lca(int v, int u)
{
    if (dis[v] < dis[u])
    {
        swap(v, u);
    }
    v = get_par(v, dis[v] - dis[u]);
    if (u == v)
    {
        return v;
    }
    for (int i = MAX_L - 1; i >= 0; i--)
    {
        if (lca[v][i] != lca[u][i])
        {
            v = lca[v][i];
            u = lca[u][i];
        }
    }
    return lca[v][0];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dis[0] = -1;
    down(1);
    up(1);
    cin >> q;
    while (q--)
    {
        int u, v, lc;
        ll ans = 0, fas;
        cin >> u >> v;
        lc = get_lca(u, v);
        fas = (((fasta1[v] + fasta1[u]) % MOD) - (2 * fasta1[lc] % MOD) + MOD) % MOD;
        if (lc == v)
        {
            ans = (((fazir2[u] + fabal2[u]) % MOD) - (((((fas * fas % MOD) * (n - sz[v])) % MOD) + fabal2[v] + ((2 * fas % MOD * fabal[v]) % MOD)) % MOD) + MOD) % MOD;
        }
        else
        {
            ans = ((fas * fas % MOD * sz[v]) % MOD) + fazir2[v] + ((2 * fas % MOD * fazir[v]) % MOD);
        }
        ans %= MOD;
        ans *= 2;
        ans %= MOD;
        ans -= ((fazir2[u] + fabal2[u]) % MOD);
        ans %= MOD;
        cout << (ans + MOD) % MOD << "\n";
    }
}
