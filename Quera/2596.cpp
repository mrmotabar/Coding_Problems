/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e2 + 10, INF = 1e9;
int n, a[MAX_N];
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
    int ans = 0;
    for (int i = 1; i <= 1000; i++)
    {
        bool boo = true;
        for (int j = 0; j < n; j++)
        {
            if (i % a[j] != 0)
            {
                boo = false;
                break;
            }
        }
        if (boo)
            ans++;
    }
    cout << ans << endl;
}
