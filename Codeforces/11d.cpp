#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 19 + 1, MASK = (1 << MAX_N) + 10;
int n, m, adj[MAX_N];
long long dp[MAX_N][MASK], ans;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a] |= (1 << b);
        adj[b] |= (1 << a);
    }
    for (int i = 0; i < n; i++)
    {
        dp[i][1 << i] = 1;
    }
    for (int msk = 0; msk < (1 << n); msk++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((msk >> i) & 1)
            {
                int miin = __builtin_ctz(msk);
                if (i == miin)
                {
                    continue;
                }
                for (int k = 0; k < n; k++)
                {
                    if (!((adj[i] >> k) & 1))
                    {
                        continue;
                    }
                    else if (!((msk >> k) & 1))
                    {
                        continue;
                    }
                    else
                    {
                        dp[i][msk] += dp[k][msk ^ (1 << i)];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        long long sum = 0;
        for (int msk = 0; msk < (1 << n); msk++)
        {
            if (__builtin_popcount(msk) < 3)
            {
                continue;
            }
            else if (__builtin_ctz(msk) != i)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if (((adj[i] >> k) & 1) && ((msk >> k) & 1))
                {
                    sum += dp[k][msk];
                }
            }
        }
        ans += sum / 2;
    }
    cout << ans;
}
