#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if ((int(s[i]) - int('0')) % 4 == 0)
		{
			ans++;
		}
		if (i > 0)
		{
			int z = (int(s[i - 1]) - int('0')) * 10 + int(s[i]) - int('0');
			if (z % 4 == 0)
			{
				ans += i;
			}
		}
	}
	cout << ans;
}
