#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define ll long long
using namespace std;
const int MAX_N = 5e6 + 10;
string s;
int n, k, f[MAX_N], st[MAX_N], fi[MAX_N], psh[MAX_N];
vector<int> adj[MAX_N], stfi;
void fillkmp()
{
    int cur = 0;
    adj[0].pb(1);
    adj[1].pb(0);
    for (int i = 1; i < n; i++)
    {
        while (cur && s[i] != s[cur])
        {
            cur = f[cur];
        }
        cur += (s[i] == s[cur]);
        f[i + 1] = cur;
        adj[i + 1].pb(cur);
        adj[cur].pb(i + 1);
    }
}
void dfs(int v, int par = -1)
{
    st[v] = stfi.size();
    stfi.pb(v);
    for (int u : adj[v])
    {
        if (u != par)
        {
            dfs(u, v);
        }
    }
    fi[v] = stfi.size();
}
int main()
{
    cin >> n >> k >> s;
    fillkmp();
    dfs(0);
    for (int i = 1; i * k <= s.size(); i++)
    {
        if (st[i * k - i] <= st[i * k] && fi[i * k] <= fi[i * k - i])
        {
            int ss = i * k, ee = min(n, i * (k + 1)) + 1;
            while (ee - ss > 1)
            {
                int mid = (ee + ss) / 2;
                int now = mid - (i * k);
                if (st[now] <= st[mid] && fi[now] >= fi[mid])
                {
                    ss = mid;
                }
                else
                {
                    ee = mid;
                }
            }
            psh[i * k] += 1;
            psh[min(ss, i * (k + 1)) + 1] -= 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        psh[i] += psh[i - 1];
        if (psh[i] > 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}
