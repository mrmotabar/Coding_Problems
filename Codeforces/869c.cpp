#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long ans = 1, en[5000 + 10][5000 + 10], f[5000 + 10], sum, a, b, c;
int main()
{
    cin >> a >> b >> c;
    en[0][0] = 1;
    for (int i = 1; i <= 5000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            en[i][j] = (en[i - 1][j] + en[i - 1][j - 1]) % mod;
        }
    }
    f[0] = 1;
    for (int i = 1; i <= 5000; i++)
    {
        f[i] = (f[i - 1] * i) % mod;
    }
    for (int i = 0; i <= min(a, b); i++)
    {
        sum += (((en[a][i] * en[b][i]) % mod) * f[i]) % mod;
        sum %= mod;
    }
    ans *= sum;
    ans %= mod;
    sum = 0;
    for (int i = 0; i <= min(b, c); i++)
    {
        sum += (((en[b][i] * en[c][i]) % mod) * f[i]) % mod;
        sum %= mod;
    }
    ans *= sum;
    ans %= mod;
    sum = 0;
    for (int i = 0; i <= min(a, c); i++)
    {
        sum += (((en[a][i] * en[c][i]) % mod) * f[i]) % mod;
        sum %= mod;
    }
    ans *= sum;
    ans %= mod;
    cout << ans << endl;
}
