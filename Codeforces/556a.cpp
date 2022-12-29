#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int zero = 0, one = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			zero++;
		}
		else
		{
			one++;
		}
	}
	cout << s.size() - (2 * min(zero, one));
}
