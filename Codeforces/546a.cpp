#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, w, k;
	cin >> k >> n >> w;
	for (int i = 1; i <= w; i++)
	{
		n = n - i * k;
	}
	if (n < 0)
	{
		cout << n * (-1);
	}
	else
	{
		cout << 0;
	}
}
