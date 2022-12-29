/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 2e3 + 10, INF = 1e9;
int n, m, r[MAX_N * 100], c[MAX_N * 100], tr, tc;
bool ro[MAX_N], cl[MAX_N];
double dp[MAX_N][MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> r[i] >> c[i];
        if (!ro[r[i]])
        {
            ro[r[i]] = 1;
            tr++;
        }
        if (!cl[c[i]])
        {
            cl[c[i]] = 1;
            tc++;
        }
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (!(i == n && j == n))
            {
                if (i + 1 <= n && j + 1 <= n)
                {
                    dp[i][j] += ((dp[i + 1][j + 1] + 1) * (n - i) * (n - j));
                }
                if (i + 1 <= n)
                {
                    dp[i][j] += ((dp[i + 1][j] + 1) * (n - i) * j);
                }
                if (j + 1 <= n)
                {
                    dp[i][j] += ((dp[i][j + 1] + 1) * i * (n - j));
                }
                dp[i][j] += (i * j);
                dp[i][j] /= ((n * n) - (i * j));
            }
        }
    }
    cout << fixed << setprecision(11) << dp[tr][tc] << endl;
}
