#include <iostream>
#include <cstdio>
using namespace std;
int a[26];
int main()
{
	int k, max = 0;
	string s;
	cin >> s >> k;
	for (int i = 0; i < 26; i++)
	{
		cin >> a[i];
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	int sum = 0;
	for (int i = 0; i < s.size(); i++)
	{
		sum += (i + 1) * (a[int(s[i]) - int('a')]);
	}
	int h = (s.size() + 1 + s.size() + k) * k / 2;
	sum += max * (h);
	cout << sum;
}
