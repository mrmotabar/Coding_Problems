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
string s, ans;
int t[26];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (int(s[i]) >= int('a'))
        {
            t[int(s[i]) - int('a')]++;
        }
        else
        {
            t[int(s[i]) - int('A')]++;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (int(s[i]) >= int('a'))
        {
            int ind = int(s[i]) - int('a');
            ans += char((((ind * t[ind]) + 1) % 26) + int('a'));
        }
        else
        {
            int ind = int(s[i]) - int('A');
            ans += char((((ind * t[ind]) + 1) % 26) + int('A'));
        }
    }
    cout << ans << endl;
}
