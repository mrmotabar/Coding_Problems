#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char c[8][8];
	int up = 0, down = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> c[i][j];
			if (c[i][j] < 'a')
			{
				if (c[i][j] == 'Q')
				{
					up += 9;
				}
				else if (c[i][j] == 'R')
				{
					up += 5;
				}
				else if (c[i][j] == 'P')
				{
					up += 1;
				}
				else if (c[i][j] == 'N' || c[i][j] == 'B')
				{
					up += 3;
				}
			}
			if (c[i][j] >= 'a')
			{
				if (c[i][j] == 'q')
				{
					down += 9;
				}
				else if (c[i][j] == 'r')
				{
					down += 5;
				}
				else if (c[i][j] == 'p')
				{
					down += 1;
				}
				else if (c[i][j] == 'n' || c[i][j] == 'b')
				{
					down += 3;
				}
			}
		}
	}
	if (down > up)
	{
		cout << "Black";
	}
	if (up > down)
	{
		cout << "White";
	}
	if (up == down)
	{
		cout << "Draw";
	}
}
