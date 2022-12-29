/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;

int n, m, t[100 + 10][100 + 10], ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> t[i][j];
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if ((t[i][j] < t[i - 1][j] && t[i][j] < t[i + 1][j] && t[i][j] > t[i][j + 1] && t[i][j] > t[i][j - 1]) || (t[i][j] > t[i - 1][j] && t[i][j] > t[i + 1][j] && t[i][j] < t[i][j + 1] && t[i][j] < t[i][j - 1]))
            {
                ans++;
            }
        }
    }
    cout << ans;
}
