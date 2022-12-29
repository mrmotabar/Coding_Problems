#include <bits/stdc++.h>
using namespace std;
int n, mm, a[5 + 1], b[2][10 + 1], m[2], maxt;
bool dp[2][10 + 1][31 + 1][7776 + 1];
pair<int, int> pr[2][10 + 1][31 + 1][7776 + 1];
vector<int> pp, hpp;
int tik(int i)
{
	int ret = 0;
	while (i > 0)
	{
		if (i % 2 == 0)
		{
			i /= 2;
		}
		else
		{
			ret++;
			while (i % 2 == 1)
			{
				i /= 2;
			}
		}
	}
	return ret;
}
bool chk(int x, int y)
{
	int ind = n;
	while (ind--)
	{
		if (x % 2 == 1 && y % 6 == 0)
		{
			return 0;
		}
		x /= 2;
		y /= 6;
	}

	return 1;
}
int cal(int x, int y, int z)
{
	int ret = 0;
	int ind = n;
	while (ind--)
	{
		if (x % 2 == 1 && y % 2 == 0)
		{
			ret *= 6;
			ret += ((z % 6) - 1);
		}
		else
		{
			ret *= 6;
			ret += (z % 6);
		}
		x /= 2;
		y /= 2;
		z /= 6;
	}
	int hel = 0;
	ind = n;
	while (ind--)
	{
		hel *= 6;
		hel += (ret % 6);
		ret /= 6;
	}
	return hel;
}
void solve(int ind)
{
	for (int i = 1; i < m[ind]; i++)
	{
		for (int j = 0; j < (1 << n); j++)
		{
			if (tik(j) == b[ind][i])
			{
				for (int k = 0; k < 7776; k++)
				{
					if (chk(j, k))
					{
						for (int l = 0; l < (1 << n); l++)
						{
							int x = cal(j, l, k);
							dp[ind][i][j][k] |= dp[ind][i - 1][l][x];
							if (dp[ind][i - 1][l][x])
							{
								pr[ind][i][j][k] = {l, x};
							}
						}
					}
				}
			}
		}
	}
}
void print()
{
	int ind = n;
	while (ind--)
	{
		for (int i = 0; i < pp.size(); i++)
		{
			if (pp[i] % 2 == 0)
			{
				cout << ".";
			}
			else
			{
				cout << "*";
			}
			pp[i] /= 2;
		}
		cout << endl;
	}
}
int kh5(int x)
{
	int bb[5] = {0, 0, 0, 0, 0};
	int ind = 0;
	while (ind < n)
	{
		bb[ind] = x % 2;
		x /= 2;
		ind++;
	}
	int ret = 0;
	;
	while (ind--)
	{
		ret *= 6;
		ret += bb[ind];
	}
	return ret;
}
int main()
{
	cin >> n >> mm;
	m[0] = (mm / 2) + (mm % 2);
	m[1] = mm / 2;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	maxt = 7776;
	for (int i = 0; i < m[0]; i++)
	{
		cin >> b[0][i];
	}
	for (int i = 0; i < m[1]; i++)
	{
		cin >> b[1][m[1] - i - 1];
	}
	for (int i = 0; i < (1 << n); i++)
	{
		if (tik(i) == b[0][0])
		{
			dp[0][0][i][kh5(i)] = 1;
		}
		if (m[1] > 0 && tik(i) == b[1][0])
		{
			dp[1][0][i][kh5(i)] = 1;
		}
	}
	solve(0);
	if (mm == 1)
	{
		int x = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			x *= 6;
			x += a[i];
		}
		for (int i = 0; i < (1 << n); i++)
		{
			if (dp[0][0][i][x])
			{
				pp.push_back(i);
				print();
				exit(0);
			}
		}
	}
	solve(1);
	for (int i = 0; i < (1 << n); i++)
	{
		if (tik(i) == b[0][m[0] - 1])
		{
			for (int j = 0; j < (1 << n); j++)
			{
				if (tik(j) == b[1][m[1] - 1])
				{
					for (int k = 0; k < maxt; k++)
					{
						if (dp[0][m[0] - 1][i][k])
						{
							int hel = 0;
							int ind = 0;
							int x = i, y = j, z = k;
							bool nist = 0;
							while (ind < n)
							{
								if (x % 2 == 1 && y % 2 == 1)
								{
									hel *= 6;
									hel += (a[ind] - (z % 6) + 1);
									if (a[ind] - (z % 6) + 1 > 5 || a[ind] - (z % 6) + 1 < 0)
									{
										nist = 1;
									}
								}
								else
								{
									hel *= 6;
									hel += (a[ind] - (z % 6));
									if (a[ind] - (z % 6) > 5 || a[ind] - (z % 6) < 0)
									{
										nist = 1;
									}
								}
								x /= 2;
								y /= 2;
								z /= 6;
								ind++;
							}
							if (nist)
							{
								continue;
							}
							int hel2 = 0;
							ind = n;
							while (ind--)
							{
								hel2 *= 6;
								hel2 += (hel % 6);
								hel /= 6;
							}
							hel = hel2;
							if (dp[1][m[1] - 1][j][hel])
							{
								x = m[0] - 1;
								y = i;
								z = k;
								while (x >= 0)
								{
									hpp.push_back(y);
									int yy = pr[0][x][y][z].first;
									z = pr[0][x][y][z].second;
									y = yy;
									x--;
								}
								for (int q = hpp.size() - 1; q >= 0; q--)
								{
									pp.push_back(hpp[q]);
								}
								x = m[1] - 1;
								y = j;
								z = hel;
								while (x >= 0)
								{
									pp.push_back(y);
									int yy = pr[1][x][y][z].first;
									z = pr[1][x][y][z].second;
									y = yy;
									x--;
								}
								print();
								exit(0);
							}
						}
					}
				}
			}
		}
	}
}
