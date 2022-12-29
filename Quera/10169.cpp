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
int n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    int ans = ((1 << (n + 1)) - 1) - ((1 << (s.size())) - 1);
    int x = 0;
    for (int i = 0; i < s.size(); i++)
    {
        x *= 2;
        if (s[i] == 'R')
        {
            x++;
        }
    }
    cout << ans - x << endl;
}
