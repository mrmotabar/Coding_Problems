/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9, mod = 1e9 + 7;
string s, t;
ll ts[30], tt[30], ans, tans = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
    {
        ts[int(s[i]) - int('a')]++;
        tt[int(t[i]) - int('a')]++;
    }
    for (int i = 0; i < 26; i++)
    {
        ans += min(ts[i], tt[i]);
        ll u = 1;
        if (ts[i] < tt[i])
        {
            for (int j = tt[i]; j > tt[i] - ts[i]; j--)
            {
                u *= j;
                u %= mod;
            }
        }
        else if (ts[i] > tt[i])
        {
            for (int j = ts[i]; j > ts[i] - tt[i]; j--)
            {
                u *= j;
                u %= mod;
            }
        }
        else
        {
            for (int j = ts[i]; j > 0; j--)
            {
                u *= j;
                u %= mod;
            }
        }
        tans *= u;
        tans %= mod;
    }
    cout << ans << " " << tans << endl;
}
