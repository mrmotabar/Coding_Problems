#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int MAX_N = 1e6 + 10;
string s;
vector<pair<char, int>> v[2], kom;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        int t = 1;
        while (i + 1 < s.size() && s[i] == s[i + 1])
        {
            t++;
            i++;
        }
        v[0].pb({s[i], t});
    }
    int temp = 0;
    while (v[temp % 2].size() > 1)
    {
        for (int i = 0; i < v[temp % 2].size(); i++)
        {
            auto u = v[temp % 2][i];
            if (u.S == 1 || (i > 0 && i < v[temp % 2].size() - 1 && u.S == 2))
            {
                continue;
            }
            if (i == 0 || i == v[temp % 2].size() - 1)
            {
                kom.pb({u.F, u.S - 1});
            }
            else
            {
                kom.pb({u.F, u.S - 2});
            }
        }
        for (int i = 0; i < kom.size(); i++)
        {
            int t = kom[i].S;
            while (i + 1 < kom.size() && kom[i].F == kom[i + 1].F)
            {
                t += kom[i + 1].S;
                i++;
            }
            v[(temp + 1) % 2].pb({kom[i].F, t});
        }
        kom.clear();
        v[temp % 2].clear();
        temp++;
    }
    cout << temp;
}
