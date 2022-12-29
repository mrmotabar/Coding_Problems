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
ll n, m, rr, cc;
bool r[MAX_N], c[MAX_N];
int main()
{
    scanf("%d %d", &n, &m);
    rr = n;
    cc = n;
    int a, b;
    while (m--)
    {
        scanf("%d %d", &a, &b);
        if (r[a] == 0)
        {
            rr--;
        }
        if (c[b] == 0)
        {
            cc--;
        }
        r[a] = 1;
        c[b] = 1;
        printf("%lld\n", rr * cc);
    }
}
