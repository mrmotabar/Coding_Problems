#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int MAX_N = 5e3 + 10;
int n, a[MAX_N], flag[MAX_N], ans[MAX_N], cnt[MAX_N][MAX_N], temp;
vector<int> vec;
int khalikon(int x)
{
    int ret = x;
    if (x < 0)
    {
        ret *= -1;
    }
    int sq = sqrt(ret);
    for (int i = 2; i <= sq; i++)
    {
        while (ret % (i * i) == 0)
        {
            ret /= (i * i);
        }
    }
    if (x < 0)
    {
        ret *= -1;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] != 0)
        {
            flag[i] = khalikon(a[i]);
        }
        vec.pb(flag[i]);
    }
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for (int i = 0; i < n; i++)
    {
        flag[i] = lower_bound(vec.begin(), vec.end(), flag[i]) - vec.begin();
    }
    for (int i = 0; i < n; i++)
    {
        temp = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] != 0)
            {
                cnt[i][flag[j]]++;
                if (cnt[i][flag[j]] == 1)
                {
                    temp++;
                }
            }
            if (temp > 0)
            {
                ans[temp]++;
            }
            else
            {
                ans[1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
}
