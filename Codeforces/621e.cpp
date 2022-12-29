#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX_N = 50000 + 10, MOD = 1e9 + 7;
int n, b, k, x, a[MAX_N];
struct mat
{
    int a[110][110];
    mat(int y = 0)
    {
        memset(a, 0, sizeof a);
        for (int i = 0; i < 110; i++)
        {
            a[i][i] = y;
        }
    }
    int *operator[](int y)
    {
        return a[y];
    }
};
mat operator*(mat &A, mat &B)
{
    mat ret;
    for (int i = 0; i < 110; i++)
    {
        for (int j = 0; j < 110; j++)
        {
            for (int y = 0; y < 110; y++)
            {
                ret[i][j] += (A[i][y] * B[y][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}
mat pw(mat A, int b)
{
    mat ret(1);
    while (b)
    {
        if (b & 1)
        {
            ret = ret * A;
        }
        A = A * A;
        b >>= 1;
    }
    return ret;
}
mat adj;
int32_t main()
{
    cin >> n >> b >> k >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][((i * 10) + a[j]) % x]++;
        }
    }
    adj = pw(adj, b);
    cout << adj[0][k] << endl;
}
