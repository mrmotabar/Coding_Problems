#include <iostream>
#include <cstdio>
using namespace std;
int s[3];
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 1; i < 7; i++)
	{
		if (abs(i - a) > abs(i - b))
		{
			s[2]++;
		}
		else if (abs(i - a) == abs(i - b))
		{
			s[1]++;
		}
		else
		{
			s[0]++;
		}
	}
	cout << s[0] << " " << s[1] << " " << s[2];
}
