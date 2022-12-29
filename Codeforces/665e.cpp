#include <bits/stdc++.h>

#define pb push_back
#define pf push_front

#define F first
#define S second

#define IOS ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;
typedef long long ll;
typedef long double ld;

// cout<<fixed<<setprecision(x)<<d;
//  107,109, 211,223, 307, 401,409, 503,509, 601,607, 701,709, 809, 907, 1009

const int MAX_N = 1e6 + 100, LOG = 23;
const int mod = 1e9 + 7, MOD = 1e9 + 9;
const ll inf = 1e9, INF = 1e18, super_inf = ~0ull / 4;

int n, k, a[MAX_N];
int sz = 1, trie[MAX_N * 40][2], cnt[MAX_N * 40];
ll ans;

void add(int x)
{
    int cur = 0;
    for (int i = 31; i >= 0; i--)
    {
        cnt[cur]++;
        bool x2 = (x >> i) & 1;
        if (trie[cur][x2] == 0)
        {
            trie[cur][x2] = sz++;
        }
        cur = trie[cur][x2];
    }
    cnt[cur]++;
}

int get(int x)
{
    int cur = 0, ret = 0;
    bool f = 1;
    for (int i = 31; i >= 0; i--)
    {
        bool x2 = (x >> i) & 1, k2 = (k >> i) & 1;
        if (k2 == 0 && trie[cur][!x2] != 0)
        {
            ret += cnt[trie[cur][!x2]];
        }
        if (trie[cur][x2 ^ k2] == 0)
        {
            f = 0;
            break;
        }
        else
        {
            cur = trie[cur][x2 ^ k2];
        }
    }
    if (f)
    {
        ret += cnt[cur];
    }
    return ret;
}

int main()
{
    cin >> n >> k;
    add(0);
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        temp ^= a[i];
        ans += get(temp);
        add(temp);
    }
    cout << ans << endl;
}
