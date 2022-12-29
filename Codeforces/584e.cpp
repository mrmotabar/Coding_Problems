#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
typedef pair<int, int> pii;
const int MAX_N = 2000 + 1;
int n, a[MAX_N], b[MAX_N], ans, jayb[MAX_N], jaya[MAX_N];
vector<pii> jav;
set<int> agh, jol;
int main()
{
    ;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        jaya[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
        jayb[b[i]] = i;
        ans += abs(jaya[b[i]] - i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (jayb[a[i]] < i)
        {
            agh.insert(i);
        }
        else if (jayb[a[i]] != i)
        {
            jol.insert(i);
        }
    }
    while (agh.size())
    {
        int r = *agh.begin();
        agh.erase(agh.begin());
        auto ind = jol.lower_bound(r);
        ind--;
        jol.erase(ind);
        int j = *ind;
        jav.pb({r, j});
        if (jayb[a[r]] != j)
        {
            agh.insert(j);
        }
        if (jayb[a[j]] != r)
        {
            jol.insert(r);
        }
        swap(a[r], a[j]);
    }
    printf("%d\n", ans / 2);
    printf("%d\n", jav.size());
    for (pii u : jav)
    {
        cout << u.F << " " << u.S << "\n";
    }
}
