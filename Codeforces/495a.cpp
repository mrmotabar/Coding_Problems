#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int a[10];
	a[0] = 2;
	a[1] = 7;
	a[2] = 2;
	a[3] = 3;
	a[4] = 3;
	a[5] = 4;
	a[6] = 2;
	a[7] = 5;
	a[8] = 1;
	a[9] = 2;
	cout << a[int(s[0]) - int('0')] * a[int(s[1]) - int('0')];
}
