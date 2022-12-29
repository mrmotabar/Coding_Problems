#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
char a[1000];
int b[1000];
long long max_zarb = 0;
int main()
{
	ifstream inf("8.txt");
	for (int i = 0; i < 1000; i++)
	{
		inf >> a[i];
		b[i] = int(a[i]) - int('0');
	}
	for (int i = 0; i + 12 < 1000; i++)
	{
		long long zarb = 1;
		for (int j = 0; j < 13; j++)
		{
			zarb *= b[i + j];
		}
		if (zarb > max_zarb)
		{
			max_zarb = zarb;
		}
	}
	cout << max_zarb;
}
