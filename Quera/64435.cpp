/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e2 + 10, INF = 1e9;

int t, n, m;
char c[MAX_N][MAX_N];

int main()
{

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> c[i][j];
            }
        }
        for (int j = 0; j < m; j++)
        {
            bool flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (flag)
                {
                    ans++;
                }
                if (c[i][j] == '_')
                {
                    flag = 1;
                }
                else if (c[i][j] == '\\')
                {
                    flag = 1;
                    ans += 0.5;
                }
                else if (c[i][j] == '/')
                {
                    flag = 1;
                    ans += 0.5;
                }
            }
        }
        cout << setprecision(3) << fixed << ans << endl;
    }
}
