#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int MAX_N = 1e5 + 10, SQ = 333;
int n, q, a[MAX_N];
vector<pair<int, int>> quer[MAX_N];
long long dp[MAX_N], ans[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int s, k;
        cin >> s >> k;
        quer[k].pb({s, i});
    }
    for (int i = 1; i <= n; i++)
    {
        if (quer[i].size() > 0)
        {
            if (i < SQ)
            {
                for (int j = n - 1; j >= 0; j--)
                {
                    if (j + i < n)
                    {
                        dp[j] = a[j] + dp[j + i];
                    }
                    else
                    {
                        dp[j] = a[j];
                    }
                }
                for (auto u : quer[i])
                {
                    ans[u.S] = dp[u.F - 1];
                }
            }
            else
            {
                for (auto u : quer[i])
                {
                    int ind = u.F - 1;
                    while (ind < n)
                    {
                        ans[u.S] += a[ind];
                        ind += i;
                    }
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
}
