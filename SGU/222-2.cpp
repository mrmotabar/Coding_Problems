/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 251;
class Bignum
{
public:
	static const int MAX_N = 380;
	static const int MOD = 10;
	ll d[MAX_N], sizd = 0;
	Bignum(ll x = 0)
	{
		memset(d, 0, sizeof d);
		sizd = 0;
		d[sizd] = x;
		relax();
	}
	Bignum(const Bignum &b)
	{
		sizd = b.sizd;
		for (int i = 0; i <= sizd; i++)
		{
			d[i] = b.d[i];
		}
	}
	void relax()
	{
		d[sizd + 1] = 0;
		for (int i = 0; i <= sizd; i++)
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
		for (int i = 0; i <= max(b.sizd, sizd); i++)
		{
			ret.d[i] = d[i] + b.d[i];
		}
		ret.sizd = max(sizd, b.sizd);
		ret.relax();
		return ret;
	}
	inline Bignum operator+(const int &b) const
	{
		Bignum ret = 0, g = b;
		for (int i = 0; i <= max(g.sizd, sizd); i++)
		{
			ret.d[i] = d[i] + g.d[i];
		}
		ret.sizd = max(sizd, g.sizd);
		ret.relax();
		return ret;
	}
	inline Bignum operator*(const int &b) const
	{
		Bignum ret = 0, g = b;
		ret.sizd = sizd + g.sizd;
		for (int i = 0; i <= sizd; i++)
		{
			for (int j = 0; j <= g.sizd; j++)
			{
				ret.d[i + j] += d[i] * g.d[j];
			}
		}
		ret.relax();
		return ret;
	}
	void show()
	{
		for (int i = sizd; i >= 0; i--)
		{
			printf("%d", d[i]);
		}
	}
};
Bignum dp[2 + 1][MAX_N];
ll n, k, a[MAX_N];
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		a[i] = n;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i % 2][0] = 1;
		for (int j = 1; j <= k; j++)
		{
			dp[i % 2][j] = dp[(i - 1) % 2][j] + (dp[(i - 1) % 2][j - 1] * (a[i] - (j - 1)));
		}
	}
	dp[n % 2][k].show();
}
