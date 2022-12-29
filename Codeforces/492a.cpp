#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, a;
	cin >> n;
	for (int i = 0; (i + 1) * (i + 2) * (i + 3) / 6 <= n; i++)
	{
		a = i;
	}
	cout << a + 1;
}
