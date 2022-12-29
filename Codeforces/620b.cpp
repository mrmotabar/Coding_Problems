#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int s, e, sum = 0;
	cin >> s >> e;
	for (int i = s; i <= e; i++)
	{
		int u = i;
		while (u > 0)
		{
			sum += a[u % 10];
			u /= 10;
		}
	}
	cout << sum;
}
