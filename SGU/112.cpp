#include <cstdio>
#include <iostream>
using namespace std;
const int MAX_N = 5000 + 20;

string s1, s2;

int t, o, y;

int a[MAX_N];
int siza = 0;

int b[MAX_N];
int sizb = 0;

int d[MAX_N];
int sizd = 0;

int c[MAX_N];
int sizc = 0;

int e[MAX_N];
int size = 0;

void change(int p, int a[], int &siz)
{
	if (p == 100)
	{
		siz = 3;
	}
	else if (p != 100 && p > 9)
	{
		siz = 2;
	}
	else
	{
		siz = 1;
	}
	a[0] = p % 10;
	a[1] = (p / 10) % 10;
	a[2] = (p / 100) % 10;
}
void normalize(int a[], int &siz)
{
	for (int i = siz - 1; i >= 0 && a[i] == 0; --i)
		--siz;
	if (siz == 0)
		++siz;

	for (int i = 0; i < siz; ++i)
	{
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
		if (a[siz] > 0)
			++siz;
	}
}
void mull(int n, int u)
{
	for (int i = 0; i < u - 1; i++)
	{
		for (int i = 0; i < siza; i++)
			a[i] *= n;
		normalize(a, siza);
	}
	normalize(a, siza);
}
void my_mull(int n, int u)
{
	for (int i = 0; i < u - 1; i++)
	{
		for (int i = 0; i < sizc; i++)
			c[i] *= n;
		normalize(c, sizc);
	}
	normalize(c, sizc);
}
int moghayese()
{
	int z = siza;
	if (sizc > z)
	{
		return 2;
	}
	if (sizc < z)
	{
		return 1;
	}
	if (sizc == z)
	{
		for (int i = z - 1; i >= 0; i--)
		{
			if (a[i] > c[i])
			{
				return 1;
			}
			else if (a[i] < c[i])
			{
				return 2;
			}
		}
		return 0;
	}
}
void kam(int a[], int c[])
{
	for (int i = 0; i < sizc; i++)
	{
		if (a[i] < c[i])
		{
			a[i] += 10;
			int z = i + 1;
			while (a[z] == 0 && z < siza)
			{
				a[z] = 9;
				z++;
			}
			a[z]--;
			a[i] -= c[i];
		}
		else
		{
			a[i] -= c[i];
		}
	}
	normalize(a, siza);
}
int main()
{
	cin >> t;
	cin >> o;
	change(t, a, siza);
	change(o, c, sizc);
	mull(t, o);
	my_mull(o, t);
	int w = moghayese();
	if (w == 2)
	{
		kam(c, a);
		cout << '-';
		for (int i = sizc - 1; i >= 0; i--)
		{
			cout << c[i];
		}
	}
	if (w == 1 || w == 0)
	{
		kam(a, c);
		for (int i = siza - 1; i >= 0; i--)
		{
			cout << a[i];
		}
	}
}
