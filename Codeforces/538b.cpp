#include <iostream>
#include <cstdio>
using namespace std;
int r[100000 + 10];
int main()
{
	int n;
	cin >> n;
	int max = 0;
	int l = 0;
	while (n > 0)
	{
		r[l] = n % 10;
		n /= 10;
		l++;
		if (r[l - 1] > max)
		{
			max = r[l - 1];
		}
	}
	cout << max << endl;
	for (int i = 0; i < max; i++)
	{
		bool m = 0;
		for (int j = l; j >= 0; j--)
		{
			if (r[j] == 0 && m == 1)
			{
				cout << "0";
			}
			else if (r[j] != 0)
			{
				cout << "1";
				r[j]--;
				m = 1;
			}
		}
		cout << " ";
	}
}
