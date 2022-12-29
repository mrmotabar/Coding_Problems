#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int b[100000];
int main()
{
	int n;
	cin >> n;
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	//	for(int i=0;i<=max;i++){
	//		cout<<b[i]<<"  ";
	//	}
	for (int i = 1; i <= n; i++)
	{
		int rot = 0;
		for (int j = max; j != a[i]; j--)
		{
			rot += b[j];
		}
		cout << rot + 1 << " ";
	}
}
