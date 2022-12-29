#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, q;
	cin >> n >> q;
	int l, r, k;
	l = n;
	r = 1;
	while (l != r)
	{
		q = (l + r - q);
		k = (l + r) / 2;
		if (q > k)
		{
			r = k + 1;
		}
		else
		{
			l = k;
		}
	}
	cout << q;
}
