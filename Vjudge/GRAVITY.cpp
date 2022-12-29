#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 110;
vector<int> adj[max_n];
int d[max_n][max_n];
string s[max_n];
pair<int, int> q[max_n * max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 0;
	int n, m, o;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> o >> n >> m;
		int sx, sy, ex, ey;
		getline(cin, s[0]);
		for (int j = 0; j < n; j++)
		{
			getline(cin, s[j]);
		}
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < m; y++)
			{
				if (s[x][y] == 'S')
				{
					s[x][y] = ' ';
					sx = x;
					sy = y;
				}
				if (s[x][y] == 'T')
				{
					s[x][y] = ' ';
					ex = x;
					ey = y;
				}
			}
		}
		for (int k = 0; k < max_n * max_n; k++)
		{
			q[k].first = 0;
			q[k].second = 0;
		}
		for (int u = 0; u < max_n; u++)
		{
			for (int f = 0; f < max_n; f++)
			{
				d[u][f] = 999999;
			}
		}
		int h = 0, t = 0;
		d[sx][sy] = 0;
		q[t].first = sx;
		q[t++].second = sy;
		while (h < t)
		{
			int vx = q[h].first;
			int vy = q[h++].second;
			if (s[vx][vy] == ' ')
			{
				if (s[vx + 1][vy] == ' ' && vx + 1 < n)
				{
					if (d[vx][vy] + 1 < d[vx + 1][vy])
					{
						d[vx + 1][vy] = d[vx][vy] + 1;
						q[t].first = vx + 1;
						q[t++].second = vy;
					}
				}
				if (s[vx + 1][vy + 1] == ' ' && vx + 1 < n && vy + 1 < m)
				{
					if (d[vx][vy] + 1 < d[vx + 1][vy + 1])
					{
						d[vx + 1][vy + 1] = d[vx][vy] + 1;
						q[t].first = vx + 1;
						q[t++].second = vy + 1;
					}
				}
				if (vy - 1 >= 0)
					if (s[vx + 1][vy - 1] == ' ' && vx + 1 < n && vy > 0)
					{
						if (d[vx][vy] + 1 < d[vx + 1][vy - 1])
						{
							d[vx + 1][vy - 1] = d[vx][vy] + 1;
							q[t].first = vx + 1;
							q[t++].second = vy - 1;
						}
					}
				if (vx - 1 >= 0)
					if (s[vx - 1][vy] == ' ' && vx > 0)
					{
						if (d[vx][vy] + 1 < d[vx - 1][vy])
						{
							d[vx - 1][vy] = d[vx][vy] + 1;
							q[t].first = vx - 1;
							q[t++].second = vy;
						}
					}
				if (vx - 1 >= 0)
					if (s[vx - 1][vy + 1] == ' ' && vx > 0 && vy + 1 < m)
					{
						if (d[vx][vy] + 1 < d[vx - 1][vy + 1])
						{
							d[vx - 1][vy + 1] = d[vx][vy] + 1;
							q[t].first = vx - 1;
							q[t++].second = vy + 1;
						}
					}
				if (vx - 1 >= 0 && vy - 1 >= 0)
					if (s[vx - 1][vy - 1] == ' ' && vx > 0 && vy > 0)
					{
						if (d[vx][vy] + 1 < d[vx - 1][vy - 1])
						{
							d[vx - 1][vy - 1] = d[vx][vy] + 1;
							q[t].first = vx - 1;
							q[t++].second = vy - 1;
						}
					}
				if (vy - 1 >= 0)
					if (s[vx][vy - 1] == ' ' && vy > 0)
					{
						if (d[vx][vy] + 1 < d[vx][vy - 1])
						{
							d[vx][vy - 1] = d[vx][vy] + 1;
							q[t].first = vx;
							q[t++].second = vy - 1;
						}
					}
				if (s[vx][vy + 1] == ' ' && vy + 1 < m)
				{
					if (d[vx][vy] + 1 < d[vx][vy + 1])
					{
						d[vx][vy + 1] = d[vx][vy] + 1;
						q[t].first = vx;
						q[t++].second = vy + 1;
					}
				}
			}
		}
		//	cout<<sx<<"  "<<sy<<endl;
		//	cout<<ex<<"  "<<ey<<endl;
		//	cout<<endl;
		//	for(int f=0;f<n;f++){
		//		for(int l=0;l<m;l++){
		//			cout<<d[f][l]<<" ";
		//		}
		//		cout<<endl;
		//	}
		//	return 0;
		if (d[ex][ey] != 0 && d[ex][ey] <= o)
		{
			cout << "Possible" << endl;
		}
		else
		{
			cout << "Impossible" << endl;
		}
	}
}
