/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 2e5 + 10, INF = 1e9;

int n, v, u, t[MAX_N], ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> v >> u;
        t[v]++;
        t[u]++;
        ans = max(ans, t[v]);
        ans = max(ans, t[u]);
    }
    cout << ans;
}
