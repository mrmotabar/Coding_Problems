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
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll ans = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int u = i;
        while (u % 10 == 0)
        {
            u /= 10;
        }
        ans *= u;
        while (ans % 10 == 0)
        {
            ans /= 10;
        }
        ans %= 10000000000;
    }
    cout << ans % 10 << endl;
}
