#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
typedef pair<int, int> pii;
const int MAX_N = 500 + 10;
int n, match[MAX_N], match2[MAX_N];
vector<pii> adj[MAX_N];
bool mark[MAX_N];
int mans[MAX_N];
bool dfs(int v, int m)
{
    mark[v] = 1;
    for (auto u : adj[v])
    {
        if (u.S <= m)
        {
            if (match2[u.F] == 0 || (mark[match2[u.F]] == 0 && dfs(match2[u.F], m)))
            {
                match[v] = u.F;
                match2[u.F] = v;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            adj[i].pb({j, a});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        mans[i] = i;
    }
    int s = -1 * 1e6, e = 1e6;
    while (s < e - 1)
    {
        int mid = (s + e) / 2;
        int an = 0;
        memset(match, 0, sizeof match);
        memset(match2, 0, sizeof match2);
        while (1)
        {
            bool finished = 1;
            memset(mark, 0, sizeof mark);
            for (int i = 1; i <= n; i++)
            {
                if (!mark[i] && match[i] == 0 && dfs(i, mid))
                {
                    an++;
                    finished = 0;
                }
            }
            if (finished)
            {
                break;
            }
        }
        if (an == n)
        {
            e = mid;
            for (int i = 1; i <= n; i++)
            {
                mans[i] = match[i];
            }
        }
        else
        {
            s = mid;
        }
    }
    cout << e << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "  " << mans[i] << endl;
    }
}
