#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int t = 0;
	int n;
	string s1, s2;
	cin >> n;
	cin >> s1;
	for (int i = 0; i < n - 1; i++)
	{
		if (i % 2 == 0)
		{
			cin >> s2;
			if (s2[0] == s1[1])
			{
				t++;
			}
		}
		if (i % 2 == 1)
		{
			cin >> s1;
			if (s2[0] == s1[1])
			{
				t++;
			}
		}
	}
	cout << t + 1;
}
