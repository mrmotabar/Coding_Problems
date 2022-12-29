#include <bits/stdc++.h>
using namespace std;
int ans;
bool ch(int x)
{
    int ind = 0, r[30];
    while (x > 0)
    {
        r[ind] = x % 10;
        x /= 10;
        ind++;
    }
    for (int i = 0; i < ind; i++)
    {
        if (r[i] != r[ind - 1 - i])
        {
            return 0;
        }
    }
    return 1;
}
bool ch2(int x)
{
    int ind = 0;
    for (int i = 0; i < 25; i++)
    {
        if (x >> i & 1)
        {
            ind = i;
        }
    }
    for (int i = 0; i <= ind; i++)
    {
        if ((x >> i & 1) ^ (x >> (ind - i) & 1))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    for (int i = 1; i < 1000000; i++)
    {
        if (ch(i) && ch2(i))
        {
            ans += i;
        }
    }
    cout << ans;
}
