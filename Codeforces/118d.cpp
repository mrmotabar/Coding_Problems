#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 100000000;
int d[200][200][2];
int main()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    d[0][0][0] = 1;
    d[0][0][1] = 1;
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            for (int k = 1; k <= k1 && i - k >= 0; k++)
            {
                d[i][j][0] += d[i - k][j][1] % mod;
            }
            for (int k = 1; k <= k2 && j - k >= 0; k++)
            {
                d[i][j][1] += d[i][j - k][0] % mod;
            }
        }
    }
    cout << (d[n1][n2][0] + d[n1][n2][1]) % mod;
}
