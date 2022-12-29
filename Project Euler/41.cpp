#include <bits/stdc++.h>
using namespace std;
int a[10], ans, t;
vector<int> aval;
bool mark[100000];
int make(int x)
{
    int ret = 0;
    for (int i = 0; i < x; i++)
    {
        ret *= 10;
        ret += a[i];
    }
    return ret;
}
int main()
{
    mark[1] = 1;
    for (long long i = 2; i < 100000; i++)
    {
        if (mark[i] == 0)
        {
            aval.push_back(i);
            for (long long j = i * i; j < 100000; j += i)
            {
                mark[j] = 1;
            }
        }
    }
    for (int i = 9; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            a[j] = j + 1;
        }
        do
        {
            int now = make(i);
            bool hast = 1;
            for (int u : aval)
            {
                if (u >= now)
                {
                    break;
                }
                if (now % u == 0)
                {
                    hast = 0;
                }
            }
            if (hast)
            {
                ans = max(ans, now);
            }
        } while (next_permutation(a, a + i));
    }
    cout << ans << endl;
}
