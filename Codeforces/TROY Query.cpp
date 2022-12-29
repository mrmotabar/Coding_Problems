#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int MAX_N = 1e6 + 10;
int n, num[MAX_N];
vector<ll> com, com2;
vector<pair<pair<ll, ll>, pair<int, int>>> qu;
vector<int> adj[MAX_N];
bool mark[MAX_N];
void dfs(int v, int c)
{
    mark[v] = 1;
    num[v] = c;
    for (int u : adj[v])
    {
        if (!mark[u])
        {
            dfs(u, c);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        int c, d;
        cin >> a >> b >> c >> d;
        qu.pb({{a, b}, {c, d}});
        com.pb(a);
        com2.pb(b);
    }
    sort(com.begin(), com.end());
    com.resize(unique(com.begin(), com.end()) - com.begin());
    sort(com2.begin(), com2.end());
    com2.resize(unique(com2.begin(), com2.end()) - com2.begin());
    int s = 1, e = n + 1;
    while (1 < e - s)
    {
        int mid = (s + e) / 2, numi = 1;
        bool ans = true;
        for (int i = 0; i < MAX_N - 10; i++)
        {
            adj[i].clear();
        }
        memset(num, 0, sizeof num);
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < mid; i++)
        {
            int ind1 = lower_bound(com.begin(), com.end(), qu[i].F.F) - com.begin();
            int ind2 = lower_bound(com2.begin(), com2.end(), qu[i].F.S) - com2.begin();
            ind2 += com.size();
            if (qu[i].S.F == qu[i].S.S)
            {
                adj[2 * ind1].pb(2 * ind2);
                adj[2 * ind2].pb(2 * ind1);

                adj[2 * ind1 + 1].pb(2 * ind2 + 1);
                adj[2 * ind2 + 1].pb(2 * ind1 + 1);
            }
            else
            {
                adj[2 * ind1 + 1].pb(2 * ind2);
                adj[2 * ind2].pb(2 * ind1 + 1);

                adj[2 * ind1].pb(2 * ind2 + 1);
                adj[2 * ind2 + 1].pb(2 * ind1);
            }
        }
        for (int i = 0; i < 2 * (com.size() + com2.size()); i++)
        {
            if (!mark[i])
            {
                dfs(i, numi);
                numi++;
            }
        }
        for (int i = 0; i < com.size() + com2.size(); i++)
        {
            if (num[2 * i] == num[2 * i + 1] && num[2 * i] != 0)
            {
                ans = false;
            }
        }
        if (ans)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    for (int i = 0; i < s; i++)
    {
        cout << "Yes\n";
    }
    for (int i = 0; i < n - s; i++)
    {
        cout << "No\n";
    }
}
