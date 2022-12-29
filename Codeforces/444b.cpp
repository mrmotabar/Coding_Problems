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
int n, d, a[MAX_N], b[MAX_N], c[MAX_N];
vector<int> yek;
ll x;
int where[MAX_N];
ll getNextX()
{
    x = (x * 37 + 10007) % 1000000007;
    return x;
}
void initAB()
{
    for (int i = 0; i < n; i = i + 1)
    {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; i = i + 1)
    {
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for (int i = 0; i < n; i = i + 1)
    {
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for (int i = 0; i < n; i = i + 1)
    {
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> x;
    initAB();
    for (int i = 0; i < n; i++)
    {
        where[a[i]] = i;
        if (b[i] == 1)
        {
            yek.pb(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j >= n - 266 && j >= 0; j--)
        {
            if (where[j] <= i && b[i - where[j]])
            {
                c[i] = j;
                break;
            }
        }
        if (c[i] == 0)
        {
            for (int k = 0; k < yek.size() && yek[k] <= i; k++)
            {
                c[i] = max(c[i], a[i - yek[k]]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << endl;
    }
}
