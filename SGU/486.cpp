#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int b = 0, k = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (s1[i] == s2[i])
			{
				b++;
				s2[i] = 'a';
			}
			else if (s1[i] == s2[j])
			{
				k++;
			}
		}
	}
	cout << b << endl
		 << k;
}
