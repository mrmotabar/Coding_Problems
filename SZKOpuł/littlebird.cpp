/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 1e6 + 10, INF = 1e9;
int n, h[MAX_N], dp[MAX_N], q, k;
deque<pii> deq;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    cin >> q;
    while (q--)
    {
        cin >> k;
        deq.clear();
        memset(dp, 0, sizeof dp);
        dp[n] = 0;
        deq.pb({dp[n], n});
        for (int i = n - 1; i >= 1; i--)
        {
            while (deq.size() && deq[0].second > i + k)
            {
                deq.pop_front();
            }
            if (h[i] > h[deq[0].second])
            {
                dp[i] = deq[0].first;
            }
            else
            {
                dp[i] = deq[0].first + 1;
            }
            while (deq.size() && dp[i] < deq[deq.size() - 1].first)
            {
                deq.pop_back();
            }
            while (deq.size() && dp[i] == deq[deq.size() - 1].first && h[i] < h[deq[deq.size() - 1].second])
            {
                deq.pop_back();
            }
            deq.pb({dp[i], i});
        }
        cout << dp[1] << endl;
    }
    // for(int i=1;i<=n;i++){
    //     cout<<dp[i]<<"  ";
    // }
    // cout<<endl;
}
