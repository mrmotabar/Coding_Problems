#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int k, a[12];
	cin >> k;
	for (int i = 0; i < 12; i++)
	{
		cin >> a[i];
	}
	sort(a, a + 12);
	int sum = 0, t = 0;
	int i = 11;
	while (sum < k)
	{
		sum += a[i];
		t++;
		if (t == 12 && sum < k)
		{
			cout << -1;
			return 0;
		}
		i--;
	}
	cout << t;
}
