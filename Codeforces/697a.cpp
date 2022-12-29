#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int a, b, c;
	cin >> a >> b >> c;
	if ((c - 1 != a) && ((c - a) % b <= 1) && (c - a >= 0))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
