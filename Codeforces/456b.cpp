#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int a = int(s[s.size() - 1]) - int('0') + (int(s[s.size() - 2]) - int('0')) * 10;
	if (a % 4 == 0)
	{
		cout << 4;
	}
	else
	{
		cout << 0;
	}
}
