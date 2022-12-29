/*mohammadreza motabar*/
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define pb push_back
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
const int MAX_N = 1e5 + 10, INF = 1e8;
vector<pii> s;
bool mark[MAX_N];
int barabar(int a, int b)
{
	int ret = 0, temp = 0;
	int aa = a, bb = b;
	while (temp < 4)
	{
		if (aa % 10 == bb % 10)
		{
			ret++;
		}
		aa /= 10;
		bb /= 10;
		temp++;
	}
	return ret;
}
int jay(int a, int b)
{
	int ta[10], tb[10], aa = a, bb = b, ret = 0, temp = 0;
	memset(ta, 0, sizeof ta);
	memset(tb, 0, sizeof tb);
	while (temp < 4)
	{
		if (aa % 10 != bb % 10)
		{
			ta[aa % 10]++;
			tb[bb % 10]++;
		}
		aa /= 10;
		bb /= 10;
		temp++;
	}
	for (int i = 0; i <= 9; i++)
	{
		ret += min(ta[i], tb[i]);
	}
	return ret;
}
int arzesh(int v)
{
	int ret = 0, x, y;
	int vc[5][5];
	memset(vc, 0, sizeof vc);
	for (int i = 0; i < s.size(); i++)
	{
		if (!mark[i])
		{
			x = barabar(s[i].second, v);
			y = jay(s[i].second, v);
			vc[x][y]++;
			ret = max(ret, vc[x][y]);
		}
	}
	return ret;
}
int upd()
{
	int ret = s.size() - 1;
	int t = 300;
	while (t--)
	{
		int r = rand() % s.size();
		if (!mark[r])
		{
			s[r].first = arzesh(s[r].second);
			if (s[r].first < s[ret].first)
			{
				ret = r;
			}
		}
		else
		{
			t++;
		}
	}
	/*int t=0;
	for(int i=0;i<s.size() && t<7;i++){
		if(!mark[i]){
			s[i].first=arzesh(s[i].second);
			if(s[i].first<s[ret].first){
				ret=i;
			}
			t++;
		}
	}*/
	return ret;
}
void print(int v)
{
	if (v < 10)
	{
		cout << 0 << 0 << 0 << v << endl;
	}
	else if (v < 100)
	{
		cout << 0 << 0 << v << endl;
	}
	else if (v < 1000)
	{
		cout << 0 << v << endl;
	}
	else
	{
		cout << v << endl;
	}
}
void hazf(int v, int x, int y)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (!mark[i])
		{
			if (barabar(v, s[i].second) != x || jay(v, s[i].second) != y)
			{
				mark[i] = 1;
			}
		}
	}
}
bool mot(int v)
{
	int t[10 + 1], temp = 0;
	memset(t, 0, sizeof t);
	while (temp < 4)
	{
		t[v % 10]++;
		v /= 10;
		temp++;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (t[i] > 1)
			return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	for (int i = 0; i <= 9999; i++)
	{
		if (mot(i))
		{
			s.pb({0, i});
		}
	}
	s.pb({INF, 10000});
	while (1)
	{
		int x, y;
		int ind = upd();
		print(s[ind].second);
		cin >> x >> y;
		if (x == 4)
			break;
		hazf(s[ind].second, x, y);
	}
}
