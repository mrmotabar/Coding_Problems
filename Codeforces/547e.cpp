#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e6 + 10;
int n, qq, nxt[26 + 10][MAX_N], f[MAX_N], q[MAX_N], l, r, ind[MAX_N], sz = 1;
int ans[MAX_N], st[MAX_N], fi[MAX_N], stfi, fen[MAX_N];
string s[MAX_N];
vector<int> adj[MAX_N];
vector<pair<pair<int, int>, int>> qu[MAX_N];
int add_tri(const string &s)
{
    int cur = 0;
    for (char x : s)
    {
        if (!nxt[x - 'a'][cur])
        {
            nxt[x - 'a'][cur] = sz++;
        }
        cur = nxt[x - 'a'][cur];
    }
    return cur;
}
void make_aho()
{
    for (int c = 0; c < 26; c++)
    {
        if (nxt[c][0])
        {
            q[r++] = nxt[c][0];
        }
    }
    while (l < r)
    {
        int v = q[l++];
        adj[f[v]].pb(v);
        for (int c = 0; c < 26; c++)
        {
            if (nxt[c][v])
            {
                f[nxt[c][v]] = nxt[c][f[v]];
                q[r++] = nxt[c][v];
            }
            else
            {
                nxt[c][v] = nxt[c][f[v]];
            }
        }
    }
}
void dfs(int v)
{
    stfi++;
    st[v] = stfi;
    for (int u : adj[v])
    {
        dfs(u);
    }
    fi[v] = stfi;
}
void add(int p, int val)
{
    p++;
    for (; p < MAX_N; p += p & (-p))
    {
        fen[p] += val;
    }
}
int get(int p)
{
    p++;
    int ret = 0;
    for (; p; p -= p & (-p))
    {
        ret += fen[p];
    }
    return ret;
}
void upd(int x)
{
    int cur = 0;
    for (char c : s[x])
    {
        cur = nxt[c - 'a'][cur];
        add(st[cur], 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> qq;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        ind[i] = add_tri(s[i]);
    }
    make_aho();
    dfs(0);
    for (int i = 1; i <= qq; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (l > 1)
        {
            qu[l - 1].pb({{i, -1}, k});
        }
        qu[r].pb({{i, +1}, k});
    }
    for (int i = 1; i <= n; i++)
    {
        upd(i);
        for (auto u : qu[i])
        {
            ans[u.F.F] += (u.F.S * (get(fi[ind[u.S]]) - get(st[ind[u.S]] - 1)));
        }
    }
    for (int i = 1; i <= qq; i++)
    {
        cout << ans[i] << "\n";
    }
}
