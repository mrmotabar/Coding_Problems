/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
const ll MAX_N = 10 + 10, INF = 1e9;
class Bignum
{
public:
	static const short MAX_N = 380;
	static const short MOD = 10;
	short d[MAX_N], sizd = 0;
	Bignum(short x = 0)
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
	inline Bignum operator+=(const Bignum &b)
	{
		return *this = *this + b;
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
	inline Bignum operator*(const Bignum &b) const
	{
		Bignum ret = 0;
		ret.sizd = sizd + b.sizd;
		for (int i = 0; i <= sizd; i++)
		{
			for (int j = 0; j <= b.sizd; j++)
			{
				ret.d[i + j] += d[i] * b.d[j];
			}
		}
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
int n, k;
vector<int> w, b;
Bignum dpw[2 + 1][2500 + 10], dpb[2 + 1][2500 + 10], ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	w.pb(0);
	b.pb(0);
	for (int i = 1; i <= n; i += 2)
	{
		b.pb(i);
	}
	for (int i = 2; i <= n; i += 2)
	{
		w.pb(i);
	}
	if (n % 2 == 1)
	{
		for (int i = n - 2; i >= 1; i -= 2)
		{
			b.pb(i);
		}
		for (int i = 2; i <= n; i += 2)
		{
			w.pb(i);
		}
	}
	else
	{
		for (int i = 1; i <= n; i += 2)
		{
			b.pb(i);
		}
		for (int i = n - 2; i >= 2; i -= 2)
		{
			w.pb(i);
		}
	}
	sort(b.begin(), b.end());
	sort(w.begin(), w.end());
	dpw[0][0] = 1;
	dpb[0][0] = 1;
	for (int i = 1; i < w.size(); i++)
	{
		dpw[i % 2][0] = 1;
		for (int j = 1; j <= k; j++)
		{
			dpw[i % 2][j] = dpw[(i - 1) % 2][j] + (dpw[(i - 1) % 2][j - 1] * (w[i] - (j - 1)));
		}
	}
	for (int i = 1; i < b.size(); i++)
	{
		dpb[i % 2][0] = 1;
		for (int j = 1; j <= k; j++)
		{
			dpb[i % 2][j] = dpb[(i - 1) % 2][j] + (dpb[(i - 1) % 2][j - 1] * (b[i] - (j - 1)));
		}
	}
	for (int i = 0; i <= k; i++)
	{
		ans += dpw[(w.size() - 1) % 2][i] * dpb[(b.size() - 1) % 2][k - i];
	}
	ans.show();
}
