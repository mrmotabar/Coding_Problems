#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s1, s2;
map<string, int> mp;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        mp[s1]++;
        ans = max(mp[s1], ans);
    }
    cout << ans << endl;
}
