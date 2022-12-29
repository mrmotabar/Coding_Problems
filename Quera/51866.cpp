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

int n, k, c[MAX_N], ma = -INF, mi = INF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        mi = min(c[i], mi);
        ma = max(c[i], ma);
    }
    if (k >= 3)
    {
        cout << mi;
    }
    else if (k == 1)
    {
        cout << ma;
    }
    else
    {
        int x = -INF, y, ans = INF;
        for (int i = 0; i < n - 1; i++)
        {
            y = -INF;
            x = max(x, c[i]);
            for (int j = i + 1; j < n; j++)
            {
                y = max(y, c[j]);
            }
            ans = min(ans, min(x, y));
        }
        cout << ans;
    }
}
