/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, m, k;
int x[MAX_N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i <= m; i++)
    {
        cin >> x[i];
    }
    int ans = 0, a = 0;
    for (int i = 0; i < m; i++)
    {
        if (__builtin_popcount(x[i] ^ x[m]) <= k)
        {
            ans++;
        }
    }
    cout << ans;
}
