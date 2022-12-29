#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
set<int> na;
int n, a[MAX_N], cnt[MAX_N], mark[MAX_N], ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            na.insert(i);
        }
        else if (cnt[i] == 1)
        {
            mark[i] = 0;
        }
        else
        {
            mark[i] = 1;
        }
    }
    ans = na.size();
    for (int i = 1; i <= n; i++)
    {
        if (mark[a[i]] == 0)
        {
            continue;
        }
        else if (mark[a[i]] == 2)
        {
            cnt[a[i]]--;
            if (cnt[a[i]] == 1)
            {
                mark[a[i]] = 0;
            }
            a[i] = *na.begin();
            na.erase(*na.begin());
        }
        else
        {
            if (*na.begin() < a[i])
            {
                cnt[a[i]]--;
                if (cnt[a[i]] == 1)
                {
                    mark[a[i]] = 0;
                }
                a[i] = *na.begin();
                na.erase(*na.begin());
            }
            else
            {
                mark[a[i]] = 2;
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}
