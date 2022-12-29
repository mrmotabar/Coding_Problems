#include <iostream>
#include <cstdio>
using namespace std;
char c[40][40][40];
pair<int, pair<int, int>> q[1000000];
int d[40][40][40];
int main()
{
	int x, y, z;
	int x1, y1, z1;
	int x2, y2, z2;
	while (1)
	{
		cin >> x >> y >> z;
		if (x == 0 && y == 0 && z == 0)
		{
			break;
		}
		for (int i = 1; i <= x; i++)
		{
			for (int j = 1; j <= y; j++)
			{
				for (int k = 1; k <= z; k++)
				{
					d[i][j][k] = 9999999;
				}
			}
		}
		for (int i = 0; i < 10000; i++)
		{
			q[i] = {0, {0, 0}};
		}
		for (int i = 1; i <= 40; i++)
		{
			for (int j = 1; j <= 40; j++)
			{
				for (int k = 1; k <= 40; k++)
				{
					c[i][j][k] = 'a';
				}
			}
		}
		for (int i = 1; i <= x; i++)
		{
			for (int j = 1; j <= y; j++)
			{
				for (int k = 1; k <= z; k++)
				{
					cin >> c[i][j][k];
					if (c[i][j][k] == 'S')
					{
						c[i][j][k] = '.';
						x1 = i;
						y1 = j;
						z1 = k;
					}
					if (c[i][j][k] == 'E')
					{
						c[i][j][k] = '.';
						x2 = i;
						y2 = j;
						z2 = k;
					}
				}
			}
		}
		int h = 0, t = 0;
		d[x1][y1][z1] = 0;
		q[t++] = {x1, {y1, z1}};
		while (h < t)
		{
			int vx = q[h].first;
			int vy = q[h].second.first;
			int vz = q[h++].second.second;
			if (c[vx][vy][vz + 1] == '.')
			{
				if (d[vx][vy][vz] + 1 < d[vx][vy][vz + 1])
				{
					d[vx][vy][vz + 1] = d[vx][vy][vz] + 1;
					q[t++] = {vx, {vy, vz + 1}};
				}
			}
			if (c[vx][vy][vz - 1] == '.')
			{
				if (d[vx][vy][vz] + 1 < d[vx][vy][vz - 1])
				{
					d[vx][vy][vz - 1] = d[vx][vy][vz] + 1;
					q[t++] = {vx, {vy, vz - 1}};
				}
			}
			if (c[vx][vy + 1][vz] == '.')
			{
				if (d[vx][vy][vz] + 1 < d[vx][vy + 1][vz])
				{
					d[vx][vy + 1][vz] = d[vx][vy][vz] + 1;
					q[t++] = {vx, {vy + 1, vz}};
				}
			}
			if (c[vx][vy - 1][vz] == '.')
			{
				if (d[vx][vy][vz] + 1 < d[vx][vy - 1][vz])
				{
					d[vx][vy - 1][vz] = d[vx][vy][vz] + 1;
					q[t++] = {vx, {vy - 1, vz}};
				}
			}
			if (c[vx + 1][vy][vz] == '.')
			{
				if (d[vx][vy][vz] + 1 < d[vx + 1][vy][vz])
				{
					d[vx + 1][vy][vz] = d[vx][vy][vz] + 1;
					q[t++] = {vx + 1, {vy, vz}};
				}
			}
			if (c[vx - 1][vy][vz] == '.')
			{
				if (d[vx][vy][vz] + 1 < d[vx - 1][vy][vz])
				{
					d[vx - 1][vy][vz] = d[vx][vy][vz] + 1;
					q[t++] = {vx - 1, {vy, vz}};
				}
			}
		}
		if (d[x2][y2][z2] == 9999999)
		{
			cout << "Trapped!" << endl;
		}
		else
		{
			cout << "Escaped in " << d[x2][y2][z2] << " minute(s)." << endl;
		}
	}
}
