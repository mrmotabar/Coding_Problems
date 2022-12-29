#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const ll MAX_N = 1e6 + 10, B = 727, MOD = 1e9 + 7;
ll h[MAX_N], pw[MAX_N];
string s;
vector<int> bar;
ll get(int l, int r)
{
    return (h[r] - (1ll * h[l] * pw[r - l] % MOD) + MOD) % MOD;
}
int main()
{
    pw[0] = 1;
    for (int i = 1; i < MAX_N; i++)
    {
        pw[i] = pw[i - 1] * B % MOD;
    }
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        h[i + 1] = (1ll * h[i] * B + (s[i] - 'a' + 1)) % MOD;
    }
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (get(0, i + 1) == get(s.size() - (i + 1), s.size()))
        {
            bar.pb(i);
        }
    }
    if (bar.size() == 0)
    {
        cout << "Just a legend";
        return 0;
    }
    int now = bar[bar.size() - 1];
    for (int i = 1; i + now < s.size() - 1; i++)
    {
        if (get(0, now + 1) == get(i, i + now + 1))
        {
            for (int i = 0; i <= now; i++)
            {
                cout << s[i];
            }
            return 0;
        }
    }
    if (bar.size() == 1)
    {
        cout << "Just a legend";
    }
    else
    {
        for (int i = 0; i <= bar[bar.size() - 2]; i++)
        {
            cout << s[i];
        }
    }
}
