#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int inch, foot;
	foot = n / 36;
	if ((n % 36 == 1 || n % 36 == 35) && n >= 35)
	{
		cout << foot + 1 << " " << 0;
		return 0;
	}
	n %= 36;
	inch = n / 3;
	if (n % 3 > 1)
	{
		inch++;
	}
	cout << foot << " " << inch;
}
