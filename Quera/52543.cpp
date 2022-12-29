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
    sort(a, a + n);
    int s = 0, e = n - 1, t = 0;
    while (s < e)
    {
        if (t % 2 == 0)
        {
            cout << a[e] << ' ';
            e--;
        }
        else
        {
            cout << a[s] << ' ';
            s++;
        }
        t++;
    }
    cout << a[s];
}
