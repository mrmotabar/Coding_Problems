#include <iostream>
#include <cstring>
using namespace std;
main()
{
	int n, x = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		if (s[1] == '+')
		{
			x++;
		}
		if (s[1] == '-')
		{
			x--;
		}
	}
	cout << x << endl;
}
