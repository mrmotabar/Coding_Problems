#include <iostream>
#include <cstdio>
using namespace std;
const int MAX_N = 10000 + 20;
int n, p, c, t;
int a[MAX_N];
int b[MAX_N];

int f(int h)
{
	int i = 0, time = 0, nafar = 0, sum = 0;
	for (i = 0; i < n && sum < h; i++)
	{
		b[i] = a[i];
		sum += a[i];
	}

	i--;

	if (sum > h)
		b[i] -= sum - h;

	int j = i;

	time += ((j + 1) * p);

	while (j >= 0)
	{
		time += 2 * ((b[j] / c) * p) * (j);
		cout << b[j] << "    " << c << "   hhhh" << endl;
		b[j] = (b[j] % c);
		nafar += b[j];
		if (nafar >= c)
		{
			nafar = nafar % c;
			time += 2 * p * (j + 1);
		}
		if (b[j] == 0 && j >= 0)
		{
			time -= p;
		}
		j--;
		time += p;
	}
	if (nafar > 0)
	{
		time += p;
	}
	cout << h << "   " << time << endl;
	return time;
}
int main()
{
	cin >> n >> c >> p >> t;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	// cout<<f(5);
	// return 0;

	int s = 0, e = sum + 1;

	while (e - s > 1)
	{
		int mid = (s + e) / 2;
		if (f(mid) <= t)
			s = mid;
		else
			e = mid;
	}

	cout << s;
}
