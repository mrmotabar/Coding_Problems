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
int q[MAX_N], ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        q[i] = q[i + 1];
        if (s[i] == 'Q')
            q[i]++;
    }
    int cntq = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'Q')
            cntq++;
        if (s[i] == 'A')
            ans += (cntq * q[i]);
    }
    cout << ans << endl;
}
