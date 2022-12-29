#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e6 + 10;
bool aval[MAX_N];
ll ans;
bool ch(int x)
{
    if (x < 10)
    {
        return 0;
    }
    int y = x;
    while (y > 0)
    {
        if (!aval[y])
        {
            return 0;
        }
        y /= 10;
    }
    y = x;
    int ind = 0;
    for (int i = 10; 1; i *= 10)
    {
        if (y < i)
        {
            ind = i;
            break;
        }
    }
    ind /= 10;
    while (ind > 0)
    {
        if (!aval[y])
        {
            return 0;
        }
        y %= ind;
        ind /= 10;
    }
    return 1;
}
int main()
{
    memset(aval, 1, sizeof aval);
    aval[1] = 0;
    for (ll i = 2; i < MAX_N; i++)
    {
        if (aval[i])
        {
            if (ch(i))
            {
                cout << i << endl;
                ans += i;
            }
            for (ll j = i * i; j < MAX_N; j += i)
            {
                aval[j] = 0;
            }
        }
    }
    // cout<<ans<<endl;
}
