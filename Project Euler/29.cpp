#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int a[10000 + 10][100 + 10], ind;
vector<int> amel[100 + 10];
bool ans[10000 + 10];
void por(int id, int x, int y)
{
    for (int i = 0; i < amel[x].size(); i++)
    {
        int k = 0, v = x;
        while (v % amel[x][i] == 0)
        {
            v /= amel[x][i];
            k++;
        }
        a[id][amel[x][i]] = k * y;
    }
}
int main()
{
    for (int i = 2; i <= 100; i++)
    {
        if (amel[i].size() == 0)
        {
            amel[i].pb(i);
            for (int j = i + i; j <= 100; j += i)
            {
                amel[j].pb(i);
            }
        }
    }
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 2; j <= 100; j++)
        {
            por(ind, i, j);
            ind++;
        }
    }
    memset(ans, 1, sizeof ans);
    for (int i = 0; i < 9801; i++)
    {
        for (int j = i + 1; j < 9801; j++)
        {
            bool b = 1;
            for (int k = 0; k < 100; k++)
            {
                if (a[i][k] != a[j][k])
                {
                    b = 0;
                    break;
                }
            }
            if (b)
            {
                ans[j] = 0;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < 9801; i++)
    {
        if (ans[i])
        {
            ret++;
        }
    }
    cout << ret;
}
