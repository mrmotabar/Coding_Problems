#include <iostream>
#include <cstdio>
using namespace std;
char c[1000000 + 10];
int main()
{
	int n;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
		if (c[i] != char(4 + int('0')) && c[i] != char(7 + int('0')))
		{
			cout << "NO";
			return 0;
		}
		if (i < n / 2)
		{
			sum1 += int(c[i]) - int('0');
		}
		if (i >= n / 2)
		{
			sum2 += int(c[i]) - int('0');
		}
	}
	// cout<<sum1<<"   "<<sum2<<endl;
	if (sum1 == sum2)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
}
