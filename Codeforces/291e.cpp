#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int MAX_N = 1e5 + 10;
int n, nxt[MAX_N][26 + 10], f[MAX_N], ans;
vector<pair<int, string>> adj[MAX_N];
string s;
void dfs(int v, int par = 0, int cur = 0)
{
    int tmp;
    string ss;
    for (auto u : adj[v])
    {
        if (u.F != par)
        {
            ss = u.S;
            tmp = cur;
            for (int i = 0; i < ss.size(); i++)
            {
                tmp = nxt[tmp][ss[i] - 'a'];
                if (tmp == s.size())
                {
                    ans++;
                }
            }
            dfs(u.F, v, tmp);
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int a;
        string b;
        cin >> a >> b;
        adj[i].pb({a, b});
        adj[a].pb({i, b});
    }
    cin >> s;
    int cur = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (cur && s[cur] != s[i])
        {
            cur = f[cur];
        }
        cur += (s[cur] == s[i]);
        f[i + 1] = cur;
    }
    for (int i = 0; i <= s.size(); i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (i != s.size() && s[i] - 'a' == c)
            {
                nxt[i][c] = i + 1;
            }
            else
            {
                nxt[i][c] = nxt[f[i]][c];
            }
        }
    }
    dfs(1);
    cout << ans;
}
