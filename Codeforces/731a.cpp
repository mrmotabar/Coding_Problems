#include <iostream>
#include <cstdio>
using namespace std;
int ghadr(int a, int b)
{
	if (a > b)
	{
		return a - b;
	}
	else
	{
		return b - a;
	}
}
int main()
{
	string s;
	cin >> s;
	char index = 'a';
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		ans += min(ghadr(int(s[i]), int(index)), 26 - ghadr(int(s[i]), int(index)));
		index = s[i];
	}
	cout << ans;
}
