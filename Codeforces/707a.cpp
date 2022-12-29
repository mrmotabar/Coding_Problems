#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	char a;
	bool c = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			if (a != 'B' && a != 'W' && a != 'G')
			{
				c = true;
			}
		}
	}
	if (c == true)
	{
		cout << "#Color";
	}
	else if (c == false)
	{
		cout << "#Black&White";
	}
}
