/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const short MAX_N = 260;
class Bignum
{
public:
	static const short MAX_N = 499 + 10;
	static const short MOD = 10;
	short d[MAX_N], sizd = 0;
	inline Bignum(ll x = 0)
	{
		memset(d, 0, sizeof d);
		sizd = 0;
		d[sizd] = x;
		relax();
	}
	inline Bignum(const Bignum &b)
	{
		sizd = b.sizd;
		for (short i = 0; i <= sizd; i++)
		{
			d[i] = b.d[i];
		}
	}
	inline void relax()
	{
		for (short i = 0; i <= sizd; i++)
		{
			d[i + 1] += d[i] / MOD;
			d[i] %= MOD;
			if (d[sizd + 1] > 0)
			{
				sizd++;
			}
		}
		while (sizd && !d[sizd])
		{
			sizd--;
		}
	}
	inline Bignum operator+(const Bignum &b) const
	{
		Bignum ret = 0;
		for (short i = 0; i <= max(b.sizd, sizd); i++)
		{
			ret.d[i] = d[i] + b.d[i];
		}
		ret.sizd = max(sizd, b.sizd);
		ret.relax();
		return ret;
	}
	inline Bignum operator+(const short &b) const
	{
		Bignum ret = 0, g = b;
		for (short i = 0; i <= max(g.sizd, sizd); i++)
		{
			ret.d[i] = d[i] + g.d[i];
		}
		ret.sizd = max(sizd, g.sizd);
		ret.relax();
		return ret;
	}
	inline Bignum operator*(const short &b) const
	{
		Bignum ret = 0, g = b;
		ret.sizd = sizd + g.sizd;
		for (short i = 0; i <= sizd; i++)
		{
			for (short j = 0; j <= g.sizd; j++)
			{
				ret.d[i + j] += d[i] * g.d[j];
			}
		}
		ret.relax();
		return ret;
	}
	inline void show()
	{
		for (short i = sizd; i >= 0; i--)
		{
			cout << d[i];
		}
	}
};
Bignum dp[10][MAX_N];
short n, k, a[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (short i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (short i = 1; i <= n; i++)
	{
		dp[i % 2][0] = 1;
		for (short j = 1; j <= k; j++)
		{
			dp[i % 2][j] = dp[(i - 1) % 2][j] + (dp[(i - 1) % 2][j - 1] * (a[i] - (j - 1)));
		}
	}
	dp[n % 2][k].show();
}
