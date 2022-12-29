#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
using namespace std;
const int MAX_N = 100 + 10;
string s1, s2, virus;
int dp[MAX_N][MAX_N][MAX_N], f[MAX_N], nxt[MAX_N][26 + 10], n, m;
pair<pair<int, int>, int> par[MAX_N][MAX_N][MAX_N];
void pp(int x, int y, int z)
{
    if (x >= n || y >= m)
    {
        return;
    }
    if (par[x][y][z].F.F == x + 1 && par[x][y][z].F.S == y + 1 && par[x][y][z].S == nxt[z][s1[x] - 'A'])
    {
        cout << s1[x];
    }
    pp(par[x][y][z].F.F, par[x][y][z].F.S, par[x][y][z].S);
}
int main()
{
    cin >> s1 >> s2 >> virus;
    int cur = 0;
    n = s1.size();
    m = s2.size();
    for (int i = 1; i < virus.size(); i++)
    {
        while (cur && virus[cur] != virus[i])
        {
            cur = f[cur];
        }
        cur += (virus[cur] == virus[i]);
        f[i + 1] = cur;
    }
    for (int i = 0; i <= virus.size(); i++)
    {
        for (int c = 0; c < 26; c++)
        {
            if (i != n && virus[i] - 'A' == c)
            {
                nxt[i][c] = i + 1;
            }
            else
            {
                nxt[i][c] = nxt[f[i]][c];
            }
        }
    }
    for (int i = n - 1; ~i; i--)
    {
        for (int j = m - 1; ~j; j--)
        {
            for (int k = 0; k < virus.size(); k++)
            {
                dp[i][j][k] = dp[i + 1][j][k];
                par[i][j][k] = {{i + 1, j}, k};
                if (dp[i][j][k] < dp[i][j + 1][k])
                {
                    dp[i][j][k] = dp[i][j + 1][k];
                    par[i][j][k] = {{i, j + 1}, k};
                }
                if (s1[i] == s2[j] && dp[i][j][k] < dp[i + 1][j + 1][nxt[k][s1[i] - 'A']] + 1 && nxt[k][s1[i] - 'A'] < virus.size())
                {
                    dp[i][j][k] = dp[i + 1][j + 1][nxt[k][s1[i] - 'A']] + 1;
                    par[i][j][k] = {{i + 1, j + 1}, nxt[k][s1[i] - 'A']};
                }
            }
        }
    }
    if (dp[0][0][0] == 0)
    {
        cout << 0;
        return 0;
    }
    pp(0, 0, 0);
}
