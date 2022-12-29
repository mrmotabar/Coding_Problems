#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s[13] = {" ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string n;
	int k;
	cin >> n >> k;
	int p = 0;
	for (int i = 1; i < 13; i++)
	{
		if (s[i] == n)
		{
			p = i;
			break;
		}
	}
	p = (p + k) % 12;
	if (p == 0)
	{
		p = 12;
	}
	cout << s[p];
}
