#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int max_n = 100010;
const int bina = 1000000;
vector<int> adj[max_n];
int d[max_n];
int q[max_n];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < max_n; i++)
    {
        d[i] = bina;
        if (2 * i < max_n)
        {
            adj[i].push_back(2 * i);
        }
        if (i - 1 > 0)
        {
            adj[i].push_back(i - 1);
        }
    }
    int h = 0, t = 0;
    d[n] = 0;
    q[t++] = n;
    while (h < t)
    {
        int v = q[h++];
        for (int u : adj[v])
            if (d[v] + 1 < d[u])
            {
                d[u] = d[v] + 1;
                q[t++] = u;
            }
    }
    cout << d[m];
}
