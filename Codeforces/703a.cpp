#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int x, y;
	int a1 = 0, a2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if (x > y)
		{
			a1++;
		}
		if (y > x)
		{
			a2++;
		}
	}
	if (a1 > a2)
	{
		cout << "Mishka";
	}
	else if (a1 == a2)
	{
		cout << "Friendship is magic!^^";
	}
	else
	{
		cout << "Chris";
	}
}
