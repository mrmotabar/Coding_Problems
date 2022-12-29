#include <iostream>
#include <Cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	bool a = true;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if (m == 1)
		{
			a = false;
		}
	}
	if (a == true)
	{
		cout << 1;
	}
	else
	{
		cout << -1;
	}
}
