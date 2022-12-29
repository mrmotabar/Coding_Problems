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

int k, ans;
string s, temp;

int solve(char x, string y)
{
    for (int i = 0; i < y.size(); i++)
    {
        if (y[i] == x)
        {
            return min(i, (int)y.size() - i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k;
    cin >> s;
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        ans += solve(s[i], temp);
    }
    cout << ans;
}
