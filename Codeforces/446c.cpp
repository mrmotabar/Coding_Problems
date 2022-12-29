/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 5e5 + 10, INF = 1e13, MOD = 1e9 + 9;
ll n, m, a[MAX_N];
ll fib[MAX_N], psf[MAX_N], psa[MAX_N];
ll seg[4 * MAX_N];
pair<ll, ll> lazy[4 * MAX_N];
void shift(int id, int b, int e)
{
    int mid = (b + e) / 2;

    lazy[id * 2].first += lazy[id].first;
    lazy[id * 2].first %= MOD;

    lazy[id * 2].second += lazy[id].second;
    lazy[id * 2].second %= MOD;

    lazy[id * 2 + 1].first += (fib[mid - b] * lazy[id].second) % MOD;
    lazy[id * 2 + 1].first %= MOD;
    lazy[id * 2 + 1].first += (fib[mid - b - 1] * lazy[id].first) % MOD;
    lazy[id * 2 + 1].first %= MOD;

    lazy[id * 2 + 1].second += (fib[mid - b + 1] * lazy[id].second) % MOD;
    lazy[id * 2 + 1].second %= MOD;
    lazy[id * 2 + 1].second += (fib[mid - b] * lazy[id].first) % MOD;
    lazy[id * 2 + 1].second %= MOD;

    seg[id * 2] += lazy[id].first;
    seg[id * 2] %= MOD;
    seg[id * 2] += lazy[id].second;
    seg[id * 2] %= MOD;
    seg[id * 2] += (lazy[id].second * (psf[mid - b - 1] - 1 + MOD)) % MOD;
    seg[id * 2] %= MOD;
    seg[id * 2] += (lazy[id].first * psf[mid - b - 2]) % MOD;
    seg[id * 2] %= MOD;

    ll x = ((fib[mid - b] * lazy[id].second) % MOD + (fib[mid - b - 1] * lazy[id].first) % MOD) % MOD;
    ll y = ((fib[mid - b + 1] * lazy[id].second) % MOD + (fib[mid - b] * lazy[id].first) % MOD) % MOD;
    seg[id * 2 + 1] += x;
    seg[id * 2 + 1] %= MOD;
    seg[id * 2 + 1] += y;
    seg[id * 2 + 1] %= MOD;
    seg[id * 2 + 1] += (y * (psf[e - mid - 1] - 1 + MOD)) % MOD;
    seg[id * 2 + 1] %= MOD;
    seg[id * 2 + 1] += (x * psf[e - mid - 2]) % MOD;
    seg[id * 2 + 1] %= MOD;

    lazy[id].first = 0;
    lazy[id].second = 0;
}
void upd(int id, int b, int e, int l, int r)
{
    if (l >= e || b >= r)
        return;
    if (l <= b && e <= r)
    {
        seg[id] += psf[e - l] - psf[b - l] + MOD;
        seg[id] %= MOD;
        lazy[id].first += fib[b - l + 1];
        lazy[id].second += fib[b - l + 2];
        lazy[id].first %= MOD;
        lazy[id].second %= MOD;
        return;
    }
    int mid = (e + b) / 2;
    shift(id, b, e);
    upd(id * 2, b, mid, l, r);
    upd(id * 2 + 1, mid, e, l, r);
    seg[id] = (seg[id * 2] + seg[id * 2 + 1]) % MOD;
}
ll get(int id, int b, int e, int l, int r)
{
    if (l >= e || b >= r)
        return 0;
    if (l <= b && e <= r)
        return seg[id];
    shift(id, b, e);
    int mid = (e + b) / 2;
    return (get(id * 2, b, mid, l, r) + get(id * 2 + 1, mid, e, l, r)) % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        psa[i] = psa[i - 1] + a[i];
        psa[i] %= MOD;
    }
    fib[1] = 1;
    fib[2] = 1;
    psf[1] = 1;
    psf[2] = 2;
    for (int i = 3; i < MAX_N; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= MOD;
        psf[i] = psf[i - 1] + fib[i];
        psf[i] %= MOD;
    }
    int t, l, r;
    while (m--)
    {
        cin >> t >> l >> r;
        if (t == 1)
        {
            upd(1, 1, n + 1, l, r + 1);
        }
        else
        {
            // get(1,1,n+1,l,r+1);
            cout << (psa[r] - psa[l - 1] + get(1, 1, n + 1, l, r + 1) + MOD) % MOD << endl;
        }
    }
}
