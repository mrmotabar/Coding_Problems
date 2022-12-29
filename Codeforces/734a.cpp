#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, a = 0, d = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A')
		{
			a++;
		}
		else
		{
			d++;
		}
	}
	if (d > a)
	{
		cout << "Danik";
	}
	else if (a > d)
	{
		cout << "Anton";
	}
	else
	{
		cout << "Friendship";
	}
}
