#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	int a;
	cin >> s;
	cin >> a;
	int x1 = int(s[0]) - int('0');
	int x2 = int(s[1]) - int('0');
	int x3 = int(s[3]) - int('0');
	int x4 = int(s[4]) - int('0');
	int saat = 10 * x1 + x2;
	int daghighe = 10 * x3 + x4;
	saat += (daghighe + a) / 60;
	daghighe = (daghighe + a) % 60;
	int y = 0;
	if (saat % 24 == 0 || saat % 24 < 10)
	{
		y = 1;
	}
	// if(saat%24!=0 && daghighe==0){
	//	y=0;
	// }
	if (y == 1)
	{
		cout << '0';
	}
	if (daghighe < 10)
		cout << saat % 24 << ':' << '0' << daghighe;
	else
		cout << saat % 24 << ':' << daghighe;
}
