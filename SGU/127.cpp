#include <iostream>
#include <cstdio>
using namespace std;
int a[10];
int main()
{
	int k, n;
	cin >> k >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		a[int(s[0]) - int('0')]++;
	}
	int t = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] > 0)
		{
			if (a[i] % k != 0)
			{
				t++;
				a[i] -= (a[i] % k);
			}
			t += (a[i] / k);
		}
	}
	cout << t + 2;
}
