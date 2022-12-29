#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int a[s.size()];
	for (int i = 0; i < s.size(); i++)
	{
		a[i] = int(s[i]) - int('0');
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (a[i] % 8 == 0)
		{
			cout << "YES" << endl
				 << a[i];
			return 0;
		}
	}
	int adad;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			adad = a[i] * 10 + a[j];
			if (adad % 8 == 0)
			{
				cout << "YES" << endl
					 << adad;
				return 0;
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i + 1; j < s.size(); j++)
		{
			for (int k = j + 1; k < s.size(); k++)
			{
				adad = a[i] * 100 + a[j] * 10 + a[k];
				if (adad % 8 == 0)
				{
					cout << "YES" << endl
						 << adad;
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
