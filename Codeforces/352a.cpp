#include <iostream>
#include <cstdio>
using namespace std;
int b[6];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		b[a]++;
	}
	if (b[0] == 0)
	{
		cout << -1;
		return 0;
	}
	if (b[5] < 9)
	{
		cout << 0;
		return 0;
	}
	bool c = false;
	while (b[5] >= 9)
	{
		cout << 555555555;
		b[5] -= 9;
		c = true;
	}
	if (c)
	{
		while (b[0] != 0)
		{
			cout << 0;
			b[0]--;
		}
		return 0;
	}
	if (c == false)
	{
		cout << 0;
	}
}
