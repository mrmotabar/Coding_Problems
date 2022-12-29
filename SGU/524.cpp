#include <bits/stdc++.h>
#define ld double
#define F first
#define S second
using namespace std;
const int MAX_N = 400 + 10;
int n, a[MAX_N];
pair<ld, pair<ld, int>> ans = {1e7, {-1, -1}};
double cal(double d, int fi)
{
    double ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret += abs(a[fi] + (i - fi) * d - a[i]);
    }
    return ret;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        ld lo = 0, hi = 1e6;
        for (int j = 0; j < 100; j++)
        {
            ld m1 = (2 * lo + hi) / 3, m2 = (lo + 2 * hi) / 3;
            if (cal(m1, i) < cal(m2, i))
            {
                hi = m2;
            }
            else
            {
                lo = m1;
            }
        }
        ans = min(ans, {cal(hi, i), {hi, i}});
    }
    cout << fixed << setprecision(10);
    cout << ans.F << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[ans.S.S] + (i - ans.S.S) * ans.S.F << " ";
    }
}
