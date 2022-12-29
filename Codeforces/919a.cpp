#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n, m, ans = 1000000000;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;
        ans = min(ans, m * (a / b));
    }
    cout << fixed << setprecision(8) << ans;
}
