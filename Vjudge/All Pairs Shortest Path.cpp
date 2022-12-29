#include <iostream>
#include <cstdio>
using namespace std;
const long long int INF = 1e12;
int e, v, r;
long long int to[100000], from[100000], w[1000000], d[1000][1000];
bool relax(int e)
{
	if (d[r][to[e]] > d[r][from[e]] + w[e] && d[r][from[e]] != INF)
	{
		d[r][to[e]] = d[r][from[e]] + w[e];
		return 1;
	}
	return 0;
}
int main()
{
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> to[i] >> from[i] >> w[i];
	}
	for (int i = 0; i < v + 10; i++)
	{
		fill(d[i], d[i] + v + 10, INF);
	}
	for (r = 0; r < v; r++)
	{
		d[r][r] = 0;
		for (int i = 0; i < v; i++)
		{
			for (int j = 0; j < e; j++)
			{
				bool o = relax(j);
				if (i == v - 1 && o == true)
				{
					cout << "NEGATIVE CYCLE" << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			if (d[j][i] != INF)
			{
				cout << d[j][i];
			}
			else
			{
				cout << "INF";
			}
			if (j != v - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
