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

int n, k, a[MAX_N], ans, sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (sum + a[i] > k)
        {
            ans++;
            sum = a[i];
        }
        else if (sum + a[i] == k)
        {
            ans++;
            sum = 0;
        }
        else
        {
            sum += a[i];
        }
    }
    if (sum != 0)
    {
        ans++;
    }
    cout << ans;
}
