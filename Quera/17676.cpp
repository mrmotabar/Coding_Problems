/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 3e3 + 10, INF = 1e9;

int n, m, ans;
char c[MAX_N][MAX_N];
bool d[MAX_N][MAX_N];

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
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!d[i][j])
            {
                if (c[i][j] == '|')
                {
                    ans++;
                    int ind = j;
                    while (ind < m && c[i][ind] == '|')
                    {
                        d[i][ind] = 1;
                        ind++;
                    }
                }
                else
                {
                    ans++;
                    int ind = i;
                    while (ind < n && c[ind][j] == '-')
                    {
                        d[ind][j] = 1;
                        ind++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
