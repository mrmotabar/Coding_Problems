#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	if (a % 2 == 1)
	{
		a++;
	}
	if (b - a <= 1)
	{
		cout << -1;
		return 0;
	}
	cout << a << " " << a + 1 << " " << a + 2;
}
