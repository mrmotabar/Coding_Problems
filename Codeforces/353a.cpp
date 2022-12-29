#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];
int b[1000000];
int main()
{
	int n, suma = 0, sumb = 0, t = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		suma += a[i];
		sumb += b[i];
		if (a[i] % 2 != b[i] % 2)
		{
			t++;
		}
	}
	if (suma % 2 == 0 && sumb % 2 == 0)
	{
		cout << 0;
		return 0;
	}
	else if (t % 2 == 0 && t > 0)
	{
		cout << 1;
	}
	else
	{
		cout << -1;
	}
}
