#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a, b, c;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		c += a[i];
	}
	if (c == b)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
