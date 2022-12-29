#include <bits/stdc++.h>
using namespace std;
string d;
int ans = 1;
string str(int x)
{
    string ret;
    while (x > 0)
    {
        ret += char((x % 10) + int('0'));
        x /= 10;
    }
    int n = ret.length();
    for (int i = 0; i < n / 2; i++)
    {
        swap(ret[i], ret[n - 1 - i]);
    }
    return ret;
}
int in(char c)
{
    return int(c) - int('0');
}
int main()
{
    for (int i = 1; i < 200000; i++)
    {
        d += str(i);
    }
    for (int i = 0; i <= 99999; i = (i * 10) + 9)
    {
        ans *= in(d[i]);
    }
    cout << ans;
}
