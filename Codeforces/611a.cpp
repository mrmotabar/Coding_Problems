#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	if (s2 == "week")
	{
		if (n != 5 && n != 6)
		{
			cout << 52;
			return 0;
		}
		else
		{
			cout << 53;
			return 0;
		}
	}
	else
	{
		if (n <= 29)
		{
			cout << 12;
			return 0;
		}
		else if (n == 30)
		{
			cout << 11;
			return 0;
		}
		else
		{
			cout << 7;
			return 0;
		}
	}
}
