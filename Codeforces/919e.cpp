#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e6 + 10;
ll a, b, p, ans;
ll x;
int pw(int x, int y, int m)
{
    if (!y)
        return 1;
    ll t = pw(x, y / 2, m);
    t = 1ll * t * t % m;
    if (y & 1)
        t = 1ll * t * x % m;
    return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> p >> x;
    for (int j = 0; j < p - 1; j++)
    {
        ll aj = pw(a, j, p), y = (1ll * pw(aj, p - 2, p) * b) % p, anow;
        if (x >= j)
        {
            anow = (x - j) / (p - 1);
            if (anow >= (j - y + p) % (p))
            {
                anow -= (j - y + p) % (p);
                anow /= p;
                anow++;
                ans += anow;
            }
        }
    }
    cout << ans << endl;
}
