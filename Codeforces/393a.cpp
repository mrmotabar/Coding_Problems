#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	int n = 0, i = 0, e = 0, t = 0;
	cin >> s;
	for (int j = 0; j < s.size(); j++)
	{
		if (s[j] == 'i')
		{
			i++;
		}
		if (s[j] == 'n')
		{
			n++;
		}
		if (s[j] == 'e')
		{
			e++;
		}
		if (s[j] == 't')
		{
			t++;
		}
	}
	n = (n - 1) / 2;
	cout << min(i, min(n, min(e / 3, t)));
}
