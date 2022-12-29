#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e6 + 10;
int n, k, nxt[MAX_N][26], f[MAX_N], sz = 1, q[MAX_N], l, r, st[MAX_N], fi[MAX_N], ind[100000 + 10], stfi, fen[MAX_N];
string s[100000 + 10];
vector<int> adj[MAX_N];
bool mark[100000 + 10];
int add_tri(const string &s)
{
    int cur = 0;
    for (char c : s)
    {
        if (!nxt[cur][c - 'a'])
        {
            nxt[cur][c - 'a'] = sz++;
        }
        cur = nxt[cur][c - 'a'];
    }
    return cur;
}
void make_aho()
{
    for (int c = 0; c < 26; c++)
    {
        if (nxt[0][c])
        {
            q[r++] = nxt[0][c];
            adj[0].pb(nxt[0][c]);
        }
    }
    while (l < r)
    {
        int v = q[l++];
        for (int c = 0; c < 26; c++)
        {
            if (nxt[v][c])
            {
                f[nxt[v][c]] = nxt[f[v]][c];
                q[r++] = nxt[v][c];
                adj[nxt[f[v]][c]].pb(nxt[v][c]);
            }
            else
            {
                nxt[v][c] = nxt[f[v]][c];
            }
        }
    }
}
void dfs(int v)
{
    st[v] = stfi;
    stfi++;
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
void addbaz(int l, int r, int val)
{
    add(l, val);
    add(r, -val);
}
int st_in(const string &s)
{
    int ret = 0;
    for (int i = 1; i < s.size(); i++)
    {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ind[i] = add_tri(s[i]);
    }
    make_aho();
    dfs(0);
    for (int i = 0; i < n; i++)
    {
        addbaz(st[ind[i]], fi[ind[i]], 1);
        mark[i] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        string ss;
        int x;
        cin >> ss;
        if (ss[0] == '-')
        {
            x = st_in(ss);
            x--;
            if (mark[x])
            {
                addbaz(st[ind[x]], fi[ind[x]], -1);
                mark[x] = 0;
            }
        }
        else if (ss[0] == '+')
        {
            x = st_in(ss);
            x--;
            if (!mark[x])
            {
                addbaz(st[ind[x]], fi[ind[x]], 1);
                mark[x] = 1;
            }
        }
        else
        {
            int ans = 0, cur = 0;
            for (int i = 1; i < ss.size(); i++)
            {
                cur = nxt[cur][ss[i] - 'a'];
                ans += get(st[cur]);
            }
            cout << ans << "\n";
        }
    }
}
