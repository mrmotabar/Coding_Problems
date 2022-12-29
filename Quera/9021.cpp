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
int n, a[MAX_N], b[MAX_N];
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            ans.pb(a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int u : ans)
    {
        cout << u << " ";
    }
}
