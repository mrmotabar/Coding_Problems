#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N = 1000 + 10;
int n, m, a[MAX_N][MAX_N], sat, gc[MAX_N], ans;
int32_t main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    sat = a[1][1];
    for (int i = 2; i <= m; i++)
    {
        sat = __gcd(sat, a[1][i]);
    }
    for (int i = 1; i <= m; i++)
    {
        gc[i] = a[1][i];
        for (int j = 2; j <= n; j++)
        {
            gc[i] = __gcd(gc[i], a[j][i]);
        }
    }
    for (int i = 1; i <= sqrt(sat); i++)
    {
        if (sat % i == 0)
        {
            bool hast = 1;
            for (int j = 1; j <= m; j++)
            {
                if (gc[j] % (a[1][j] / i) != 0)
                {
                    hast = 0;
                    break;
                }
            }
            if (hast)
            {
                ans++;
            }
        }
        if (i != (sat / i) && sat % (sat / i) == 0)
        {
            bool hast = 1;
            for (int j = 1; j <= m; j++)
            {
                if (gc[j] % (a[1][j] / (sat / i)) != 0)
                {
                    hast = 0;
                    break;
                }
            }
            if (hast)
            {
                ans++;
            }
        }
    }
    cout << ans;
}
