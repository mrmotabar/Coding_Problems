#include <iostream>
#include <cstdio>
using namespace std;
const long mod = 1000000007;
int d[100000], sum[100000];
int main()
{
    int t, k;
    cin >> t >> k;
    for (int i = 0; i < k; i++)
    {
        d[i] = 1;
    }
    for (int i = k; i <= 100001; i++)
    {
        d[i] = (d[i - 1] + d[i - k]) % mod;
    }
    for (int i = 1; i <= 100001; i++)
    {
        sum[i] = (sum[i - 1] + d[i]) % mod;
    }
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (sum[b] - sum[a - 1] + mod) % mod << endl;
    }
}
