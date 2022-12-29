#include <iostream>
#include <cstdio>
using namespace std;
int a, b, s;
int main()
{
	cin >> a >> b >> s;
	int a1 = a * (-1);
	int b1 = b * (-1);
	if (max(a, a1) + max(b, b1) == s || (max(a, a1) + max(b, b1)) % 2 == s % 2 && max(a, a1) + max(b, b1) <= s)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}
