/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e12, mod = 1e9 + 7;
ll n, m, k, x, y;
ll a[2], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m >> x >> y;
    ll s = 0, e = mod, cnt;
    while (s < e - 1)
    {
        cnt = 0;
        int mid = (s + e) / 2;
        for (int i = 1; i <= n; i++)
        {
            if (i > 1)
                a[i % 2] = (x * a[(i - 1) % 2] + y) % mod;
            else
                a[1] = m;
            if (a[i % 2] <= mid)
            {
                cnt++;
            }
        }
        if (cnt <= k)
        {
            s = mid;
        }
        else
        {
            e = mid;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
            a[i % 2] = (x * a[(i - 1) % 2] + y) % mod;
        else
            a[1] = m;
        if (a[i % 2] < s && a[i % 2] > ans)
        {
            ans = a[i % 2];
        }
    }
    cout << ans << endl;
}
