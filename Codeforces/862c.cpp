#include <bits/stdc++.h>
using namespace std;
int x, n, xo = 0, t = (1 << 17);
int main()
{
    cin >> n >> x;
    if (n == 1)
    {
        cout << "YES\n"
             << x;
        return 0;
    }
    if (n == 2 && x == 0)
    {
        cout << "NO\n";
        return 0;
    }
    if (n == 2)
    {
        cout << "YES\n"
             << 0 << " " << x;
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n - 3; i++)
    {
        cout << i << "\n";
        xo = xo ^ i;
    }
    if (xo == x)
    {
        cout << 2 * t << " " << t << " " << ((2 * t) ^ t) << "\n";
    }
    else
    {
        cout << 0 << " " << 2 * t << " " << ((x ^ xo) ^ (2 * t)) << "\n";
    }
}
