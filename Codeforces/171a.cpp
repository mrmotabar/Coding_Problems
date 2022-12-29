// april....
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a = 0, b = 0;
	string s;
	cin >> a >> s;
	int x = 1;
	for (int i = 0; i < s.size(); i++)
	{
		b += (int(s[i]) - int('0')) * x;
		x *= 10;
	}
	cout << a + b;
}
