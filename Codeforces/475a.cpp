#include <iostream>
#include <cstdio>
using namespace std;
int a[11], b[11], c[11], d[11];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; n > 0; i++)
	{
		a[i]++;
		n--;
		if (n == 0)
		{
			break;
		}
		b[i]++;
		n--;
		if (n == 0)
		{
			break;
		}
		if (i == 0)
		{
			c[i]++;
			n--;
			if (n == 0)
			{
				break;
			}
		}
		d[i]++;
		n--;
	}
	cout << "+------------------------+" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			cout << '|';
			for (int i = 0; i < 11; i++)
			{
				if (a[i] == 1)
				{
					cout << "O.";
				}
				else
				{
					cout << "#.";
				}
			}
			cout << "|D|)" << endl;
		}
		if (i == 1)
		{
			cout << '|';
			for (int i = 0; i < 11; i++)
			{
				if (b[i] == 1)
				{
					cout << "O.";
				}
				else
				{
					cout << "#.";
				}
			}
			cout << "|.|" << endl;
		}
		if (i == 2)
		{
			cout << '|';
			for (int i = 0; i < 11; i++)
			{
				if (c[i] == 1)
				{
					cout << "O.";
				}
				else if (c[0] == 0)
				{
					cout << "#.";
					c[0]++;
				}
				else
				{
					cout << "..";
				}
			}
			cout << "..|" << endl;
		}
		if (i == 3)
		{
			cout << '|';
			for (int i = 0; i < 11; i++)
			{
				if (d[i] == 1)
				{
					cout << "O.";
				}
				else
				{
					cout << "#.";
				}
			}
			cout << "|.|)" << endl;
		}
	}
	cout << "+------------------------+";
}
