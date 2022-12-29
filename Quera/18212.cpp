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

string s;
long long light[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, ans, ind, dot = -1, tav;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    while (s[ind] != 'e')
    {
        if (s[ind] != '.')
        {
            ans += light[s[ind] - '0'];
        }
        else
        {
            dot = ind;
        }
        ind++;
    }
    tav = stoi(s.substr(ind + 1ll, s.size() - 1ll - ind));
    while (s[ind - 1] == '0' || s[ind - 1] == '.')
    {
        ans -= 6;
        ind--;
    }
    if (dot == -1)
    {
        dot = ind - 1ll;
    }
    if (tav > ind - dot - 1ll)
    {
        ans += (tav - (ind - dot - 1ll)) * light[0];
    }
    cout << ans << endl;
}
