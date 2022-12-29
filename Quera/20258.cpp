/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const ll MAX_N = 1e6 + 10, INF = 1e9;

int n, k;
pii lr[MAX_N];
multiset<int> st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> lr[i].F >> lr[i].S;
    }
    sort(lr, lr + n);
    int time = 0, ind = 0, cnt = 0;
    while (ind < n || st.size() > 0)
    {
        if (st.size() > 0 && (*st.begin()) < time)
        {
            cout << "NO" << endl;
            exit(0);
        }
        while (ind < n && lr[ind].F == time)
        {
            st.insert(lr[ind].S);
            ind++;
        }
        while (st.size() > 0 && cnt < k)
        {
            st.erase(st.begin());
            cnt++;
        }
        time++;
        cnt = 0;
    }
    cout << "YES" << endl;
}
