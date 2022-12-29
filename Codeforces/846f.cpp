#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX_N = 1e6 + 10;
ll n, a[MAX_N], last[MAX_N], ans, k, san;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (last[a[i]] == 0)
        {
            k++;
        }
        san += (n - i + 1) - last[a[i]];
        ans += k * (n + 1) - san;
        last[a[i]] = (n - i + 1);
    }
    ans *= 2;
    ans -= n;
    cout << fixed << setprecision(7) << (ans * 1.0) / (n * n * 1.0) << endl;
}
