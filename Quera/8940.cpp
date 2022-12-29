/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e5 + 10, INF = 1e9;
int n, p, q, ans;
map<pair<string, string>, int> has;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> q;
    while (n--)
    {
        string s, a, b;
        cin >> s;
        for (int i = 0; i < p; i++)
        {
            a += s[i];
        }
        for (int i = s.size() - q; i < s.size(); i++)
        {
            b += s[i];
        }
        if (has.count({a, b}) == 0)
        {
            ans++;
        }
        has[{a, b}] = 1;
    }
    cout << ans << endl;
}
