#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string a[30];
	a[1] = "0";
	a[2] = "1";
	a[3] = "2";
	a[4] = "3";
	a[5] = "4";
	a[6] = "5";
	a[7] = "6";
	a[8] = "7";
	a[9] = "8";
	a[10] = "9";
	a[11] = "10";
	a[12] = "11";
	a[13] = "12";
	a[14] = "13";
	a[15] = "14";
	a[16] = "15";
	a[17] = "16";
	a[18] = "17";
	a[19] = "ABSINTH";
	a[20] = "BEER";
	a[21] = "BRANDY";
	a[22] = "CHAMPAGNE";
	a[23] = "GIN";
	a[24] = "RUM";
	a[25] = "SAKE";
	a[26] = "TEQUILA";
	a[27] = "VODKA";
	a[28] = "WHISKEY";
	a[29] = "WINE";
	int n;
	string x;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		for (int j = 1; j < 30; j++)
		{
			if (x == a[j])
			{
				ans++;
			}
		}
	}
	cout << ans;
}
