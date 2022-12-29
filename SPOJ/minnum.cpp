#include <iostream>
#include <cstdio>
using namespace std;
void kam(int a[], int c[]);
const int MAX_N = 5000;

int a[MAX_N];
int siza = 0;

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

void print()
{
	for (int i = siza - 1; i >= 0; --i)
		cout << a[i];
	cout << endl;
}

long long taghsim_int(long long b)
{
	int r = 0;
	for (int i = siza; i >= 0; i--)
	{
		r = (r * 10) + a[i];
		a[i] = r / b;
		r %= b;
	}
	r %= b;
	normalize(a, siza);
	return r;
}

void clear(int a[], int &siz)
{
	for (int i = 0; i < siz; ++i)
		a[i] = 0;
	siz = 0;
}

int main()
{
	bool c = true;
	for (int i = 0; c == true; i++)
	{
		string s1;
		cin >> s1;
		if (s1 == "-1")
		{
			c = false;
			break;
		}
		change(s1, a, siza);
		long long w = taghsim_int(9);
		if (w != 0)
		{
			a[0]++;
			normalize(a, siza);
		}
		print();
		clear(a, siza);
	}
	return 0;
}
