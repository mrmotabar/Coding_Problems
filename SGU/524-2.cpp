#include <bits/stdc++.h>
#define ld double
#define F first
#define S second
using namespace std;
const int MAX_N = 400 + 10;
int a[MAX_N], n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<ld, pair<ld, int>> ans = {1e7, {-1, -1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ld d = (a[j] - a[i]) / ld(j - i), sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += abs(a[i] + (k - i) * d - a[k]);
            }
            ans = min(ans, {sum, {d, i}});
        }
    }
    cout << fixed << setprecision(10);
    cout << ans.F << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[ans.S.S] + (i - ans.S.S) * ans.S.F << " ";
    }
}
