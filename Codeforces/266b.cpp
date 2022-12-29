#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	int t, n;
	cin >> n >> t >> s;
	while (t--)
	{
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'B' && s[i + 1] == 'G')
			{
				swap(s[i], s[i + 1]);
				i++;
			}
		}
	}
	cout << s;
}
