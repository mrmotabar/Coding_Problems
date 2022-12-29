#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int a1 = (int(s1[0]) - int('0')) * 10 + (int(s1[1]) - int('0'));
	int a2 = (int(s1[3]) - int('0')) * 10 + (int(s1[4]) - int('0'));
	int b1 = (int(s2[0]) - int('0')) * 10 + (int(s2[1]) - int('0'));
	int b2 = (int(s2[3]) - int('0')) * 10 + (int(s2[4]) - int('0'));
	a1 = a1 - b1;
	a2 = a2 - b2;
	if (a2 < 0)
	{
		a2 = a2 + 60;
		a1--;
	}
	if (a1 < 0)
	{
		a1 = a1 + 24;
	}
	if (a1 < 10)
	{
		cout << 0 << a1;
	}
	else
	{
		cout << a1;
	}
	cout << ":";
	if (a2 < 10)
	{
		cout << 0 << a2;
	}
	else
	{
		cout << a2;
	}
}
