#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;
int n, a[MAX_N], ans, gc;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        gc = __gcd(gc, a[i]);
        if (a[i] & 1)
        {
            t++;
        }
        else
        {
            if (t & 1)
            {
                ans += t / 2 + 2;
            }
            else
            {
                ans += t / 2;
            }
            t = 0;
        }
    }
    if (gc > 1)
    {
        cout << "YES\n";
        cout << 0;
        return 0;
    }
    if (t & 1)
    {
        ans += t / 2 + 2;
    }
    else
    {
        ans += t / 2;
    }
    cout << "YES\n";
    cout << ans;
}
