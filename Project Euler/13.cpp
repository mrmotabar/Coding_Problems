#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;
string d[100];
int a[100000], siza = 0, c[100000], sizc = 0, b[100000], sizb = 0;
void change(string s, int a[], int &siz)
{
	for (int i = (int)(s.size() - 1); i >= 0; i--)
		a[siz++] = (int)(s[i] - '0');
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
void add()
{
	sizc = max(siza, sizb);
	for (int i = 0; i < max(siza, sizb); ++i)
		c[i] = a[i] + b[i];
	normalize(c, sizc);
}
void clear(int a[], int &siz)
{
	for (int i = 0; i < siz; ++i)
		a[i] = 0;
	siz = 1;
}
void cpy(int b[], int &sizb, int a[], int &siza)
{
	clear(a, siza);
	siza = sizb;
	for (int i = 0; i < sizb; ++i)
		a[i] = b[i];
}
int main()
{
	ifstream inf("13.txt");
	inf >> d[0];
	change(d[0], a, siza);
	for (int i = 1; i < 100; i++)
	{
		inf >> d[i];
		change(d[i], b, sizb);
		add();
		clear(b, sizb);
		sizb = 0;
		clear(a, siza);
		cpy(c, sizc, a, siza);
		normalize(c, sizc);
		normalize(a, siza);
		clear(c, sizc);
	}
	for (int i = siza - 1; i >= 0; i--)
	{
		cout << a[i];
	}
}
