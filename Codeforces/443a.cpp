#include <iostream>
#include <cstdio>
using namespace std;
int a[100];
int main()
{
	string s;
	getline(cin, s);
	for (int i = 1; i < (s.size() - 1); i += 3)
	{
		a[int(s[i]) - int('a')]++;
	}
	int t = 0;
	for (int i = 0; i < 100; i++)
	{
		if (a[i] != 0)
		{
			t++;
		}
	}
	cout << t;
}
