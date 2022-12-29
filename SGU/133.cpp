#include <iostream>
#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;
pair<long long int, long long int> p[16000];
void insertion(int s, int e)
{
	for (int i = s; i <= e; i++)
	{
		int x = p[i].first;
		int y = p[i].second;
		int j = i - 1;
		while ((p[j].first > x) && (j >= 0))
		{
			p[j + 1].first = p[j].first;
			p[j + 1].second = p[j].second;
			j--;
		}
		p[j + 1].first = x;
		p[j + 1].second = y;
	}
}
int partition(int s, int e)
{
	srand(time(0));
	int m = (rand() % (e - s)) + s;
	swap(p[m].first, p[e].first);
	swap(p[m].second, p[e].second);
	int i = s;
	int j = e - 1;
	while (i < j)
	{
		if (p[i].first <= p[e].first)
		{
			i++;
		}
		else if (p[j].first >= p[e].first)
		{
			j--;
		}
		else
		{
			swap(p[i].first, p[j].first);
			swap(p[i].second, p[j].second);
		}
	}
	if (p[i].first < p[e].first)
	{
		swap(p[i + 1].first, p[e].first);
		swap(p[i + 1].second, p[e].second);
		return i + 1;
	}
	else
	{
		swap(p[i].first, p[e].first);
		swap(p[i].second, p[e].second);
		return i;
	}
}
void q_sort(int s, int e)
{
	int m;
	if (s < e && e - s > 30)
	{
		m = partition(s, e);
		q_sort(s, m - 1);
		q_sort(m + 1, e);
	}
	else if (s < e && e - s <= 30)
	{
		insertion(s, e);
	}
}
int mogh(pair<long long int, long long int> a, pair<long long int, long long int> b)
{
	if (a.second != b.second)
	{
		return a.second > b.second;
	}
	else
	{
		return a.first > b.first;
	}
}
int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	q_sort(0, n - 1);
	int x = p[0].second;
	for (int i = 1; i < n; i++)
	{
		if (p[i].second < x)
			ans++;
		else
			x = p[i].second;
	}
	cout << ans;
}
